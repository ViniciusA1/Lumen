#pragma once

struct Vector3;

namespace Lumen
{

class Matrix4;
class Quaternion;

class Vector3
{
public:
    static const Vector3 One;
    static const Vector3 Zero;

public:
    float x, y, z;

    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    Vector3(const ::Vector3 &vec);

    friend Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
    friend Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
    friend Vector3 operator*(const Vector3 &vec, float scalar);
    friend Vector3 operator*(float scalar, const Vector3 &vec);
    friend Vector3 operator/(const Vector3 &vec, float scalar);
    friend Vector3 operator/(float scalar, const Vector3 &vec);
    friend Vector3 &operator+=(Vector3 &lhs, const Vector3 &rhs);
    friend Vector3 &operator-=(Vector3 &lhs, const Vector3 &rhs);
    friend Vector3 &operator*=(Vector3 &vec, float scalar);
    friend Vector3 &operator/=(Vector3 &vec, float scalar);
    friend bool operator==(const Vector3 &lhs, const Vector3 &rhs);
    friend bool operator!=(const Vector3 &lhs, const Vector3 &rhs);
    operator ::Vector3() const;

    [[nodiscard]] float Length() const;
    [[nodiscard]] float LengthSqr() const;
    [[nodiscard]] Vector3 Normalized() const;

    static float Angle(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Clamp(const Vector3 &v, const Vector3 &min, const Vector3 &max);
    static Vector3 Clamp(const Vector3 &v, float min, float max);
    static Vector3 Cross(const Vector3 &v1, const Vector3 &v2);
    static float Dot(const Vector3 &v1, const Vector3 &v2);
    static float Distance(const Vector3 &v1, const Vector3 &v2);
    static float DistanceSqr(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Lerp(const Vector3 &v1, const Vector3 &v2, float amount);
    static Vector3 Max(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Min(const Vector3 &v1, const Vector3 &v2);
    static void OrthoNormalize(Vector3 &v1, Vector3 &v2);
    static Vector3 Reflect(const Vector3 &v, const Vector3 &normal);
    static Vector3 Refract(const Vector3 &v, const Vector3 &n, float r);
    static Vector3 RotateByAxisAngle(const Vector3 &v, const Vector3 &axis, float angle);
    static Vector3 RotateByQuaternion(const Vector3 &v, const Quaternion &q);
    static Vector3 Transform(const Vector3 &v, const Matrix4 &mat);
};

} // namespace Lumen