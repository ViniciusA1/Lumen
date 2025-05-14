#pragma once

#include <initializer_list>
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
    static constexpr float Abs(float f);
    static constexpr float Fmod(float a, float b);
    static constexpr float Max(float a, float b);
    static constexpr float Min(float a, float b);
    static constexpr float Max(std::initializer_list<float> list);
    static constexpr float Min(std::initializer_list<float> list);
    static constexpr float Pow(float base, float exponent);
    static constexpr float Exp(float power);
    static constexpr float Sqrt(float f);

    static constexpr float Ceil(float f);
    static constexpr int CeilToInt(float f);
    static constexpr float Floor(float f);
    static constexpr int FloorToInt(float f);
    static constexpr float Round(float f);
    static constexpr int RoundToInt(float f);

    static constexpr float Cos(float angle);
    static constexpr float Sin(float angle);
    static constexpr float Tan(float angle);
    static constexpr float Acos(float f);
    static constexpr float Asin(float f);
    static constexpr float Atan(float f);
    static constexpr float Atan2(float y, float x);

    static constexpr float Lerp(float a, float b, float t);
    static constexpr float LerpUnclamped(float a, float b, float t);
    static constexpr float InverseLerp(float a, float b, float value);
    static constexpr float MoveTowards(float current, float target, float maxDelta);

    static constexpr float DeltaAngle(float current, float target);

    static constexpr float Clamp(float value, float min, float max);
    static constexpr float Clamp01(float value);
    static constexpr float Repeat(float t, float length);

    static constexpr bool Approximately(float a, float b);
    static constexpr bool IsPowerOfTwo(int value);
    static constexpr float Log(float value);
    static constexpr float Log10(float value);
    static constexpr float Sign(float f);
    static constexpr float SmoothStep(float min, float max, float t);
};

} // namespace Lumen

#include "Lumen/Math/Math.inl"