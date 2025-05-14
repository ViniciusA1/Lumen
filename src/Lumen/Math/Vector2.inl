#pragma once

#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

constexpr Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

constexpr float Vector2::Length() const
{
    return Math::Sqrt(x * x + y * y);
}

constexpr float Vector2::LengthSqr() const
{
    return x * x + y * y;
}

constexpr Vector2 Vector2::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

constexpr float Vector2::Angle(const Vector2 &v1, const Vector2 &v2)
{
    float dot = Dot(v1, v2);
    float lengths = v1.Length() * v2.Length();

    if (lengths == 0.0f)
        return 0.0f;

    return Math::Acos(dot / lengths);
}

constexpr Vector2 Vector2::Clamp(const Vector2 &v, const Vector2 &min, const Vector2 &max)
{
    return {
        Math::Max(min.x, Math::Min(v.x, max.x)),
        Math::Max(min.y, Math::Min(v.y, max.y)),
    };
}

constexpr Vector2 Vector2::Clamp(const Vector2 &v, float min, float max)
{
    Vector2 result = v;
    float length = v.LengthSqr();

    if (length > 0.0f)
    {
        length = Math::Sqrt(length);

        float scale = 1;
        if (length < min)
        {
            scale = min / length;
        }
        else if (length > max)
        {
            scale = max / length;
        }

        result.x = v.x * scale;
        result.y = v.y * scale;
    }

    return result;
}

constexpr float Vector2::Distance(const Vector2 &v1, const Vector2 &v2)
{
    return (v1 - v2).Length();
}

constexpr float Vector2::DistanceSqr(const Vector2 &v1, const Vector2 &v2)
{
    return (v1 - v2).LengthSqr();
}

constexpr float Vector2::Dot(const Vector2 &v1, const Vector2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

constexpr Vector2 Vector2::Lerp(const Vector2 &v1, const Vector2 &v2, float amount)
{
    return v1 + (v2 - v1) * Math::Clamp(amount, 0.0f, 1.0f);
}

constexpr Vector2 Vector2::MoveTowards(const Vector2 &v, const Vector2 &target,
                                       float maxDist)
{
    Vector2 delta = target - v;
    float dist = delta.Length();

    if (dist <= maxDist || dist == 0.0f)
        return target;

    return v + delta.Normalized() * maxDist;
}

constexpr Vector2 Vector2::Reflect(const Vector2 &v, const Vector2 &normal)
{
    return v - normal * 2.0f * Dot(v, normal);
}

constexpr Vector2 Vector2::Rotate(const Vector2 &v, float angle)
{
    float cosAngle = Math::Cos(angle);
    float sinAngle = Math::Sin(angle);
    return {v.x * cosAngle - v.y * sinAngle, v.x * sinAngle + v.y * cosAngle};
}

constexpr Vector2 Vector2::Transform(const Vector2 &v, const Matrix4 &mat)
{
    return {
        mat[0] * v.x + mat[4] * v.y + mat[12],
        mat[1] * v.x + mat[5] * v.y + mat[13],
    };
}

constexpr Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

constexpr Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

constexpr Vector2 operator*(const Vector2 &vec, float scalar)
{
    return {vec.x * scalar, vec.y * scalar};
}

constexpr Vector2 operator*(float scalar, const Vector2 &vec)
{
    return vec * scalar;
}

constexpr Vector2 operator/(const Vector2 &vec, float scalar)
{
    if (scalar == 0)
        return vec;
    return {vec.x / scalar, vec.y / scalar};
}

constexpr Vector2 operator/(float scalar, const Vector2 &vec)
{
    if (vec.x == 0 || vec.y == 0)
        return vec;
    return {scalar / vec.x, scalar / vec.y};
}

constexpr Vector2 &operator+=(Vector2 &lhs, const Vector2 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

constexpr Vector2 &operator-=(Vector2 &lhs, const Vector2 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

constexpr Vector2 &operator*=(Vector2 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    return vec;
}

constexpr Vector2 &operator/=(Vector2 &vec, float scalar)
{
    if (scalar == 0)
        return vec;
    vec.x /= scalar;
    vec.y /= scalar;
    return vec;
}

constexpr bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

constexpr bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
    return !(lhs == rhs);
}

} // namespace Lumen