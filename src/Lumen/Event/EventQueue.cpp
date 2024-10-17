#include "Lumen/Event/EventQueue.hpp"

namespace Lumen
{

void EventQueue::Push(const Event &event)
{
    m_Queue.push_back(event);
}

Event EventQueue::Pop()
{
    Event event = m_Queue.front();
    m_Queue.erase(m_Queue.begin());
    return event;
}

void EventQueue::Clear()
{
    m_Queue.clear();
}

bool EventQueue::IsEmpty() const
{
    return m_Queue.empty();
}

size_t EventQueue::Size() const
{
    return m_Queue.size();
}

} // namespace Lumen