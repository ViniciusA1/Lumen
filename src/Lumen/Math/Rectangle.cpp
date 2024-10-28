#include "Lumen/Math/Rectangle.hpp"
#include "raylib.h"

namespace Lumen
{

Rectangle::Rectangle(float x, float y, float width, float height)
    : X(x), Y(y), Width(width), Height(height)
{
}

Rectangle::operator ::Rectangle() const
{
    return {X, Y, Width, Height};
}

} // namespace Lumen