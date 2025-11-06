#include "Lumen/Input/Input.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Event/KeyboardEvent.hpp"
#include "Lumen/Event/MouseEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"

#include "raylib.h"

namespace Lumen
{

bool Input::IsKeyDown(KeyCode key)
{
    return ::IsKeyDown(static_cast<int>(key));
}

bool Input::IsKeyPressed(KeyCode key)
{
    return ::IsKeyPressed(static_cast<int>(key));
}

bool Input::IsKeyPressedRepeat(KeyCode key)
{
    return ::IsKeyPressedRepeat(static_cast<int>(key));
}

bool Input::IsKeyReleased(KeyCode key)
{
    return ::IsKeyReleased(static_cast<int>(key));
}

bool Input::IsKeyUp(KeyCode key)
{
    return ::IsKeyUp(static_cast<int>(key));
}

int Input::GetCharPressed()
{
    return ::GetCharPressed();
}

KeyCode Input::GetKeyPressed()
{
    return static_cast<KeyCode>(::GetKeyPressed());
}

bool Input::IsMouseButtonDown(MouseCode button)
{
    return ::IsMouseButtonDown(static_cast<int>(button));
}

bool Input::IsMouseButtonPressed(MouseCode button)
{
    return ::IsMouseButtonPressed(static_cast<int>(button));
}

bool Input::IsMouseButtonReleased(MouseCode button)
{
    return ::IsMouseButtonReleased(static_cast<int>(button));
}

bool Input::IsMouseButtonUp(MouseCode button)
{
    return ::IsMouseButtonUp(static_cast<int>(button));
}

float Input::GetMouseAxisMovement(MouseCode axis)
{
    if (axis == MouseCode::AxisX)
        return GetMouseX();

    if (axis == MouseCode::AxisY)
        return GetMouseY();

    if (axis == MouseCode::AxisWheelX)
        return GetMouseWheelMoveV().x;

    if (axis == MouseCode::AxisWheelY)
        return GetMouseWheelMoveV().y;

    return 0;
}

Vector2 Input::GetMouseDelta()
{
    const ::Vector2 &delta = ::GetMouseDelta();
    return {delta.x, delta.y};
}

Vector2 Input::GetMousePosition()
{
    const ::Vector2 &pos = ::GetMousePosition();
    return {pos.x, pos.y};
}

float Input::GetMouseWheelMove()
{
    return ::GetMouseWheelMove();
}

Vector2 Input::GetMouseWheelMoveV()
{
    return ::GetMouseWheelMoveV();
}

int Input::GetMouseX()
{
    return ::GetMouseX();
}

int Input::GetMouseY()
{
    return ::GetMouseY();
}

void Input::SetMouseCursor(MouseCursor cursor)
{
    ::SetMouseCursor(static_cast<int>(cursor));
}

void Input::SetMouseOffset(int offsetX, int offsetY)
{
    ::SetMouseOffset(offsetX, offsetY);
}

void Input::SetMouseOffset(Vector2 offset)
{
    ::SetMouseOffset(offset.x, offset.y);
}

void Input::SetMousePosition(int x, int y)
{
    ::SetMousePosition(x, y);
}

void Input::SetMousePosition(Vector2 position)
{
    ::SetMousePosition(position.x, position.y);
}

void Input::SetMouseScale(float scaleX, float scaleY)
{
    ::SetMouseScale(scaleX, scaleY);
}

void Input::SetMouseScale(Vector2 scale)
{
    ::SetMouseScale(scale.x, scale.y);
}

bool Input::IsGamepadAvailable(int gamepad)
{
    return ::IsGamepadAvailable(gamepad);
}

bool Input::IsGamepadButtonDown(int gamepad, GamepadCode button)
{
    return ::IsGamepadButtonDown(gamepad, static_cast<int>(button));
}

bool Input::IsGamepadButtonPressed(int gamepad, GamepadCode button)
{
    return ::IsGamepadButtonPressed(gamepad, static_cast<int>(button));
}

bool Input::IsGamepadButtonReleased(int gamepad, GamepadCode button)
{
    return ::IsGamepadButtonReleased(gamepad, static_cast<int>(button));
}

bool Input::IsGamepadButtonUp(int gamepad, GamepadCode button)
{
    return ::IsGamepadButtonUp(gamepad, static_cast<int>(button));
}

int Input::GetGamepadAxisCount(int gamepad)
{
    return ::GetGamepadAxisCount(gamepad);
}

float Input::GetGamepadAxisMovement(int gamepad, GamepadCode axis)
{
    return ::GetGamepadAxisMovement(gamepad, static_cast<int>(axis) - 1000);
}

GamepadCode Input::GetGamepadButtonPressed()
{
    return static_cast<GamepadCode>(::GetGamepadButtonPressed());
}

std::string Input::GetGamepadName(int gamepad)
{
    return ::GetGamepadName(gamepad);
}

void Input::SetGamepadVibration(int gamepad, float leftMotor, float rightMotor,
                                float duration)
{
    ::SetGamepadVibration(gamepad, leftMotor, rightMotor, duration);
}

void Input::PollEvents()
{
    if (::WindowShouldClose())
        EventBus::Publish(WindowCloseEvent{});

    if (::IsWindowResized())
    {
        EventBus::Publish(WindowResizeEvent{
            ::GetScreenWidth(),
            ::GetScreenHeight(),
        });
    }

    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; key++)
    {
        if (::IsKeyDown(key))
        {
            EventBus::Publish(KeyPressedEvent{
                static_cast<KeyCode>(key),
                1,
            });
        }
        if (::IsKeyReleased(key))
        {
            EventBus::Publish(KeyReleasedEvent{
                static_cast<KeyCode>(key),
            });
        }
    }

    for (int button = MOUSE_LEFT_BUTTON; button <= MOUSE_BUTTON_BACK; button++)
    {
        if (::IsMouseButtonPressed(button))
        {
            EventBus::Publish(MouseButtonPressedEvent{
                static_cast<MouseCode>(button),
                Vector2(::GetMouseX(), ::GetMouseY()),
            });
        }
        if (::IsMouseButtonReleased(button))
        {
            EventBus::Publish(MouseButtonReleasedEvent{
                static_cast<MouseCode>(button),
                Vector2(::GetMouseX(), ::GetMouseY()),
            });
        }
    }

    if (::GetMouseDelta().x != 0 || ::GetMouseDelta().y != 0)
    {
        EventBus::Publish(MouseMovedEvent{
            Vector2(::GetMouseX(), ::GetMouseY()),
        });
    }

    const ::Vector2 &mouseScroll = GetMouseWheelMoveV();
    if (mouseScroll.x != 0 || mouseScroll.x != 0)
        EventBus::Publish(MouseScrolledEvent{mouseScroll});
}

} // namespace Lumen