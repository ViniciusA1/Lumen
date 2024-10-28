#pragma once

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

    operator ::Color() const;
};

} // namespace Lumen