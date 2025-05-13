#include "Lumen/Math/Vector4.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"

#include "imgui.h"
#include "raymath.h"
#include <algorithm>
#include <cmath>

namespace Lumen
{

const Vector4 Vector4::One = {1, 1, 1, 1};
const Vector4 Vector4::Zero = {0, 0, 0, 0};

Vector4::Vector4(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f)
{
}

Vector4::Vector4(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f)
{
}

Vector4::Vector4(const ::Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{
}

Vector4::Vector4(const ::ImVec4 &vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{
}

Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

Vector4 operator-(const Vector4 &lhs, const Vector4 &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

Vector4 operator*(const Vector4 &vec, float scalar)
{
    return {vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar};
}

Vector4 operator*(float scalar, const Vector4 &vec)
{
    return {vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar};
}

Vector4 operator/(const Vector4 &vec, float scalar)
{
    if (scalar == 0.0f)
        return Vector4::Zero;

    return {vec.x / scalar, vec.y / scalar, vec.z / scalar, vec.w / scalar};
}

Vector4 operator/(float scalar, const Vector4 &vec)
{
    if (vec.x == 0.0f || vec.y == 0.0f || vec.z == 0.0f || vec.w == 0.0f)
        return Vector4::Zero;

    return {scalar / vec.x, scalar / vec.y, scalar / vec.z, scalar / vec.w};
}

Vector4 &operator+=(Vector4 &lhs, const Vector4 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

Vector4 &operator-=(Vector4 &lhs, const Vector4 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

Vector4 &operator*=(Vector4 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;
    vec.w *= scalar;
    return vec;
}

Vector4 &operator/=(Vector4 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    vec.x /= scalar;
    vec.y /= scalar;
    vec.z /= scalar;
    vec.w /= scalar;
    return vec;
}

bool operator==(const Vector4 &lhs, const Vector4 &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

bool operator!=(const Vector4 &lhs, const Vector4 &rhs)
{
    return !(lhs == rhs);
}

Vector4::operator ::Vector4() const
{
    return ::Vector4{x, y, z, w};
}

Vector4::operator ::ImVec4() const
{
    return ::ImVec4{x, y, z, w};
}

float Vector4::Length() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::LengthSqr() const
{
    return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

float Vector4::Distance(const Vector4 &v1, const Vector4 &v2)
{
    return (v1 - v2).Length();
}

float Vector4::DistanceSqr(const Vector4 &v1, const Vector4 &v2)
{
    return (v1 - v2).LengthSqr();
}

float Vector4::Dot(const Vector4 &v1, const Vector4 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Vector4 Vector4::Lerp(const Vector4 &v1, const Vector4 &v2, float amount)
{
    return v1 + (v2 - v1) * std::clamp(amount, 0.0f, 1.0f);
}

Vector4 Vector4::Max(const Vector4 &v1, const Vector4 &v2)
{
    return {std::fmax(v1.x, v2.x), std::fmax(v1.y, v2.y), std::fmax(v1.z, v2.z),
            std::fmax(v1.w, v2.w)};
}

Vector4 Vector4::Min(const Vector4 &v1, const Vector4 &v2)
{
    return {std::fmin(v1.x, v2.x), std::fmin(v1.y, v2.y), std::fmin(v1.z, v2.z),
            std::fmin(v1.w, v2.w)};
}

Vector4 Vector4::MoveTowards(const Vector4 &v, const Vector4 &target, float maxDist)
{
    Vector4 delta = target - v;
    float dist = delta.Length();

    if (dist <= maxDist || dist == 0.0f)
        return target;

    return v + delta.Normalized() * maxDist;
}

} // namespace Lumen