#pragma once

#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Quaternion.hpp"
#include "Lumen/Math/Vector3.hpp"

namespace Lumen
{

constexpr Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

constexpr float Vector3::Length() const
{
    return Math::Sqrt(x * x + y * y + z * z);
}

constexpr float Vector3::LengthSqr() const
{
    return x * x + y * y + z * z;
}

constexpr Vector3 Vector3::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

constexpr float Vector3::Angle(const Vector3 &v1, const Vector3 &v2)
{
    float dot = Dot(v1, v2);
    float lengths = v1.Length() * v2.Length();

    if (lengths == 0.0f)
        return 0.0f;

    return Math::Acos(dot / lengths);
}

constexpr Vector3 Vector3::Clamp(const Vector3 &v, const Vector3 &min, const Vector3 &max)
{
    return {
        Math::Min(Math::Max(v.x, min.x), max.x),
        Math::Min(Math::Max(v.y, min.y), max.y),
        Math::Min(Math::Max(v.z, min.z), max.z),
    };
}

constexpr Vector3 Vector3::Clamp(const Vector3 &v, float min, float max)
{
    Vector3 result = v;

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

        result = v * scale;
    }

    return result;
}

constexpr Vector3 Vector3::Cross(const Vector3 &v1, const Vector3 &v2)
{
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x,
    };
}

constexpr float Vector3::Dot(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

constexpr float Vector3::Distance(const Vector3 &v1, const Vector3 &v2)
{
    return (v2 - v1).Length();
}

constexpr float Vector3::DistanceSqr(const Vector3 &v1, const Vector3 &v2)
{
    return (v2 - v1).LengthSqr();
}

constexpr Vector3 Vector3::Forward(const Vector3 &rotationEuler)
{
    float pitch = Math::Deg2Rad * rotationEuler.x;
    float yaw = Math::Deg2Rad * rotationEuler.y;

    return {
        cosf(pitch) * sinf(yaw),
        -sinf(pitch),
        cosf(pitch) * cosf(yaw),
    };
}

constexpr Vector3 Vector3::Lerp(const Vector3 &v1, const Vector3 &v2, float amount)
{
    return v1 + (v2 - v1) * Math::Clamp(amount, 0.0f, 1.0f);
}

constexpr Vector3 Vector3::Max(const Vector3 &v1, const Vector3 &v2)
{
    return {
        Math::Max(v1.x, v2.x),
        Math::Max(v1.y, v2.y),
        Math::Max(v1.z, v2.z),
    };
}

constexpr Vector3 Vector3::Min(const Vector3 &v1, const Vector3 &v2)
{
    return {
        Math::Min(v1.x, v2.x),
        Math::Min(v1.y, v2.y),
        Math::Min(v1.z, v2.z),
    };
}

constexpr void Vector3::OrthoNormalize(Vector3 &v1, Vector3 &v2)
{
    v2 = v2 - v1 * Dot(v2, v1) / Dot(v1, v1);
    v1 = v1.Normalized();
    v2 = v2.Normalized();
}

constexpr Vector3 Vector3::Reflect(const Vector3 &v, const Vector3 &normal)
{
    return v - normal * 2.0f * Dot(v, normal);
}

constexpr Vector3 Vector3::Refract(const Vector3 &v, const Vector3 &n, float r)
{
    float dot = Dot(v, n);
    return v - n * (dot * (1.0f + r) + r);
}

constexpr Vector3 Vector3::Right(const Vector3 &rotationEuler)
{
    float yaw = Math::Deg2Rad * rotationEuler.y - Math::Deg2Rad * 90.0f;

    return {
        sinf(yaw),
        0.0f,
        cosf(yaw),
    };
}

constexpr Vector3 Vector3::RotateByAxisAngle(const Vector3 &v, const Vector3 &axis,
                                             float angle)
{
    Vector3 axisNormalized = axis.Normalized();

    angle /= 2.0f;
    float a = Math::Sin(angle);
    float b = axisNormalized.x * a;
    float c = axisNormalized.y * a;
    float d = axisNormalized.z * a;
    a = Math::Cos(angle);
    Vector3 w = {b, c, d};

    Vector3 wv = Vector3::Cross(w, v);
    Vector3 wwv = Vector3::Cross(w, wv);

    return (2 * wv * a) + 2 * wwv;
}

constexpr Vector3 Vector3::RotateByQuaternion(const Vector3 &v, const Quaternion &q)
{
    Vector3 result;

    result.x = v.x * (q.x * q.x + q.w * q.w - q.y * q.y - q.z * q.z) +
               v.y * (2 * q.x * q.y - 2 * q.w * q.z) +
               v.z * (2 * q.x * q.z + 2 * q.w * q.y);
    result.y = v.x * (2 * q.w * q.z + 2 * q.x * q.y) +
               v.y * (q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z) +
               v.z * (-2 * q.w * q.x + 2 * q.y * q.z);
    result.z = v.x * (-2 * q.w * q.y + 2 * q.x * q.z) +
               v.y * (2 * q.w * q.x + 2 * q.y * q.z) +
               v.z * (q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z);

    return result;
}

constexpr Vector3 Vector3::Transform(const Vector3 &v, const Matrix4 &mat)
{
    return {
        mat[0] * v.x + mat[4] * v.y + mat[8] * v.z + mat[12],
        mat[1] * v.x + mat[5] * v.y + mat[9] * v.z + mat[13],
        mat[2] * v.x + mat[6] * v.y + mat[10] * v.z + mat[14],
    };
}

constexpr Vector3 Vector3::Up(const Vector3 &forward, const Vector3 &right)
{
    return Vector3::Cross(right, forward).Normalized();
}

constexpr Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
    return {
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
    };
}

constexpr Vector3 operator-(const Vector3 &vec)
{
    return {
        -vec.x,
        -vec.y,
        -vec.z,
    };
}

constexpr Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
    return {
        lhs.x - rhs.x,
        lhs.y - rhs.y,
        lhs.z - rhs.z,
    };
}

constexpr Vector3 operator*(const Vector3 &vec, float scalar)
{
    return {
        vec.x * scalar,
        vec.y * scalar,
        vec.z * scalar,
    };
}

constexpr Vector3 operator*(float scalar, const Vector3 &vec)
{
    return {
        vec.x * scalar,
        vec.y * scalar,
        vec.z * scalar,
    };
}

constexpr Vector3 operator/(const Vector3 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    return {
        vec.x / scalar,
        vec.y / scalar,
        vec.z / scalar,
    };
}

constexpr Vector3 operator/(float scalar, const Vector3 &vec)
{
    if (vec.x == 0.0f || vec.y == 0.0f || vec.z == 0.0f)
        return vec;

    return {
        scalar / vec.x,
        scalar / vec.y,
        scalar / vec.z,
    };
}

constexpr Vector3 &operator+=(Vector3 &lhs, const Vector3 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

constexpr Vector3 &operator-=(Vector3 &lhs, const Vector3 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

constexpr Vector3 &operator*=(Vector3 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;
    return vec;
}

constexpr Vector3 &operator/=(Vector3 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    vec.x /= scalar;
    vec.y /= scalar;
    vec.z /= scalar;
    return vec;
}

constexpr bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

constexpr bool operator!=(const Vector3 &lhs, const Vector3 &rhs)
{
    return !(lhs == rhs);
}

} // namespace Lumen