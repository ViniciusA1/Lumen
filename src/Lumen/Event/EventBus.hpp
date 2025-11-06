#pragma once

#include "Lumen/Event/PublishMode.hpp"

#include <any>
#include <functional>
#include <mutex>
#include <queue>
#include <typeindex>

#define BIND_EVENT(fn)                                                                   \
    [this](auto &&event) { this->fn(std::forward<decltype(event)>(event)); }

namespace Lumen
{

class EventBus
{
public:
    using CallbackFunction = std::function<void(const std::any &)>;

public:
    template <typename EventType>
    static void Subscribe(std::function<void(const EventType &)> callback);
    template <typename EventType>
    static void Publish(const EventType &event, PublishMode mode = PublishMode::Queue);

    static void ProcessEvents();

private:
    static std::unordered_map<std::type_index, std::vector<CallbackFunction>>
        m_Subscribers;

    static std::queue<std::pair<std::type_index, std::any>> m_EventQueue;

    static std::mutex m_SubscriberMutex;
    static std::mutex m_QueueMutex;
};

} // namespace Lumen

#include "Lumen/Event/EventBus.inl"