#pragma once

#include "Lumen/Math/Math.hpp"

#include <algorithm>
#include <cmath>

namespace Lumen
{

constexpr float Math::Abs(float f)
{
    return std::fabs(f);
}

constexpr float Math::Fmod(float a, float b)
{
    return fmodf(a, b);
}

constexpr float Math::Max(float a, float b)
{
    return std::fmax(a, b);
}

constexpr float Math::Min(float a, float b)
{
    return std::fmin(a, b);
}

constexpr float Math::Max(std::initializer_list<float> list)
{
    return std::max(list);
}

constexpr float Math::Min(std::initializer_list<float> list)
{
    return std::min(list);
}

constexpr float Math::Pow(float base, float exponent)
{
    return std::pow(base, exponent);
}

constexpr float Math::Exp(float power)
{
    return std::exp(power);
}

constexpr float Math::Sqrt(float f)
{
    return std::sqrt(f);
}

constexpr float Math::Ceil(float f)
{
    return std::ceil(f);
}

constexpr int Math::CeilToInt(float f)
{
    return static_cast<int>(std::ceil(f));
}

constexpr float Math::Floor(float f)
{
    return std::floor(f);
}

constexpr int Math::FloorToInt(float f)
{
    return static_cast<int>(std::floor(f));
}

constexpr float Math::Round(float f)
{
    return std::round(f);
}

constexpr int Math::RoundToInt(float f)
{
    return static_cast<int>(std::round(f));
}

constexpr float Math::Cos(float angle)
{
    return std::cos(angle);
}

constexpr float Math::Sin(float angle)
{
    return std::sin(angle);
}

constexpr float Math::Tan(float angle)
{
    return std::tan(angle);
}

constexpr float Math::Acos(float f)
{
    return std::acos(f);
}

constexpr float Math::Asin(float f)
{
    return std::asin(f);
}

constexpr float Math::Atan(float f)
{
    return std::atan(f);
}

constexpr float Math::Atan2(float y, float x)
{
    return std::atan2(y, x);
}

constexpr float Math::Lerp(float a, float b, float t)
{
    return a + (b - a) * Clamp01(t);
}

constexpr float Math::LerpUnclamped(float a, float b, float t)
{
    return a + (b - a) * t;
}

constexpr float Math::InverseLerp(float a, float b, float value)
{
    return a != b ? Clamp01((value - a) / (b - a)) : 0.0f;
}

constexpr float Math::MoveTowards(float current, float target, float maxDelta)
{
    return std::fabs(target - current) <= maxDelta
               ? target
               : current + std::copysign(maxDelta, target - current);
}

constexpr float Math::DeltaAngle(float current, float target)
{
    float delta = std::fmod(target - current, 360.0f);
    return delta > 180.0f ? delta - 360.0f : delta;
}

constexpr float Math::Clamp(float value, float min, float max)
{
    return std::fmax(min, std::fmin(max, value));
}

constexpr float Math::Clamp01(float value)
{
    return Clamp(value, 0.0f, 1.0f);
}

constexpr float Math::Repeat(float t, float length)
{
    return std::fmod(t, length);
}

constexpr bool Math::Approximately(float a, float b)
{
    return std::fabs(a - b) < Epsilon;
}

constexpr bool Math::IsPowerOfTwo(int value)
{
    return (value & (value - 1)) == 0;
}

constexpr float Math::Log(float value)
{
    return std::log(value);
}

constexpr float Math::Log10(float value)
{
    return std::log10(value);
}

constexpr float Math::Sign(float f)
{
    return (f >= 0.0f) ? 1.0f : -1.0f;
}

constexpr float Math::SmoothStep(float min, float max, float t)
{
    t = Clamp01(t);
    return t * t * (3.0f - 2.0f * t);
}

} // namespace Lumen