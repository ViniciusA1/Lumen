#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

std::unordered_map<std::type_index, std::vector<EventBus::CallbackFunction>>
    EventBus::m_Subscribers;

std::queue<std::pair<std::type_index, std::any>> EventBus::m_EventQueue;

std::mutex EventBus::m_SubscriberMutex;
std::mutex EventBus::m_QueueMutex;

void EventBus::ProcessEvents()
{
    std::queue<std::pair<std::type_index, std::any>> localQueue;
    {
        std::lock_guard<std::mutex> lock(m_QueueMutex);
        std::swap(localQueue, m_EventQueue);
    }

    while (!localQueue.empty())
    {
        auto [type, event] = std::move(localQueue.front());
        localQueue.pop();

        std::vector<CallbackFunction> subscribersCopy;
        {
            std::lock_guard<std::mutex> lock(m_SubscriberMutex);
            auto it = m_Subscribers.find(type);
            if (it != m_Subscribers.end())
                subscribersCopy = it->second;
        }

        for (auto &subscriber : subscribersCopy)
            subscriber(event);
    }
}

} // namespace Lumen