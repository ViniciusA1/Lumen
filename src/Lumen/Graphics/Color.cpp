#include "Lumen/Graphics/Color.hpp"

#include "raylib.h"

namespace Lumen
{

Color::Color(const ::Color &color) : r(color.r), g(color.g), b(color.b), a(color.a)
{
}

Color::operator ::Color() const
{
    return {r, g, b, a};
}

} // namespace Lumen