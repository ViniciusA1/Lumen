#include "Lumen/Event/Event.hpp"
#include "Lumen/Core/InputCode.hpp"
#include "Lumen/Event/EventQueue.hpp"
#include "Lumen/Event/KeyboardEvent.hpp"
#include "Lumen/Event/MouseEvent.hpp"
#include <raylib.h>

namespace Lumen
{

Event::Event(EventType type, const EventData &data) : m_Type(type), m_Data(data)
{
}

void Event::PollEvents(EventQueue &queue)
{
    queue.Clear();

    if (WindowShouldClose())
    {
        queue.Emplace(EventType::WindowClose, WindowCloseEvent{});
    }

    if (IsWindowResized())
    {
        queue.Emplace(EventType::WindowResize,
                      WindowResizeEvent{GetScreenWidth(), GetScreenHeight()});
    }

    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; key++)
    {
        if (IsKeyDown(key))
        {
            queue.Emplace(EventType::KeyPressed,
                          KeyPressedEvent{static_cast<KeyCode>(key), 1});
        }
        if (IsKeyReleased(key))
        {
            queue.Emplace(EventType::KeyReleased,
                          KeyReleasedEvent{static_cast<KeyCode>(key)});
        }
    }

    for (int button = MOUSE_LEFT_BUTTON; button <= MOUSE_BUTTON_BACK; button++)
    {
        if (IsMouseButtonPressed(button))
        {
            queue.Emplace(EventType::MouseButtonPressed,
                          MouseButtonPressedEvent{static_cast<MouseCode>(button),
                                                  GetMouseX(), GetMouseY()});
        }
        if (IsMouseButtonReleased(button))
        {
            queue.Emplace(EventType::MouseButtonReleased,
                          MouseButtonReleasedEvent{static_cast<MouseCode>(button),
                                                   GetMouseX(), GetMouseY()});
        }
    }

    if (GetMouseDelta().x != 0 || GetMouseDelta().y != 0)
    {
        queue.Emplace(EventType::MouseMoved, MouseMovedEvent{GetMouseX(), GetMouseY()});
    }

    Vector2 mouseScroll = GetMouseWheelMoveV();
    if (mouseScroll.y != 0)
    {
        queue.Emplace(EventType::MouseScrolled,
                      MouseScrolledEvent{mouseScroll.x, mouseScroll.y});
    }
}

} // namespace Lumen