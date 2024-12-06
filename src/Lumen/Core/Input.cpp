#include "Lumen/Core/Input.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Event/KeyboardEvent.hpp"
#include "Lumen/Event/MouseEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"
#include <raylib.h>

namespace Lumen
{

bool Input::GetKeyPressed(KeyCode key)
{
    return ::IsKeyPressed(static_cast<int>(key));
}

bool Input::GetKeyDown(KeyCode key)
{
    return ::IsKeyDown(static_cast<int>(key));
}

bool Input::GetKeyUp(KeyCode key)
{
    return ::IsKeyUp(static_cast<int>(key));
}

bool Input::GetMouseButton(MouseCode button)
{
    return ::IsMouseButtonPressed(static_cast<int>(button));
}

bool Input::GetMouseButtonDown(MouseCode button)
{
    return ::IsMouseButtonDown(static_cast<int>(button));
}

bool Input::GetMouseButtonUp(MouseCode button)
{
    return ::IsMouseButtonUp(static_cast<int>(button));
}

Vector2 Input::GetMouseDelta()
{
    ::Vector2 delta = ::GetMouseDelta();
    return {delta.x, delta.y};
}

Vector2 Input::GetMousePosition()
{
    ::Vector2 pos = ::GetMousePosition();
    return {pos.x, pos.y};
}

float Input::GetMouseWheelMove()
{
    return ::GetMouseWheelMove();
}

void Input::SetMousePosition(int x, int y)
{
    ::SetMousePosition(x, y);
}

void Input::PollEvents()
{
    if (WindowShouldClose())
    {
        EventBus::Publish(WindowCloseEvent{});
    }

    if (IsWindowResized())
    {
        EventBus::Publish(WindowResizeEvent{GetScreenWidth(), GetScreenHeight()});
    }

    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; key++)
    {
        if (IsKeyDown(key))
        {
            EventBus::Publish(KeyPressedEvent{static_cast<KeyCode>(key), 1});
        }
        if (IsKeyReleased(key))
        {
            EventBus::Publish(KeyReleasedEvent{static_cast<KeyCode>(key)});
        }
    }

    for (int button = MOUSE_LEFT_BUTTON; button <= MOUSE_BUTTON_BACK; button++)
    {
        if (IsMouseButtonPressed(button))
        {
            EventBus::Publish(MouseButtonPressedEvent{static_cast<MouseCode>(button),
                                                      GetMouseX(), GetMouseY()});
        }
        if (IsMouseButtonReleased(button))
        {
            EventBus::Publish(MouseButtonReleasedEvent{static_cast<MouseCode>(button),
                                                       GetMouseX(), GetMouseY()});
        }
    }

    if (GetMouseDelta().x != 0 || GetMouseDelta().y != 0)
    {
        EventBus::Publish(MouseMovedEvent{GetMouseX(), GetMouseY()});
    }

    ::Vector2 mouseScroll = GetMouseWheelMoveV();
    if (mouseScroll.y != 0)
    {
        EventBus::Publish(MouseScrolledEvent{mouseScroll.x, mouseScroll.y});
    }
}

} // namespace Lumen