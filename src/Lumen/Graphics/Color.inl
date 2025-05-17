#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Math.hpp"

#include <cstdint>

namespace Lumen
{

constexpr Color::Color() : r(0), g(0), b(0), a(255)
{
}

constexpr Color::Color(unsigned char red, unsigned char green, unsigned char blue,
                       unsigned char alpha)
    : r(red), g(green), b(blue), a(alpha)
{
}

constexpr Vector4 Color::Normalize() const
{
    return {
        r / 255.0f,
        g / 255.0f,
        b / 255.0f,
        a / 255.0f,
    };
}

constexpr std::string Color::ToHex() const
{
    constexpr char hexDigits[] = "0123456789ABCDEF";
    std::string result;
    result.reserve(9);
    result += '#';
    result += hexDigits[(r >> 4) & 0xF];
    result += hexDigits[r & 0xF];
    result += hexDigits[(g >> 4) & 0xF];
    result += hexDigits[g & 0xF];
    result += hexDigits[(b >> 4) & 0xF];
    result += hexDigits[b & 0xF];
    result += hexDigits[(a >> 4) & 0xF];
    result += hexDigits[a & 0xF];
    return result;
}

constexpr Vector3 Color::ToHSV() const
{
    const Vector3 rgbNormalized{
        static_cast<float>(r) / 255.0f,
        static_cast<float>(g) / 255.0f,
        static_cast<float>(b) / 255.0f,
    };
    const float minComponent = Math::Min({
        rgbNormalized.x,
        rgbNormalized.y,
        rgbNormalized.z,
    });
    const float maxComponent = Math::Max({
        rgbNormalized.x,
        rgbNormalized.y,
        rgbNormalized.z,
    });

    const float delta = maxComponent - minComponent;

    Vector3 hsv;
    hsv.z = maxComponent;

    if (delta < 0.00001f)
    {
        hsv.y = 0.0f;
        hsv.x = 0.0f;
        return hsv;
    }

    hsv.y = (maxComponent > 0.0f) ? (delta / maxComponent) : 0.0f;

    if (maxComponent <= 0.0f)
    {
        hsv.x = NAN;
        return hsv;
    }

    if (rgbNormalized.x >= maxComponent)
        hsv.x = (rgbNormalized.y - rgbNormalized.z) / delta;
    else if (rgbNormalized.y >= maxComponent)
        hsv.x = 2.0f + (rgbNormalized.z - rgbNormalized.x) / delta;
    else
        hsv.x = 4.0f + (rgbNormalized.x - rgbNormalized.y) / delta;

    hsv.x *= 60.0f;
    if (hsv.x < 0.0f)
        hsv.x += 360.0f;

    return hsv;
}

constexpr int Color::ToInt() const
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}

constexpr Color Color::Alpha(const Color &color, float alpha)
{
    alpha = Math::Clamp01(alpha);
    return {
        color.r,
        color.g,
        color.b,
        static_cast<unsigned char>(alpha * 255),
    };
}

constexpr Color Color::AlphaBlend(const Color &dst, const Color &src, const Color &tint)
{
    const auto applyTint = [](uint8_t channel, uint8_t tint_channel) -> uint8_t {
        return static_cast<uint8_t>((static_cast<uint16_t>(channel) *
                                     (static_cast<uint16_t>(tint_channel) + 1)) >>
                                    8);
    };

    Color tintedSrc{
        applyTint(src.r, tint.r),
        applyTint(src.g, tint.g),
        applyTint(src.b, tint.b),
        applyTint(src.a, tint.a),
    };

    if (tintedSrc.a == 0)
        return dst;
    if (tintedSrc.a == 255)
        return tintedSrc;

    const auto srcAlpha = static_cast<uint16_t>(tintedSrc.a) + 1;
    const auto invSrcAlpha = 256 - srcAlpha;
    const auto dstAlpha = static_cast<uint16_t>(dst.a);

    Color result;
    result.a = static_cast<uint8_t>((srcAlpha * 256 + dstAlpha * invSrcAlpha) >> 8);

    if (result.a == 0)
        return result;

    const auto blendChannel = [=](uint8_t src_c, uint8_t dst_c) -> uint8_t {
        const uint32_t numerator =
            (static_cast<uint32_t>(src_c) * srcAlpha * 256) +
            (static_cast<uint32_t>(dst_c) * dstAlpha * invSrcAlpha);
        return static_cast<uint8_t>((numerator / static_cast<uint32_t>(result.a)) >> 8);
    };

    result.r = blendChannel(tintedSrc.r, dst.r);
    result.g = blendChannel(tintedSrc.g, dst.g);
    result.b = blendChannel(tintedSrc.b, dst.b);

    return result;
}

constexpr Color Color::Brightness(const Color &color, float factor)
{
    return {
        static_cast<unsigned char>(Math::Clamp(color.r * factor, 0.0f, 255.0f)),
        static_cast<unsigned char>(Math::Clamp(color.g * factor, 0.0f, 255.0f)),
        static_cast<unsigned char>(Math::Clamp(color.b * factor, 0.0f, 255.0f)),
        color.a,
    };
}

