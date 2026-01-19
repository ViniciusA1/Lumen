#pragma once

#include "Lumen/Concurrent/ThreadPool.hpp"

namespace Lumen
{

template <class F, class... Args>
auto ThreadPool::Enqueue(F &&f,
                         Args &&...args) -> std::future<std::invoke_result_t<F, Args...>>
{
    using return_t = std::invoke_result_t<F, Args...>;

    auto task = std::make_shared<std::packaged_task<return_t()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    {
        std::scoped_lock lock(m_QueueMutex);
        if (m_Stop)
            throw std::runtime_error("ThreadPool stopped");
        m_Tasks.emplace([task]() { (*task)(); });
    }

    m_Condition.notify_one();
    return task->get_future();
}

template <class F, class... Args> void ThreadPool::Execute(F &&f, Args &&...args)
{
    {
        std::scoped_lock lock(m_QueueMutex);
        if (m_Stop)
            throw std::runtime_error("ThreadPool stopped");

        m_Tasks.emplace(
            [fn = std::bind(std::forward<F>(f), std::forward<Args>(args)...)] { fn(); });
    }

    m_Condition.notify_one();
}

} // namespace Lumen