#pragma once

#include "Lumen/Event/FileEvent.hpp"
#include "Lumen/System/Function.hpp"

#include <atomic>
#include <mutex>
#include <thread>
#include <unordered_set>

namespace Lumen
{

using FileWatcherCallback = Function<void(const FileEvent &event)>;

enum class FileWatcherMode
{
    Sync,
    Async
};

struct WatchDirectorySpec
{
    Lumen::Path Path;
    FileWatcherCallback Callback;
    bool Recursive = false;
    bool RunCallbackOnStartup = false;
};

struct WatchFileSpec
{
    Lumen::Path Path;
    FileWatcherCallback Callback;
};

class FileWatcher
{
public:
    FileWatcher(FileWatcherMode mode = FileWatcherMode::Async, unsigned intervalMs = 500);
    ~FileWatcher();

    [[nodiscard]] int GetInterval() const;
    [[nodiscard]] FileWatcherMode GetMode() const;

    void WatchDirectory(const WatchDirectorySpec &spec);
    void WatchFile(const WatchFileSpec &spec);

    void UnwatchDirectory(const Path &dir);
    void UnwatchFile(const Path &path);

    void Update();

    void Stop();

private:
    struct FileInfo
    {
        std::filesystem::file_time_type LastWriteTime;
        FileWatcherCallback Callback;
        bool Exists = true;
    };

private:
    void ThreadLoop();

    void CheckDirectories();
    void CheckFiles();

private:
    std::unordered_map<Path, FileInfo> m_Files;
    std::unordered_map<Path, std::unordered_set<Path>> m_DirectoryMap;
    std::unordered_map<Path, FileWatcherCallback> m_DirectoryCallbacks;

    FileWatcherMode m_Mode;
    unsigned m_Interval;
    std::thread m_Thread;
    std::atomic<bool> m_Running{false};
    std::mutex m_Mutex;
};

} // namespace Lumen