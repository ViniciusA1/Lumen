#pragma once

#include "Lumen/Math/Rectangle.hpp"

namespace Lumen
{

constexpr Rectangle::Rectangle(float x, float y, float width, float height)
    : x(x), y(y), Width(width), Height(height)
{
}

constexpr Rectangle::Rectangle(float x, float y, const Vector2 &size)
    : x(x), y(y), Width(size.x), Height(size.y)
{
}

constexpr Rectangle::Rectangle(const Vector2 &position, float width, float height)
    : x(position.x), y(position.y), Width(width), Height(height)
{
}

constexpr Rectangle::Rectangle(const Vector2 &position, const Vector2 &size)
    : x(position.x), y(position.y), Width(size.x), Height(size.y)
{
}

constexpr bool Rectangle::Contains(const Vector2 &point) const
{
    return point.x >= x && point.x <= x + Width && point.y >= y && point.y <= y + Height;
}

constexpr bool Rectangle::Intersects(const Rectangle &other) const
{
    return x < other.x + other.Width && x + Width > other.x &&
           y < other.y + other.Height && y + Height > other.y;
}

constexpr Vector2 Rectangle::GetCenter() const
{
    return {x + Width / 2.0f, y + Height / 2.0f};
}

constexpr Vector2 Rectangle::GetPosition() const
{
    return {x, y};
}

constexpr Vector2 Rectangle::GetSize() const
{
    return {Width, Height};
}

constexpr void Rectangle::SetPosition(const Vector2 &position)
{
    x = position.x;
    y = position.y;
}

constexpr void Rectangle::SetSize(const Vector2 &size)
{
    Width = size.x;
    Height = size.y;
}

} // namespace Lumen