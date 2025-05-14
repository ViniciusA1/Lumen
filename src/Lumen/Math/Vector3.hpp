#pragma once

struct Vector3;

namespace Lumen
{

class Vector2;
class Vector4;
class Matrix4;
class Quaternion;

class Vector3
{
public:
    static const Vector3 One;
    static const Vector3 Zero;

public:
    float x, y, z;

    constexpr Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    Vector3(const Vector2 &vec);
    Vector3(const Vector4 &vec);
    Vector3(const ::Vector3 &vec);

    [[nodiscard]] constexpr float Length() const;
    [[nodiscard]] constexpr float LengthSqr() const;
    [[nodiscard]] constexpr Vector3 Normalized() const;

    static constexpr float Angle(const Vector3 &v1, const Vector3 &v2);
    static constexpr Vector3 Clamp(const Vector3 &v, const Vector3 &min,
                                   const Vector3 &max);
    static constexpr Vector3 Clamp(const Vector3 &v, float min, float max);
    static constexpr Vector3 Cross(const Vector3 &v1, const Vector3 &v2);
    static constexpr float Dot(const Vector3 &v1, const Vector3 &v2);
    static constexpr float Distance(const Vector3 &v1, const Vector3 &v2);
    static constexpr float DistanceSqr(const Vector3 &v1, const Vector3 &v2);
    static constexpr Vector3 Lerp(const Vector3 &v1, const Vector3 &v2, float amount);
    static constexpr Vector3 Max(const Vector3 &v1, const Vector3 &v2);
    static constexpr Vector3 Min(const Vector3 &v1, const Vector3 &v2);
    static constexpr void OrthoNormalize(Vector3 &v1, Vector3 &v2);
    static constexpr Vector3 Reflect(const Vector3 &v, const Vector3 &normal);
    static constexpr Vector3 Refract(const Vector3 &v, const Vector3 &n, float r);
    static constexpr Vector3 RotateByAxisAngle(const Vector3 &v, const Vector3 &axis,
                                               float angle);
    static constexpr Vector3 RotateByQuaternion(const Vector3 &v, const Quaternion &q);
    static constexpr Vector3 Transform(const Vector3 &v, const Matrix4 &mat);

    friend constexpr Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
    friend constexpr Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
    friend constexpr Vector3 operator*(const Vector3 &vec, float scalar);
    friend constexpr Vector3 operator*(float scalar, const Vector3 &vec);
    friend constexpr Vector3 operator/(const Vector3 &vec, float scalar);
    friend constexpr Vector3 operator/(float scalar, const Vector3 &vec);
    friend constexpr Vector3 &operator+=(Vector3 &lhs, const Vector3 &rhs);
    friend constexpr Vector3 &operator-=(Vector3 &lhs, const Vector3 &rhs);
    friend constexpr Vector3 &operator*=(Vector3 &vec, float scalar);
    friend constexpr Vector3 &operator/=(Vector3 &vec, float scalar);
    friend constexpr bool operator==(const Vector3 &lhs, const Vector3 &rhs);
    friend constexpr bool operator!=(const Vector3 &lhs, const Vector3 &rhs);
    operator ::Vector3() const;
};

} // namespace Lumen

#include "Lumen/Math/Vector3.inl"

namespace Lumen
{

inline constexpr Vector3 Vector3::One{1.0f, 1.0f, 1.0f};
inline constexpr Vector3 Vector3::Zero{0.0f, 0.0f, 0.0f};

} // namespace Lumen