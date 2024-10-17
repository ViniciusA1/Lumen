#pragma once

#include "Lumen/Event/Event.hpp"
#include <vector>

namespace Lumen
{

class EventQueue
{
public:
    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] size_t Size() const;

    void Push(const Event &event);
    template <typename... Args> void Emplace(Args &&...args)
    {
        m_Queue.emplace_back(std::forward<Args>(args)...);
    }

    Event Pop();
    void Clear();

    std::vector<Event>::iterator begin() { return m_Queue.begin(); }
    std::vector<Event>::iterator end() { return m_Queue.end(); }

    [[nodiscard]] std::vector<Event>::const_iterator begin() const
    {
        return m_Queue.begin();
    }
    [[nodiscard]] std::vector<Event>::const_iterator end() const { return m_Queue.end(); }

private:
    std::vector<Event> m_Queue;
};

} // namespace Lumen