#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

std::unordered_map<std::type_index, std::vector<EventCallbackFunction>>
    EventBus::m_Subscribers;

std::queue<std::pair<std::type_index, std::any>> EventBus::m_EventQueue;

void EventBus::ProcessEvents()
{
    while (!m_EventQueue.empty())
    {
        auto &[type, event] = m_EventQueue.front();
        auto it = m_Subscribers.find(type);
        if (it != m_Subscribers.end())
        {
            for (auto &subscriber : it->second)
            {
                subscriber(event);
            }
        }
        m_EventQueue.pop(); // Remove the processed event
    }
}

} // namespace Lumen