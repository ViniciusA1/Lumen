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
    static float Abs(float f) { return std::fabs(f); }
    static float Acos(float f) { return std::acos(f); }
    static bool Approximately(float a, float b) { return std::fabs(a - b) < Epsilon; }
    static float Asin(float f) { return std::asin(f); }
    static float Atan(float f) { return std::atan(f); }
    static float Atan2(float y, float x) { return std::atan2(y, x); }

    static float Ceil(float f) { return std::ceil(f); }
    static int CeilToInt(float f) { return static_cast<int>(std::ceil(f)); }

    static float Clamp(float value, float min, float max)
    {
        return std::fmax(min, std::fmin(max, value));
    }
    static float Clamp01(float value) { return Clamp(value, 0.0f, 1.0f); }

    static bool IsPowerOfTwo(int value) { return (value & (value - 1)) == 0; }

    static float Cos(float angle) { return std::cos(angle); }

    static float DeltaAngle(float current, float target)
    {
        float delta = std::fmod(target - current, 360.0f);
        if (delta > 180.0f)
            delta -= 360.0f;
        return delta;
    }

    static float Exp(float power) { return std::exp(power); }

    static float Floor(float f) { return std::floor(f); }
    static int FloorToInt(float f) { return static_cast<int>(std::floor(f)); }

    static float Lerp(float a, float b, float t) { return a + (b - a) * Clamp01(t); }
    static float LerpUnclamped(float a, float b, float t) { return a + (b - a) * t; }

    static float Log(float value) { return std::log(value); }
    static float Log10(float value) { return std::log10(value); }

    static float Max(float a, float b) { return std::fmax(a, b); }
    static float Min(float a, float b) { return std::fmin(a, b); }

    static float MoveTowards(float current, float target, float maxDelta)
    {
        if (std::fabs(target - current) <= maxDelta)
        {
            return target;
        }
        return current + std::copysign(maxDelta, target - current);
    }

    static float Pow(float base, float exponent) { return std::pow(base, exponent); }

    static float Repeat(float t, float length) { return std::fmod(t, length); }

    static float Round(float f) { return std::round(f); }
    static int RoundToInt(float f) { return static_cast<int>(std::round(f)); }

    static float Sign(float f) { return (f >= 0.0f) ? 1.0f : -1.0f; }

    static float Sin(float angle) { return std::sin(angle); }

    static float Sqrt(float f) { return std::sqrt(f); }

    static float Tan(float angle) { return std::tan(angle); }

    static float InverseLerp(float a, float b, float value)
    {
        if (a != b)
            return Clamp01((value - a) / (b - a));
        return 0.0f;
    }

    static float SmoothStep(float min, float max, float t)
    {
        t = Clamp01(t);
        return t * t * (3.0f - 2.0f * t);
    }
};

} // namespace Lumen