#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Math.hpp"
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

Color::Color(const ::Color &color) : r(color.r), g(color.g), b(color.b), a(color.a)
{
}

Vector4 Color::Normalize() const
{
    return Vector4{r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};
}

Vector3 Color::ToHSV() const
{
    return ::ColorToHSV(*this);
}

int Color::ToInt() const
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}

Color Color::Alpha(const Color &color, float alpha)
{
    alpha = Math::Clamp01(alpha);
    return {color.r, color.g, color.b, static_cast<unsigned char>(alpha * 255)};
}

Color Color::AlphaBlend(const Color &dst, const Color &src, const Color &tint)
{
    return ::ColorAlphaBlend(dst, src, tint);
}

Color Color::Brightness(const Color &color, float factor)
{
    return {static_cast<unsigned char>(Math::Clamp(color.r * factor, 0.0f, 255.0f)),
            static_cast<unsigned char>(Math::Clamp(color.g * factor, 0.0f, 255.0f)),
            static_cast<unsigned char>(Math::Clamp(color.b * factor, 0.0f, 255.0f)),
            color.a};
}

Color Color::Contrast(const Color &color, float contrast)
{
    return ::ColorContrast(color, contrast);
}

Color Color::Fade(const Color &color, float alpha)
{
    alpha = Math::Clamp01(alpha);
    return {color.r, color.g, color.b, static_cast<unsigned char>(alpha * 255)};
}

Color Color::FromHexa(unsigned int hexValue)
{
    return {static_cast<unsigned char>((hexValue >> 24) & 0xFF),
            static_cast<unsigned char>((hexValue >> 16) & 0xFF),
            static_cast<unsigned char>((hexValue >> 8) & 0xFF),
            static_cast<unsigned char>(hexValue & 0xFF)};
}

Color Color::FromHSV(float hue, float saturation, float value)
{
    return ::ColorFromHSV(hue, saturation, value);
}

Color Color::FromNormalized(const Vector4 &normalized)
{
    return {static_cast<unsigned char>(normalized.x * 255),
            static_cast<unsigned char>(normalized.y * 255),
            static_cast<unsigned char>(normalized.z * 255),
            static_cast<unsigned char>(normalized.w * 255)};
}

Color Color::Lerp(const Color &color1, const Color &color2, float factor)
{
    factor = Math::Clamp01(factor);
    return {static_cast<unsigned char>(color1.r + factor * (color2.r - color1.r)),
            static_cast<unsigned char>(color1.g + factor * (color2.g - color1.g)),
            static_cast<unsigned char>(color1.b + factor * (color2.b - color1.b)),
            static_cast<unsigned char>(color1.a + factor * (color2.a - color1.a))};
}

Color Color::Tint(const Color &color, const Color &tint)
{
    return {static_cast<unsigned char>((color.r * tint.r) / 255),
            static_cast<unsigned char>((color.g * tint.g) / 255),
            static_cast<unsigned char>((color.b * tint.b) / 255),
            static_cast<unsigned char>((color.a * tint.a) / 255)};
}

bool Color::operator==(const Color &other) const
{
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Color::operator!=(const Color &other) const
{
    return !(*this == other);
}

Color::operator ::Color() const
{
    return {r, g, b, a};
}

} // namespace Lumen