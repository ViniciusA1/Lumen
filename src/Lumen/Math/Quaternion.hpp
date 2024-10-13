#pragma once

#include "Lumen/Math/Vector3.hpp"

struct Vector4;

namespace Lumen
{

class Quaternion
{
public:
    static const Quaternion Identity;

public:
    float x, y, z, w;

    Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

    inline Quaternion operator*(const Quaternion &rhs) const;
    inline bool operator==(const Quaternion &rhs) const;

    [[nodiscard]] Vector3 EulerAngles() const;
    [[nodiscard]] Quaternion Normalized() const;

    void Set(float newX, float newY, float newZ, float newW);
    void SetFromToRotation(const Vector3 &fromDirection, const Vector3 &toDirection);
    void SetLookRotation(const Vector3 &forward, const Vector3 &upwards = Vector3::Up);
    void ToAngleAxis(float &angle, Vector3 &axis) const;

    static float Angle(const Quaternion &a, const Quaternion &b);
    static Quaternion AngleAxis(float angle, const Vector3 &axis);
    static float Dot(const Quaternion &a, const Quaternion &b);
    static Quaternion Euler(float x, float y, float z);
    static Quaternion FromToRotation(const Vector3 &fromDirection,
                                     const Vector3 &toDirection);
    static Quaternion Inverse(const Quaternion &rotation);
    static Quaternion Lerp(const Quaternion &a, const Quaternion &b, float t);
    static Quaternion LerpUnclamped(const Quaternion &a, const Quaternion &b, float t);
    static Quaternion LookRotation(const Vector3 &forward,
                                   const Vector3 &upwards = Vector3(0, 1, 0));
    static Quaternion Normalize(const Quaternion &q);
    static Quaternion RotateTowards(const Quaternion &from, const Quaternion &to,
                                    float maxAngle);
    static Quaternion Slerp(const Quaternion &a, const Quaternion &b, float t);
    static Quaternion SlerpUnclamped(const Quaternion &a, const Quaternion &b, float t);

    [[nodiscard]] ::Vector4 ToRaylib() const;
};

Quaternion Quaternion::operator*(const Quaternion &rhs) const
{
    return {w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y,
            w * rhs.y + y * rhs.w + z * rhs.x - x * rhs.z,
            w * rhs.z + z * rhs.w + x * rhs.y - y * rhs.x,
            w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z};
}

bool Quaternion::operator==(const Quaternion &rhs) const
{
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

} // namespace Lumen