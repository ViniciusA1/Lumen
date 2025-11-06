#pragma once

#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

template <typename EventType>
void EventBus::Subscribe(std::function<void(const EventType &)> callback)
{
    std::lock_guard<std::mutex> lock(m_SubscriberMutex);
    auto &subscribers = m_Subscribers[typeid(EventType)];
    subscribers.emplace_back([callback](const std::any &event) {
        callback(std::any_cast<const EventType &>(event));
    });
}

template <typename EventType>
void EventBus::Publish(const EventType &event, PublishMode mode)
{
    if (mode == PublishMode::Queue)
    {
        std::lock_guard<std::mutex> lock(m_QueueMutex);
        m_EventQueue.emplace(typeid(EventType), event);
    }
    else
    {
        std::lock_guard<std::mutex> lock(m_SubscriberMutex);
        auto it = m_Subscribers.find(typeid(EventType));
        if (it != m_Subscribers.end())
        {
            for (auto &subscriber : it->second)
                subscriber(event);
        }
    }
}

} // namespace Lumen