constexpr Color Color::Contrast(const Color &color, float contrast)
{
    contrast = Math::Clamp(contrast, -1.0f, 1.0f);
    const float contrastFactor = (1.0f + contrast) * (1.0f + contrast);

    const auto applyContrast = [contrastFactor](uint8_t channel) -> uint8_t {
        float normalized = static_cast<float>(channel) / 255.0f - 0.5f;
        normalized *= contrastFactor;
        float result = (normalized + 0.5f) * 255.0f;
        return static_cast<uint8_t>(Math::Clamp(result, 0.0f, 255.0f));
    };

    return {
        applyContrast(color.r),
        applyContrast(color.g),
        applyContrast(color.b),
        color.a,
    };
}

constexpr Color Color::Fade(const Color &color, float alpha)
{
    alpha = Math::Clamp01(alpha);
    return {
        color.r,
        color.g,
        color.b,
        static_cast<unsigned char>(alpha * 255),
    };
}

constexpr Color Color::FromHex(const std::string &hex)
{
    if (hex.empty() || hex[0] != '#' || (hex.size() != 7 && hex.size() != 9))
        return {};

    constexpr auto hexCharToValue = [](char c) -> unsigned char {
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'A' && c <= 'F')
            return 10 + (c - 'A');
        if (c >= 'a' && c <= 'f')
            return 10 + (c - 'a');
        return 0;
    };

    const auto hexToByte = [&](size_t offset) -> unsigned char {
        return (hexCharToValue(hex[offset]) << 4 | hexCharToValue(hex[offset + 1]));
    };

    if (hex.size() == 7)
    {
        return {
            hexToByte(1),
            hexToByte(3),
            hexToByte(5),
            255,
        };
    }
    else
    {
        return {
            hexToByte(1),
            hexToByte(3),
            hexToByte(5),
            hexToByte(7),
        };
    }
}

constexpr Color Color::FromHexa(unsigned int hexValue)
{
    return {
        static_cast<unsigned char>((hexValue >> 24) & 0xFF),
        static_cast<unsigned char>((hexValue >> 16) & 0xFF),
        static_cast<unsigned char>((hexValue >> 8) & 0xFF),
        static_cast<unsigned char>(hexValue & 0xFF),
    };
}

constexpr Color Color::FromHSV(float hue, float saturation, float value)
{
    hue = Math::Fmod(hue, 360.0f);
    saturation = Math::Clamp(saturation, 0.0f, 1.0f);
    value = Math::Clamp(value, 0.0f, 1.0f);

    const float chroma = value * saturation;
    const float hue_sector = hue / 60.0f;
    const float x = chroma * (1.0f - std::abs(Math::Fmod(hue_sector, 2.0f) - 1.0f));
    const float m = value - chroma;

    const float r = (hue_sector < 1.0f)   ? chroma
                    : (hue_sector < 2.0f) ? x
                    : (hue_sector < 3.0f) ? 0.0f
                    : (hue_sector < 4.0f) ? 0.0f
                    : (hue_sector < 5.0f) ? x
                                          : chroma;

    const float g = (hue_sector < 1.0f)   ? x
                    : (hue_sector < 2.0f) ? chroma
                    : (hue_sector < 3.0f) ? chroma
                    : (hue_sector < 4.0f) ? x
                    : (hue_sector < 5.0f) ? 0.0f
                                          : 0.0f;

    const float b = (hue_sector < 1.0f)   ? 0.0f
                    : (hue_sector < 2.0f) ? 0.0f
                    : (hue_sector < 3.0f) ? x
                    : (hue_sector < 4.0f) ? chroma
                    : (hue_sector < 5.0f) ? chroma
                                          : x;

    return {
        static_cast<uint8_t>((r + m) * 255.0f),
        static_cast<uint8_t>((g + m) * 255.0f),
        static_cast<uint8_t>((b + m) * 255.0f),
        255,
    };
}

constexpr Color Color::FromNormalized(const Vector4 &normalized)
{
    return {
        static_cast<unsigned char>(normalized.x * 255),
        static_cast<unsigned char>(normalized.y * 255),
        static_cast<unsigned char>(normalized.z * 255),
        static_cast<unsigned char>(normalized.w * 255),
    };
}

constexpr Color Color::Lerp(const Color &color1, const Color &color2, float factor)
{
    factor = Math::Clamp01(factor);
    return {
        static_cast<unsigned char>(color1.r + factor * (color2.r - color1.r)),
        static_cast<unsigned char>(color1.g + factor * (color2.g - color1.g)),
        static_cast<unsigned char>(color1.b + factor * (color2.b - color1.b)),
        static_cast<unsigned char>(color1.a + factor * (color2.a - color1.a)),
    };
}

constexpr Color Color::Tint(const Color &color, const Color &tint)
{
    return {
        static_cast<unsigned char>((color.r * tint.r) / 255),
        static_cast<unsigned char>((color.g * tint.g) / 255),
        static_cast<unsigned char>((color.b * tint.b) / 255),
        static_cast<unsigned char>((color.a * tint.a) / 255),
    };
}

constexpr bool Color::operator==(const Color &other) const
{
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

constexpr bool Color::operator!=(const Color &other) const
{
    return !(*this == other);
}

} // namespace Lumen