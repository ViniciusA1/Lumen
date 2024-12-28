#pragma once

#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"

struct Color;

namespace Lumen
{

class Color
{
public:
    static const Color LightGray;
    static const Color Gray;
    static const Color DarkGray;
    static const Color Yellow;
    static const Color Gold;
    static const Color Orange;
    static const Color Pink;
    static const Color Red;
    static const Color Maroon;
    static const Color Green;
    static const Color Lime;
    static const Color DarkGreen;
    static const Color SkyBlue;
    static const Color Blue;
    static const Color DarkBlue;
    static const Color Purple;
    static const Color Violet;
    static const Color DarkPurple;
    static const Color Beige;
    static const Color Brown;
    static const Color DarkBrown;
    static const Color White;
    static const Color Black;
    static const Color Blank;
    static const Color Magenta;
    static const Color RayWhite;

public:
    unsigned char r, g, b, a;

    Color();
    Color(unsigned char red, unsigned char green, unsigned char blue,
          unsigned char alpha = 255);
    Color(const ::Color &color);

    [[nodiscard]] Vector4 Normalize() const;
    [[nodiscard]] Vector3 ToHSV() const;
    [[nodiscard]] int ToInt() const;

    static Color Alpha(const Color &color, float alpha);
    static Color AlphaBlend(const Color &dst, const Color &src, const Color &tint);
    static Color Brightness(const Color &color, float factor);
    static Color Contrast(const Color &color, float contrast);
    static Color Fade(const Color &color, float alpha);
    static Color FromHexa(unsigned int hexValue);
    static Color FromHSV(float hue, float saturation, float value);
    static Color FromNormalized(const Vector4 &normalized);
    static Color Lerp(const Color &color1, const Color &color2, float factor);
    static Color Tint(const Color &color, const Color &tint);

    bool operator==(const Color &other) const;
    bool operator!=(const Color &other) const;
    operator ::Color() const;
};

} // namespace Lumen