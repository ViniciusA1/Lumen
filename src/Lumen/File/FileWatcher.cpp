#include "Lumen/File/FileWatcher.hpp"

namespace Lumen
{

FileWatcher::FileWatcher(FileWatcherMode mode, unsigned intervalMs)
    : m_Mode(mode), m_Interval(intervalMs)
{
    if (mode == FileWatcherMode::Async)
    {
        m_Running = true;
        m_Thread = std::thread(&FileWatcher::ThreadLoop, this);
    }
}

FileWatcher::~FileWatcher()
{
    Stop();
}

int FileWatcher::GetInterval() const
{
    return m_Interval;
}

FileWatcherMode FileWatcher::GetMode() const
{
    return m_Mode;
}

void FileWatcher::UnwatchDirectory(const Path &dir)
{
    std::scoped_lock lock(m_Mutex);

    m_DirectoryCallbacks.erase(dir);

    if (m_DirectoryMap.find(dir) != m_DirectoryMap.end())
    {
        for (auto &file : m_DirectoryMap[dir])
            m_Files.erase(file);

        m_DirectoryMap.erase(dir);
    }
}

void FileWatcher::UnwatchFile(const Path &path)
{
    std::scoped_lock lock(m_Mutex);
    m_Files.erase(path);

    for (auto &[dir, files] : m_DirectoryMap)
        files.erase(path);
}

void FileWatcher::WatchDirectory(const WatchDirectorySpec &spec)
{
    std::scoped_lock lock(m_Mutex);

    if (spec.Recursive == false)
    {
        for (auto &entry : std::filesystem::directory_iterator(spec.Path))
        {
            if (entry.is_regular_file())
            {
                WatchFile({entry.path(), spec.Callback});
                m_DirectoryMap[spec.Path].insert(entry.path());
                if (spec.RunCallbackOnStartup)
                    spec.Callback(FileEvent{FileEventType::Created, entry.path()});
            }
        }
    }
    else
    {
        for (auto &entry : std::filesystem::recursive_directory_iterator(spec.Path))
        {
            if (entry.is_regular_file())
            {
                WatchFile({entry.path(), spec.Callback});
                m_DirectoryMap[spec.Path].insert(entry.path());
                if (spec.RunCallbackOnStartup)
                    spec.Callback(FileEvent{FileEventType::Created, entry.path()});
            }
        }
    }

    m_DirectoryCallbacks[spec.Path] = spec.Callback;
}

void FileWatcher::WatchFile(const WatchFileSpec &spec)
{
    std::scoped_lock lock(m_Mutex);

    std::filesystem::file_time_type writeTime;
    bool exists = std::filesystem::exists(spec.Path);
    if (exists)
        writeTime = std::filesystem::last_write_time(spec.Path);

    m_Files[spec.Path] = {writeTime, spec.Callback, exists};
}

void FileWatcher::Update()
{
    std::scoped_lock lock(m_Mutex);
    CheckFiles();
    CheckDirectories();
}

void FileWatcher::Stop()
{
    if (m_Mode == FileWatcherMode::Async)
    {
        m_Running = false;
        if (m_Thread.joinable())
            m_Thread.join();
    }
}

void FileWatcher::ThreadLoop()
{
    while (m_Running)
    {
        {
            std::scoped_lock lock(m_Mutex);
            CheckFiles();
            CheckDirectories();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(m_Interval));
    }
}

void FileWatcher::CheckDirectories()
{
    for (auto &[dir, callback] : m_DirectoryCallbacks)
    {
        std::unordered_set<Path> currentFiles;
        for (auto &entry : std::filesystem::recursive_directory_iterator(dir))
        {
            if (!entry.is_regular_file())
                continue;

            Path filePath = entry.path();
            currentFiles.insert(filePath);

            if (m_DirectoryMap[dir].find(filePath) == m_DirectoryMap[dir].end())
            {
                WatchFile({filePath, callback});
                callback({FileEventType::Created, filePath});
            }
        }

        for (auto it = m_DirectoryMap[dir].begin(); it != m_DirectoryMap[dir].end();)
        {
            if (currentFiles.find(*it) == currentFiles.end())
            {
                auto fileIt = m_Files.find(*it);
                if (fileIt != m_Files.end())
                {
                    if (fileIt->second.Exists)
                        fileIt->second.Callback({FileEventType::Deleted, *it});

                    m_Files.erase(fileIt);
                }
                it = m_DirectoryMap[dir].erase(it);
            }
            else
            {
                ++it;
            }
        }

        m_DirectoryMap[dir] = std::move(currentFiles);
    }
}

void FileWatcher::CheckFiles()
{
    for (auto &[path, info] : m_Files)
    {
        std::error_code error;
        bool exists = std::filesystem::exists(path, error);
        if (error)
            continue;

        if (!info.Exists && exists)
        {
            info.Exists = true;
            info.LastWriteTime = std::filesystem::last_write_time(path);
            info.Callback({FileEventType::Created, path});
        }
        else if (info.Exists && !exists)
        {
            info.Exists = false;
            info.Callback({FileEventType::Deleted, path});
        }
        else if (exists)
        {
            auto newTime = std::filesystem::last_write_time(path);
            if (newTime != info.LastWriteTime)
            {
                info.LastWriteTime = newTime;
                info.Callback({FileEventType::Modified, path});
            }
        }
    }
}

} // namespace Lumen