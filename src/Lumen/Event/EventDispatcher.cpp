#include "Lumen/Event/EventDispatcher.hpp"
#include <functional>
#include <unordered_map>

namespace Lumen
{

std::unordered_map<EventType, std::function<void(Layer &, Event &)>>
    EventDispatcher::s_EventMap = {
        {EventType::KeyPressed,
         [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetKeyboardListeners(),
                           &KeyboardListener::OnKeyPressed);
         }},
        {EventType::KeyReleased,
         [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetKeyboardListeners(),
                           &KeyboardListener::OnKeyReleased);
         }},
        {EventType::MouseMoved,
         [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetMouseListeners(),
                           &MouseListener::OnMouseMoved);
         }},
        {EventType::MouseScrolled,
         [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetMouseListeners(),
                           &MouseListener::OnMouseScrolled);
         }},
        {EventType::MouseButtonPressed,
         [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetMouseListeners(),
                           &MouseListener::OnMouseButtonPressed);
         }},
        {EventType::MouseButtonReleased, [](Layer &layer, Event &event) {
             DispatchEvent(layer, event, layer.GetMouseListeners(),
                           &MouseListener::OnMouseButtonReleased);
         }}};

void EventDispatcher::Dispatch(Layer &layer, Event &event)
{
    auto it = s_EventMap.find(event.GetType());
    if (it == s_EventMap.end())
    {
        return;
    }

    it->second(layer, event);
}

} // namespace Lumen