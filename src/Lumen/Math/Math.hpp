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

} // namespace Lumen

#include "Lumen/Math/Math.inl"