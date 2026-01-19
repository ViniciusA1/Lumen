#pragma once

#include "Lumen/Input/MouseCode.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

struct MouseMovedEvent
{
    Vector2 Position;
};

struct MouseScrolledEvent
{
    Vector2 Offset;
};

struct MouseButtonPressedEvent
{
    MouseCode Button;
    Vector2 Position;
};

struct MouseButtonReleasedEvent
{
    MouseCode Button;
    Vector2 Position;
};

} // namespace Lumen