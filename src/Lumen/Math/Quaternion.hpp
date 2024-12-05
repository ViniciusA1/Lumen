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

    Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

    [[nodiscard]] Quaternion Inverted() const;
    [[nodiscard]] float Length() const;
    [[nodiscard]] Quaternion Normalized() const;
    [[nodiscard]] Matrix4 ToMatrix() const;
    [[nodiscard]] Vector3 ToEuler() const;
    void ToAxisAngle(Vector3 &outAxis, float &outAngle);
    [[nodiscard]] Quaternion Transformed(const Matrix4 &mat) const;

    static Quaternion FromAxisAngle(const Vector3 &axis, float angle);
    static Quaternion FromEuler(float pitch, float yaw, float roll);
    static Quaternion FromMatrix(const Matrix4 &mat);
    static Quaternion FromVector3ToVector3(const Vector3 &from, const Vector3 &to);
    static Quaternion Lerp(const Quaternion &q1, const Quaternion &q2, float amount);
    static Quaternion Nlerp(const Quaternion &q1, const Quaternion &q2, float amount);
    static Quaternion Slerp(const Quaternion &q1, const Quaternion &q2, float amount);

    friend Quaternion operator+(const Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion operator+(const Quaternion &lhs, float value);
    friend Quaternion operator-(const Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion operator-(const Quaternion &lhs, float value);
    friend Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion operator*(const Quaternion &lhs, float scalar);
    friend Quaternion operator*(float scalar, const Quaternion &rhs);
    friend Quaternion operator/(const Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion &operator+=(Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion &operator-=(Quaternion &lhs, const Quaternion &rhs);
    friend Quaternion &operator*=(Quaternion &lhs, float scalar);
    friend Quaternion &operator/=(Quaternion &lhs, float scalar);
    friend bool operator==(const Quaternion &lhs, const Quaternion &rhs);
    friend bool operator!=(const Quaternion &lhs, const Quaternion &rhs);
    operator ::Vector4() const;
};

} // namespace Lumen