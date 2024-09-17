#include "Lumen/Graphics/Color.hpp"
#include <raylib.h>

namespace Lumen
{

const Color Color::LightGray = Color(200, 200, 200, 255);
const Color Color::Gray = Color(130, 130, 130, 255);
const Color Color::DarkGray = Color(80, 80, 80, 255);
const Color Color::Yellow = Color(253, 249, 0, 255);
const Color Color::Gold = Color(255, 203, 0, 255);
const Color Color::Orange = Color(255, 161, 0, 255);
const Color Color::Pink = Color(255, 109, 194, 255);
const Color Color::Red = Color(230, 41, 55, 255);
const Color Color::Maroon = Color(190, 33, 55, 255);
const Color Color::Green = Color(0, 228, 48, 255);
const Color Color::Lime = Color(0, 158, 47, 255);
const Color Color::DarkGreen = Color(0, 117, 44, 255);
const Color Color::SkyBlue = Color(102, 191, 255, 255);
const Color Color::Blue = Color(0, 121, 241, 255);
const Color Color::DarkBlue = Color(0, 82, 172, 255);
const Color Color::Purple = Color(200, 122, 255, 255);
const Color Color::Violet = Color(135, 60, 190, 255);
const Color Color::DarkPurple = Color(112, 31, 126, 255);
const Color Color::Beige = Color(211, 176, 131, 255);
const Color Color::Brown = Color(127, 106, 79, 255);
const Color Color::DarkBrown = Color(76, 63, 47, 255);
const Color Color::White = Color(255, 255, 255, 255);
const Color Color::Black = Color(0, 0, 0, 255);
const Color Color::Blank = Color(0, 0, 0, 0);
const Color Color::Magenta = Color(255, 0, 255, 255);
const Color Color::RayWhite = Color(245, 245, 245, 255);

Color::Color() : r(0), g(0), b(0), a(255)
{
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue,
             unsigned char alpha)
    : r(red), g(green), b(blue), a(alpha)
{
}

::Color Color::ToRaylib() const
{
    return (::Color){r, g, b, a};
}

} // namespace Lumen