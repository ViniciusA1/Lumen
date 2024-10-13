#include "Lumen/Core/Input.hpp"
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

Vector2 Input::GetMousePosition()
{
    ::Vector2 pos = ::GetMousePosition();
    return {pos.x, pos.y};
}

float Input::GetMouseWheelMove()
{
    return ::GetMouseWheelMove();
}

} // namespace Lumen