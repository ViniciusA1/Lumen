#pragma once

#include "Lumen/Event/FileEvent.hpp"
#include "Lumen/System/Function.hpp"

#include <atomic>
#include <mutex>
#include <thread>
#include <unordered_set>

namespace Lumen
{

enum class FileWatcherMode
{
    Sync,
    Async
};

class FileWatcher
{
public:
    using Callback = Function<void(const FileEvent &event)>;

public:
    FileWatcher(FileWatcherMode mode = FileWatcherMode::Async, int intervalMs = 500);
    ~FileWatcher();

    [[nodiscard]] int GetInterval() const;
    [[nodiscard]] FileWatcherMode GetMode() const;

    void UnwatchDirectory(const Path &dir);
    void UnwatchFile(const Path &path);
    void WatchDirectory(const Path &dir, const Callback &callback, bool recursive = true);
    void WatchFile(const Path &path, const Callback &callback);

    void Update();

    void Stop();

private:
    struct FileInfo
    {
        std::filesystem::file_time_type LastWriteTime;
        Callback Callback;
        bool Exists = true;
    };

private:
    void ThreadLoop();

    void CheckDirectories();
    void CheckFiles();

private:
    std::unordered_map<Path, FileInfo> m_Files;
    std::unordered_map<Path, std::unordered_set<Path>> m_DirectoryMap;
    std::unordered_map<Path, Callback> m_DirectoryCallbacks;

    FileWatcherMode m_Mode;
    int m_Interval;
    std::thread m_Thread;
    std::atomic<bool> m_Running{false};
    std::mutex m_Mutex;
};

} // namespace Lumen