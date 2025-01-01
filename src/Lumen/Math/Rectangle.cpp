#include "Lumen/Math/Rectangle.hpp"
#include "raylib.h"

namespace Lumen
{

Rectangle::Rectangle(float x, float y, float width, float height)
    : x(x), y(y), Width(width), Height(height)
{
}

Rectangle::Rectangle(const Vector2 &position, const Vector2 &size)
    : x(position.x), y(position.y), Width(size.x), Height(size.y)
{
}

Rectangle::Rectangle(const ::Rectangle rectangle)
    : x(rectangle.x), y(rectangle.y), Width(rectangle.width), Height(rectangle.height)
{
}

Rectangle::operator ::Rectangle() const
{
    return {x, y, Width, Height};
}

} // namespace Lumen