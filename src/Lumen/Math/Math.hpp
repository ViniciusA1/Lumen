#pragma once

#include <cmath>
#include <limits>

namespace Lumen
{

class Math
{
public:
    static constexpr float PI = 3.14159265358979f;
    static constexpr float Deg2Rad = PI / 180.0f;
    static constexpr float Rad2Deg = 180.0f / PI;
    static constexpr float Epsilon = std::numeric_limits<float>::epsilon();
    static constexpr float Infinity = std::numeric_limits<float>::infinity();
    static constexpr float NegativeInfinity = -std::numeric_limits<float>::infinity();

public:
    static float Abs(float f);
    static float Max(float a, float b);
    static float Min(float a, float b);
    static float Pow(float base, float exponent);
    static float Exp(float power);
    static float Sqrt(float f);

    static float Ceil(float f);
    static int CeilToInt(float f);
    static float Floor(float f);
    static int FloorToInt(float f);
    static float Round(float f);
    static int RoundToInt(float f);

    static float Cos(float angle);
    static float Sin(float angle);
    static float Tan(float angle);
    static float Acos(float f);
    static float Asin(float f);
    static float Atan(float f);
    static float Atan2(float y, float x);

    static float Lerp(float a, float b, float t);
    static float LerpUnclamped(float a, float b, float t);
    static float InverseLerp(float a, float b, float value);
    static float MoveTowards(float current, float target, float maxDelta);

    static float DeltaAngle(float current, float target);

    static float Clamp(float value, float min, float max);
    static float Clamp01(float value);
    static float Repeat(float t, float length);

    static bool Approximately(float a, float b);
    static bool IsPowerOfTwo(int value);
    static float Log(float value);
    static float Log10(float value);
    static float Sign(float f);
    static float SmoothStep(float min, float max, float t);
};

inline float Math::Abs(float f)
{
    return std::fabs(f);
}
inline float Math::Max(float a, float b)
{
    return std::fmax(a, b);
}

inline float Math::Min(float a, float b)
{
    return std::fmin(a, b);
}

inline float Math::Pow(float base, float exponent)
{
    return std::pow(base, exponent);
}

inline float Math::Exp(float power)
{
    return std::exp(power);
}

inline float Math::Sqrt(float f)
{
    return std::sqrt(f);
}

inline float Math::Ceil(float f)
{
    return std::ceil(f);
}

inline int Math::CeilToInt(float f)
{
    return static_cast<int>(std::ceil(f));
}

inline float Math::Floor(float f)
{
    return std::floor(f);
}

inline int Math::FloorToInt(float f)
{
    return static_cast<int>(std::floor(f));
}

inline float Math::Round(float f)
{
    return std::round(f);
}

inline int Math::RoundToInt(float f)
{
    return static_cast<int>(std::round(f));
}

inline float Math::Cos(float angle)
{
    return std::cos(angle);
}

inline float Math::Sin(float angle)
{
    return std::sin(angle);
}

inline float Math::Tan(float angle)
{
    return std::tan(angle);
}

inline float Math::Acos(float f)
{
    return std::acos(f);
}

inline float Math::Asin(float f)
{
    return std::asin(f);
}

inline float Math::Atan(float f)
{
    return std::atan(f);
}

inline float Math::Atan2(float y, float x)
{
    return std::atan2(y, x);
}

inline float Math::Lerp(float a, float b, float t)
{
    return a + (b - a) * Clamp01(t);
}

inline float Math::LerpUnclamped(float a, float b, float t)
{
    return a + (b - a) * t;
}

inline float Math::InverseLerp(float a, float b, float value)
{
    return a != b ? Clamp01((value - a) / (b - a)) : 0.0f;
}

inline float Math::MoveTowards(float current, float target, float maxDelta)
{
    return std::fabs(target - current) <= maxDelta
               ? target
               : current + std::copysign(maxDelta, target - current);
}

inline float Math::DeltaAngle(float current, float target)
{
    float delta = std::fmod(target - current, 360.0f);
    return delta > 180.0f ? delta - 360.0f : delta;
}

inline float Math::Clamp(float value, float min, float max)
{
    return std::fmax(min, std::fmin(max, value));
}

inline float Math::Clamp01(float value)
{
    return Clamp(value, 0.0f, 1.0f);
}

inline float Math::Repeat(float t, float length)
{
    return std::fmod(t, length);
}

inline bool Math::Approximately(float a, float b)
{
    return std::fabs(a - b) < Epsilon;
}

inline bool Math::IsPowerOfTwo(int value)
{
    return (value & (value - 1)) == 0;
}

inline float Math::Log(float value)
{
    return std::log(value);
}

inline float Math::Log10(float value)
{
    return std::log10(value);
}

inline float Math::Sign(float f)
{
    return (f >= 0.0f) ? 1.0f : -1.0f;
}

inline float Math::SmoothStep(float min, float max, float t)
{
    t = Clamp01(t);
    return t * t * (3.0f - 2.0f * t);
}

} // namespace Lumen