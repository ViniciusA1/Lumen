#pragma once

#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Vector4.hpp"

namespace Lumen
{

constexpr Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

constexpr float Vector4::Length() const
{
    return Math::Sqrt(x * x + y * y + z * z + w * w);
}

constexpr float Vector4::LengthSqr() const
{
    return x * x + y * y + z * z + w * w;
}

constexpr Vector4 Vector4::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

constexpr float Vector4::Distance(const Vector4 &v1, const Vector4 &v2)
{
    return (v1 - v2).Length();
}

constexpr float Vector4::DistanceSqr(const Vector4 &v1, const Vector4 &v2)
{
    return (v1 - v2).LengthSqr();
}

constexpr float Vector4::Dot(const Vector4 &v1, const Vector4 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

constexpr Vector4 Vector4::Lerp(const Vector4 &v1, const Vector4 &v2, float amount)
{
    return v1 + (v2 - v1) * Math::Clamp(amount, 0.0f, 1.0f);
}

constexpr Vector4 Vector4::Max(const Vector4 &v1, const Vector4 &v2)
{
    return {
        Math::Max(v1.x, v2.x),
        Math::Max(v1.y, v2.y),
        Math::Max(v1.z, v2.z),
        Math::Max(v1.w, v2.w),
    };
}

constexpr Vector4 Vector4::Min(const Vector4 &v1, const Vector4 &v2)
{
    return {
        Math::Min(v1.x, v2.x),
        Math::Min(v1.y, v2.y),
        Math::Min(v1.z, v2.z),
        Math::Min(v1.w, v2.w),
    };
}

constexpr Vector4 Vector4::MoveTowards(const Vector4 &v, const Vector4 &target,
                                       float maxDist)
{
    Vector4 delta = target - v;
    float dist = delta.Length();

    if (dist <= maxDist || dist == 0.0f)
        return target;

    return v + delta.Normalized() * maxDist;
}

constexpr Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs)
{
    return {
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
        lhs.w + rhs.w,
    };
}

constexpr Vector4 operator-(const Vector4 &lhs, const Vector4 &rhs)
{
    return {
        lhs.x - rhs.x,
        lhs.y - rhs.y,
        lhs.z - rhs.z,
        lhs.w - rhs.w,
    };
}

constexpr Vector4 operator*(const Vector4 &vec, float scalar)
{
    return {
        vec.x * scalar,
        vec.y * scalar,
        vec.z * scalar,
        vec.w * scalar,
    };
}

constexpr Vector4 operator*(float scalar, const Vector4 &vec)
{
    return {
        vec.x * scalar,
        vec.y * scalar,
        vec.z * scalar,
        vec.w * scalar,
    };
}

constexpr Vector4 operator/(const Vector4 &vec, float scalar)
{
    if (scalar == 0.0f)
        return Vector4::Zero;

    return {
        vec.x / scalar,
        vec.y / scalar,
        vec.z / scalar,
        vec.w / scalar,
    };
}

constexpr Vector4 operator/(float scalar, const Vector4 &vec)
{
    if (vec.x == 0.0f || vec.y == 0.0f || vec.z == 0.0f || vec.w == 0.0f)
        return Vector4::Zero;

    return {
        scalar / vec.x,
        scalar / vec.y,
        scalar / vec.z,
        scalar / vec.w,
    };
}

constexpr Vector4 &operator+=(Vector4 &lhs, const Vector4 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

constexpr Vector4 &operator-=(Vector4 &lhs, const Vector4 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

constexpr Vector4 &operator*=(Vector4 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;
    vec.w *= scalar;
    return vec;
}

constexpr Vector4 &operator/=(Vector4 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    vec.x /= scalar;
    vec.y /= scalar;
    vec.z /= scalar;
    vec.w /= scalar;
    return vec;
}

constexpr bool operator==(const Vector4 &lhs, const Vector4 &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

constexpr bool operator!=(const Vector4 &lhs, const Vector4 &rhs)
{
    return !(lhs == rhs);
}

} // namespace Lumen