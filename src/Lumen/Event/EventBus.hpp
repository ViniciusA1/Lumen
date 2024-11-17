#pragma once

#include <any>
#include <functional>
#include <queue>
#include <typeindex>

#define BIND_EVENT(fn)                                                                   \
    [this](auto &&event) { this->fn(std::forward<decltype(event)>(event)); }

namespace Lumen
{

using EventCallbackFunction = std::function<void(const std::any &)>;

class EventBus
{
public:
    template <typename EventType>
    static void Subscribe(std::function<void(const EventType &)> callback);
    template <typename EventType> static void Publish(const EventType &event);

    static void ProcessEvents();

private:
    static std::unordered_map<std::type_index, std::vector<EventCallbackFunction>>
        m_Subscribers;

    static std::queue<std::pair<std::type_index, std::any>> m_EventQueue;
};

template <typename EventType>
void EventBus::Subscribe(std::function<void(const EventType &)> callback)
{
    auto &subscribers = m_Subscribers[typeid(EventType)];
    subscribers.emplace_back([callback](const std::any &event) {
        callback(std::any_cast<const EventType &>(event));
    });
}

template <typename EventType> void EventBus::Publish(const EventType &event)
{
    m_EventQueue.emplace(typeid(EventType), event);
}

} // namespace Lumen