#pragma once

struct Vector4;

namespace Lumen
{

class Vector3;
class Matrix4;

class Quaternion
{
public:
    static const Quaternion Identity;

public:
    float x, y, z, w;

    constexpr Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

    Quaternion(const ::Vector4 &quaternion);

    [[nodiscard]] constexpr Quaternion Inverted() const;
    [[nodiscard]] constexpr float Length() const;
    [[nodiscard]] constexpr Quaternion Normalized() const;
    [[nodiscard]] constexpr Matrix4 ToMatrix() const;
    [[nodiscard]] constexpr Vector3 ToEuler() const;
    constexpr void ToAxisAngle(Vector3 &outAxis, float &outAngle);
    [[nodiscard]] constexpr Quaternion Transformed(const Matrix4 &mat) const;

    static constexpr Quaternion FromAxisAngle(const Vector3 &axis, float angle);
    static constexpr Quaternion FromEuler(float pitch, float yaw, float roll);
    static constexpr Quaternion FromMatrix(const Matrix4 &mat);
    static constexpr Quaternion FromVector3ToVector3(const Vector3 &from,
                                                     const Vector3 &to);
    static constexpr Quaternion Lerp(const Quaternion &q1, const Quaternion &q2,
                                     float amount);
    static constexpr Quaternion Nlerp(const Quaternion &q1, const Quaternion &q2,
                                      float amount);
    static constexpr Quaternion Slerp(const Quaternion &q1, const Quaternion &q2,
                                      float amount);

    friend constexpr Quaternion operator+(const Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion operator+(const Quaternion &lhs, float value);
    friend constexpr Quaternion operator-(const Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion operator-(const Quaternion &lhs, float value);
    friend constexpr Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion operator*(const Quaternion &lhs, float scalar);
    friend constexpr Quaternion operator*(float scalar, const Quaternion &rhs);
    friend constexpr Quaternion operator/(const Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion &operator+=(Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion &operator-=(Quaternion &lhs, const Quaternion &rhs);
    friend constexpr Quaternion &operator*=(Quaternion &lhs, float scalar);
    friend constexpr Quaternion &operator/=(Quaternion &lhs, float scalar);
    friend constexpr bool operator==(const Quaternion &lhs, const Quaternion &rhs);
    friend constexpr bool operator!=(const Quaternion &lhs, const Quaternion &rhs);
    operator ::Vector4() const;
};

} // namespace Lumen

#include "Lumen/Math/Quaternion.inl"