#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Vector4.hpp"

#include "box2d/math_functions.h"
#include "imgui.h"
#include "raymath.h"

#include <algorithm>
#include <cmath>

namespace Lumen
{

const Vector2 Vector2::One = {1, 1};
const Vector2 Vector2::Zero = {0, 0};

Vector2::Vector2(const Vector3 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const Vector4 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::Vector2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::ImVec2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::b2Vec2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Vector2 operator*(const Vector2 &vec, float scalar)
{
    return {vec.x * scalar, vec.y * scalar};
}

Vector2 operator*(float scalar, const Vector2 &vec)
{
    return vec * scalar;
}

Vector2 operator/(const Vector2 &vec, float scalar)
{
    if (scalar == 0)
        return vec;
    return {vec.x / scalar, vec.y / scalar};
}

Vector2 operator/(float scalar, const Vector2 &vec)
{
    if (vec.x == 0 || vec.y == 0)
        return vec;
    return {scalar / vec.x, scalar / vec.y};
}

Vector2 &operator+=(Vector2 &lhs, const Vector2 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

Vector2 &operator-=(Vector2 &lhs, const Vector2 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

Vector2 &operator*=(Vector2 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    return vec;
}

Vector2 &operator/=(Vector2 &vec, float scalar)
{
    if (scalar == 0)
        return vec;
    vec.x /= scalar;
    vec.y /= scalar;
    return vec;
}

bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
    return !(lhs == rhs);
}

Vector2::operator ::Vector2() const
{
    return {x, y};
}

Vector2::operator ::ImVec2() const
{
    return {x, y};
}

Vector2::operator ::b2Vec2() const
{
    return {x, y};
}

float Vector2::Length() const
{
    return std::sqrt(x * x + y * y);
}

float Vector2::LengthSqr() const
{
    return x * x + y * y;
}

Vector2 Vector2::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

float Vector2::Angle(const Vector2 &v1, const Vector2 &v2)
{
    float dot = Dot(v1, v2);
    float lengths = v1.Length() * v2.Length();

    if (lengths == 0.0f)
        return 0.0f;

    return std::acos(dot / lengths);
}

Vector2 Vector2::Clamp(const Vector2 &v, const Vector2 &min, const Vector2 &max)
{
    return {std::fmax(min.x, std::fmin(v.x, max.x)),
            std::fmax(min.y, std::fmin(v.y, max.y))};
}

Vector2 Vector2::Clamp(const Vector2 &v, float min, float max)
{
    Vector2 result = v;
    float length = v.LengthSqr();

    if (length > 0.0f)
    {
        length = sqrtf(length);

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

float Vector2::Distance(const Vector2 &v1, const Vector2 &v2)
{
    return (v1 - v2).Length();
}

float Vector2::DistanceSqr(const Vector2 &v1, const Vector2 &v2)
{
    return (v1 - v2).LengthSqr();
}

float Vector2::Dot(const Vector2 &v1, const Vector2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vector2 Vector2::Lerp(const Vector2 &v1, const Vector2 &v2, float amount)
{
    return v1 + (v2 - v1) * std::clamp(amount, 0.0f, 1.0f);
}

Vector2 Vector2::MoveTowards(const Vector2 &v, const Vector2 &target, float maxDist)
{
    Vector2 delta = target - v;
    float dist = delta.Length();

    if (dist <= maxDist || dist == 0.0f)
        return target;

    return v + delta.Normalized() * maxDist;
}

Vector2 Vector2::Reflect(const Vector2 &v, const Vector2 &normal)
{
    return v - normal * 2.0f * Dot(v, normal);
}

Vector2 Vector2::Rotate(const Vector2 &v, float angle)
{
    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);
    return {v.x * cosAngle - v.y * sinAngle, v.x * sinAngle + v.y * cosAngle};
}

Vector2 Vector2::Transform(const Vector2 &v, const Matrix4 &mat)
{
    return {mat[0] * v.x + mat[4] * v.y + mat[12], mat[1] * v.x + mat[5] * v.y + mat[13]};
}

} // namespace Lumen