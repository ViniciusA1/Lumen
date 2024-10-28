#include "Lumen/Math/Vector2.hpp"
#include <algorithm>
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Vector2 Vector2::Down = {0, -1};
const Vector2 Vector2::Left = {-1, 0};
const Vector2 Vector2::Right = {1, 0};
const Vector2 Vector2::Up = {0, 1};
const Vector2 Vector2::Zero = {0, 0};
const Vector2 Vector2::One = {1, 1};

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

float Vector2::Magnitude() const
{
    return std::sqrt(x * x + y * y);
}

float Vector2::SqrMagnitude() const
{
    return x * x + y * y;
}

Vector2 Vector2::Normalized() const
{
    float length = Magnitude();
    return (length > 0.0f) ? Vector2(x / length, y / length) : Vector2::Zero;
}

void Vector2::Normalize()
{
    float length = Magnitude();
    if (length > 0.0f)
    {
        x /= length;
        y /= length;
    }
}

float Vector2::Angle(const Vector2 &from, const Vector2 &to)
{
    float dot = Dot(from.Normalized(), to.Normalized());
    return std::acos(dot);
}

float Vector2::Distance(const Vector2 &v1, const Vector2 &v2)
{
    return (v1 - v2).Magnitude();
}

float Vector2::Dot(const Vector2 &v1, const Vector2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vector2 Vector2::Lerp(const Vector2 &a, const Vector2 &b, float t)
{
    return a + (b - a) * std::clamp(t, 0.0f, 1.0f);
}

Vector2 Vector2::LerpUnclamped(const Vector2 &a, const Vector2 &b, float t)
{
    return a + (b - a) * t;
}

Vector2 Vector2::Max(const Vector2 &v1, const Vector2 &v2)
{
    return {std::max(v1.x, v2.x), std::max(v1.y, v2.y)};
}

Vector2 Vector2::Min(const Vector2 &v1, const Vector2 &v2)
{
    return {std::min(v1.x, v2.x), std::min(v1.y, v2.y)};
}

Vector2 Vector2::Perpendicular(const Vector2 &v)
{
    return {-v.y, v.x};
}

Vector2 Vector2::Reflect(const Vector2 &direction, const Vector2 &normal)
{
    return direction - normal * 2.0f * Dot(direction, normal);
}

Vector2 Vector2::Scale(const Vector2 &v1, const Vector2 &v2)
{
    return {v1.x * v2.x, v1.y * v2.y};
}

float Vector2::SignedAngle(const Vector2 &from, const Vector2 &to)
{
    float angle = Angle(from, to);
    float cross = from.x * to.y - from.y * to.x;
    return cross < 0 ? -angle : angle;
}

Vector2::operator ::Vector2() const
{
    return {x, y};
}

} // namespace Lumen