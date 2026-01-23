#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/World/Component/Core/TransformComponent.hpp"

#include "raylib.h"

namespace Lumen
{

Rectangle::Rectangle(const TransformComponent &transform)
{
    x = transform.Position.x - (transform.Scale.x / 2.0f);
    y = transform.Position.y - (transform.Scale.y / 2.0f);
    Width = transform.Scale.x;
    Height = transform.Scale.y;
}

Rectangle::Rectangle(const struct ::Rectangle &rectangle)
    : x(rectangle.x), y(rectangle.y), Width(rectangle.width), Height(rectangle.height)
{
}

Rectangle::operator ::Rectangle() const
{
    return {x, y, Width, Height};
}

} // namespace Lumen