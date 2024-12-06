#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Quaternion.hpp"
#include <algorithm>
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Vector3 Vector3::One = {1, 1, 1};
const Vector3 Vector3::Zero = {0, 0, 0};

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3::Vector3(const ::Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

Vector3 operator*(const Vector3 &vec, float scalar)
{
    return {vec.x * scalar, vec.y * scalar, vec.z * scalar};
}

Vector3 operator*(float scalar, const Vector3 &vec)
{
    return {vec.x * scalar, vec.y * scalar, vec.z * scalar};
}

Vector3 operator/(const Vector3 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    return {vec.x / scalar, vec.y / scalar, vec.z / scalar};
}

Vector3 operator/(float scalar, const Vector3 &vec)
{
    if (vec.x == 0.0f || vec.y == 0.0f || vec.z == 0.0f)
        return vec;

    return {scalar / vec.x, scalar / vec.y, scalar / vec.z};
}

Vector3 &operator+=(Vector3 &lhs, const Vector3 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

Vector3 &operator-=(Vector3 &lhs, const Vector3 &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

Vector3 &operator*=(Vector3 &vec, float scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;
    return vec;
}

Vector3 &operator/=(Vector3 &vec, float scalar)
{
    if (scalar == 0.0f)
        return vec;

    vec.x /= scalar;
    vec.y /= scalar;
    vec.z /= scalar;
    return vec;
}

bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

bool operator!=(const Vector3 &lhs, const Vector3 &rhs)
{
    return !(lhs == rhs);
}

Vector3::operator ::Vector3() const
{
    return {x, y, z};
}

float Vector3::Length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

float Vector3::LengthSqr() const
{
    return x * x + y * y + z * z;
}

Vector3 Vector3::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

float Vector3::Angle(const Vector3 &v1, const Vector3 &v2)
{
    float dot = Dot(v1, v2);
    float lengths = v1.Length() * v2.Length();

    if (lengths == 0.0f)
        return 0.0f;

    return std::acos(dot / lengths);
}

Vector3 Vector3::Clamp(const Vector3 &v, const Vector3 &min, const Vector3 &max)
{
    return {std::fmin(std::fmax(v.x, min.x), max.x),
            std::fmin(std::fmax(v.y, min.y), max.y),
            std::fmin(std::fmax(v.z, min.z), max.z)};
}

Vector3 Vector3::Clamp(const Vector3 &v, float min, float max)
{
    Vector3 result = v;

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

        result = v * scale;
    }

    return result;
}

Vector3 Vector3::Cross(const Vector3 &v1, const Vector3 &v2)
{
    return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x};
}

float Vector3::Dot(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Vector3::Distance(const Vector3 &v1, const Vector3 &v2)
{
    return (v2 - v1).Length();
}

float Vector3::DistanceSqr(const Vector3 &v1, const Vector3 &v2)
{
    return (v2 - v1).LengthSqr();
}

Vector3 Vector3::Lerp(const Vector3 &v1, const Vector3 &v2, float amount)
{
    return v1 + (v2 - v1) * std::clamp(amount, 0.0f, 1.0f);
}

Vector3 Vector3::Max(const Vector3 &v1, const Vector3 &v2)
{
    return {std::fmax(v1.x, v2.x), std::fmax(v1.y, v2.y), std::fmax(v1.z, v2.z)};
}

Vector3 Vector3::Min(const Vector3 &v1, const Vector3 &v2)
{
    return {std::fmin(v1.x, v2.x), std::fmin(v1.y, v2.y), std::fmin(v1.z, v2.z)};
}

void Vector3::OrthoNormalize(Vector3 &v1, Vector3 &v2)
{
    v2 = v2 - v1 * Dot(v2, v1) / Dot(v1, v1);
    v1 = v1.Normalized();
    v2 = v2.Normalized();
}

Vector3 Vector3::Reflect(const Vector3 &v, const Vector3 &normal)
{
    return v - normal * 2.0f * Dot(v, normal);
}

Vector3 Vector3::Refract(const Vector3 &v, const Vector3 &n, float r)
{
    float dot = Dot(v, n);
    return v - n * (dot * (1.0f + r) + r);
}

Vector3 Vector3::RotateByAxisAngle(const Vector3 &v, const Vector3 &axis, float angle)
{
    Vector3 axisNormalized = axis.Normalized();

    angle /= 2.0f;
    float a = sinf(angle);
    float b = axisNormalized.x * a;
    float c = axisNormalized.y * a;
    float d = axisNormalized.z * a;
    a = cosf(angle);
    Vector3 w = {b, c, d};

    Vector3 wv = Vector3::Cross(w, v);
    Vector3 wwv = Vector3::Cross(w, wv);

    return (2 * wv * a) + 2 * wwv;
}

Vector3 Vector3::RotateByQuaternion(const Vector3 &v, const Quaternion &q)
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

Vector3 Vector3::Transform(const Vector3 &v, const Matrix4 &mat)
{
    return {mat[0] * v.x + mat[4] * v.y + mat[8] * v.z + mat[12],
            mat[1] * v.x + mat[5] * v.y + mat[9] * v.z + mat[13],
            mat[2] * v.x + mat[6] * v.y + mat[10] * v.z + mat[14]};
}

} // namespace Lumen