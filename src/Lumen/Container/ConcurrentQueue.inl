#include "Lumen/Container/ConcurrentQueue.hpp"

namespace Lumen
{

template <typename T> bool ConcurrentQueue<T>::IsEmpty() const
{
    std::scoped_lock lock(m_Mutex);
    return m_Queue.empty();
}

template <typename T> size_t ConcurrentQueue<T>::GetSize() const
{
    std::scoped_lock lock(m_Mutex);
    return m_Queue.size();
}

template <typename T> std::optional<T> ConcurrentQueue<T>::Front() const
{
    std::scoped_lock lock(m_Mutex);

    if (m_Queue.empty())
        return std::nullopt;

    return m_Queue.front();
}

template <typename T> std::optional<T> ConcurrentQueue<T>::Back() const
{
    std::scoped_lock lock(m_Mutex);

    if (m_Queue.empty())
        return std::nullopt;

    return m_Queue.back();
}

template <typename T>
template <typename... Args>
void ConcurrentQueue<T>::Emplace(Args &&...args)
{
    {
        std::scoped_lock lock(m_Mutex);
        m_Queue.emplace(std::forward<Args>(args)...);
    }
    m_Cond.notify_one();
}

template <typename T> void ConcurrentQueue<T>::Push(const T &value)
{
    {
        std::scoped_lock lock(m_Mutex);
        m_Queue.push(value);
    }
    m_Cond.notify_one();
}

template <typename T> void ConcurrentQueue<T>::Push(T &&value)
{
    {
        std::scoped_lock lock(m_Mutex);
        m_Queue.push(std::move(value));
    }
    m_Cond.notify_one();
}

template <typename T> void ConcurrentQueue<T>::Pop()
{
    std::scoped_lock lock(m_Mutex);
    if (!m_Queue.empty())
        m_Queue.pop();
}

template <typename T> void ConcurrentQueue<T>::Clear()
{
    std::scoped_lock lock(m_Mutex);
    std::queue<T> empty;
    std::swap(m_Queue, empty);
}

} // namespace Lumen