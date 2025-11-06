#pragma once

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

namespace Lumen
{

template <typename T> class ConcurrentQueue
{
public:
    ConcurrentQueue() = default;
    ConcurrentQueue(const ConcurrentQueue &) = delete;
    ConcurrentQueue &operator=(const ConcurrentQueue &) = delete;

    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] size_t GetSize() const;

    [[nodiscard]] std::optional<T> Front() const;
    [[nodiscard]] std::optional<T> Back() const;

    template <typename... Args> void Emplace(Args &&...args);
    void Push(const T &value);
    void Push(T &&value);

    void Pop();

    void Clear();

private:
    mutable std::mutex m_Mutex;
    std::condition_variable m_Cond;
    std::queue<T> m_Queue;
};

} // namespace Lumen