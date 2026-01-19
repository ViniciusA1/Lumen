#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <stop_token>
#include <thread>
#include <vector>

namespace Lumen
{

class ThreadPool
{
public:
    ThreadPool(std::size_t threadCount = std::thread::hardware_concurrency());
    ~ThreadPool();

    [[nodiscard]] std::size_t GetSize() const;

    template <class F, class... Args>
    auto Enqueue(F &&f, Args &&...args) -> std::future<std::invoke_result_t<F, Args...>>;

    template <class F, class... Args> void Execute(F &&f, Args &&...args);

    void WaitAll();

    void Stop();

private:
    void WorkerLoop(const std::stop_token &stoken);

private:
    std::vector<std::jthread> m_Workers;
    std::queue<std::function<void()>> m_Tasks;

    mutable std::mutex m_QueueMutex;
    std::condition_variable m_Condition;
    std::condition_variable m_Empty;

    bool m_Stop;
};

} // namespace Lumen

#include "Lumen/Concurrent/ThreadPool.inl"