#pragma once

#include <variant>

#include "Lumen/Event/ApplicationEvent.hpp"
#include "Lumen/Event/KeyboardEvent.hpp"
#include "Lumen/Event/MouseEvent.hpp"

namespace Lumen
{

enum class EventType
{
    WindowClose = 0,
    WindowResize,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

class EventQueue;

class Event
{
public:
    using EventData =
        std::variant<WindowCloseEvent, WindowResizeEvent, KeyPressedEvent,
                     KeyReleasedEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent,
                     MouseMovedEvent, MouseScrolledEvent>;

    static void PollEvents(EventQueue &queue);

public:
    bool Handled = false;

    Event(EventType type, const EventData &data);

    [[nodiscard]] EventType GetType() const { return m_Type; };
    template <typename T> T &GetData() { return std::get<T>(m_Data); }

private:
    EventType m_Type;
    EventData m_Data;
};

} // namespace Lumen