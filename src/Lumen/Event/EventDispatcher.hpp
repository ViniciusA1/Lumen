#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Event/Event.hpp"
#include <functional>
#include <unordered_map>

namespace Lumen
{

class EventDispatcher
{
public:
    void Dispatch(Layer &layer, Event &event);

private:
    template <typename ListenerType, typename EventType>
    static void DispatchEvent(Layer &layer, Event &event,
                              std::vector<ListenerType> &listeners,
                              void (ListenerType::*listenerFunc)(EventType &))
    {
        EventType &specificEvent = event.GetData<EventType>();

        for (ListenerType &listener : listeners)
        {
            (listener.*listenerFunc)(specificEvent);
        }
    }

    static std::unordered_map<EventType, std::function<void(Layer &, Event &)>>
        s_EventMap;
};

} // namespace Lumen