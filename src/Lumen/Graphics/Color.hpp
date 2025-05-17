#pragma once

#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"

#include <string>

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

    constexpr Color();
    constexpr Color(unsigned char red, unsigned char green, unsigned char blue,
                    unsigned char alpha = 255);

    Color(const ::Color &color);

    [[nodiscard]] constexpr Vector4 Normalize() const;
    [[nodiscard]] constexpr std::string ToHex() const;
    [[nodiscard]] constexpr Vector3 ToHSV() const;
    [[nodiscard]] constexpr int ToInt() const;

    static constexpr Color Alpha(const Color &color, float alpha);
    static constexpr Color AlphaBlend(const Color &dst, const Color &src,
                                      const Color &tint);
    static constexpr Color Brightness(const Color &color, float factor);
    static constexpr Color Contrast(const Color &color, float contrast);
    static constexpr Color Fade(const Color &color, float alpha);
    static constexpr Color FromHexa(unsigned int hexValue);
    static constexpr Color FromHex(const std::string &hex);
    static constexpr Color FromHSV(float hue, float saturation, float value);
    static constexpr Color FromNormalized(const Vector4 &normalized);
    static constexpr Color Lerp(const Color &color1, const Color &color2, float factor);
    static constexpr Color Tint(const Color &color, const Color &tint);

    constexpr bool operator==(const Color &other) const;
    constexpr bool operator!=(const Color &other) const;
    operator ::Color() const;
};

} // namespace Lumen

#include "Lumen/Graphics/Color.inl"

namespace Lumen
{

inline constexpr Color Color::LightGray{200, 200, 200, 255};
inline constexpr Color Color::Gray{130, 130, 130, 255};
inline constexpr Color Color::DarkGray{80, 80, 80, 255};
inline constexpr Color Color::Yellow{253, 249, 0, 255};
inline constexpr Color Color::Gold{255, 203, 0, 255};
inline constexpr Color Color::Orange{255, 161, 0, 255};
inline constexpr Color Color::Pink{255, 109, 194, 255};
inline constexpr Color Color::Red{230, 41, 55, 255};
inline constexpr Color Color::Maroon{190, 33, 55, 255};
inline constexpr Color Color::Green{0, 228, 48, 255};
inline constexpr Color Color::Lime{0, 158, 47, 255};
inline constexpr Color Color::DarkGreen{0, 117, 44, 255};
inline constexpr Color Color::SkyBlue{102, 191, 255, 255};
inline constexpr Color Color::Blue{0, 121, 241, 255};
inline constexpr Color Color::DarkBlue{0, 82, 172, 255};
inline constexpr Color Color::Purple{200, 122, 255, 255};
inline constexpr Color Color::Violet{135, 60, 190, 255};
inline constexpr Color Color::DarkPurple{112, 31, 126, 255};
inline constexpr Color Color::Beige{211, 176, 131, 255};
inline constexpr Color Color::Brown{127, 106, 79, 255};
inline constexpr Color Color::DarkBrown{76, 63, 47, 255};
inline constexpr Color Color::White{255, 255, 255, 255};
inline constexpr Color Color::Black{0, 0, 0, 255};
inline constexpr Color Color::Blank{0, 0, 0, 0};
inline constexpr Color Color::Magenta{255, 0, 255, 255};
inline constexpr Color Color::RayWhite{245, 245, 245, 255};

} // namespace Lumen