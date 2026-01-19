#include "Lumen/Concurrent/ThreadPool.hpp"

namespace Lumen
{

ThreadPool::ThreadPool(std::size_t threadCount) : m_Stop(false)
{
    if (threadCount == 0)
        threadCount = 1;

    m_Workers.reserve(threadCount);
    for (size_t i = 0; i < threadCount; ++i)
    {
        m_Workers.emplace_back(
            [this](const std::stop_token &stoken) { WorkerLoop(stoken); });
    }
}

ThreadPool::~ThreadPool()
{
    Stop();
}

size_t ThreadPool::GetSize() const
{
    return m_Workers.size();
}

void ThreadPool::WaitAll()
{
    std::unique_lock lock(m_QueueMutex);
    m_Empty.wait(lock, [this] { return m_Tasks.empty(); });
}

void ThreadPool::Stop()
{
    {
        std::scoped_lock lock(m_QueueMutex);
        m_Stop = true;
    }

    m_Condition.notify_all();

    for (auto &worker : m_Workers)
    {
        if (worker.joinable())
            worker.request_stop();
    }

    m_Workers.clear();
}

void ThreadPool::WorkerLoop(const std::stop_token &stoken)
{
    while (!stoken.stop_requested())
    {
        std::function<void()> task;

        {
            std::unique_lock lock(m_QueueMutex);
            m_Condition.wait(lock, [this, &stoken] {
                return m_Stop || !m_Tasks.empty() || stoken.stop_requested();
            });

            if ((m_Stop && m_Tasks.empty()) || stoken.stop_requested())
                return;

            task = std::move(m_Tasks.front());
            m_Tasks.pop();

            if (m_Tasks.empty())
                m_Empty.notify_all();
        }

        task();
    }
}

} // namespace Lumen