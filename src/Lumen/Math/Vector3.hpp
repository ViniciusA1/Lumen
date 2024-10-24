#pragma once

struct Vector3;

namespace Lumen
{

class Vector3
{
public:
    static const Vector3 Down;
    static const Vector3 Left;
    static const Vector3 Right;
    static const Vector3 Up;
    static const Vector3 Back;
    static const Vector3 Forward;
    static const Vector3 Zero;
    static const Vector3 One;

public:
    float x, y, z;

    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    inline Vector3 operator+(const Vector3 &other) const;
    inline Vector3 operator-(const Vector3 &other) const;
    inline Vector3 operator*(float scalar) const;
    inline Vector3 operator/(float scalar) const;
    inline Vector3 &operator+=(const Vector3 &other);
    inline Vector3 &operator-=(const Vector3 &other);
    inline Vector3 &operator*=(float scalar);
    inline Vector3 &operator/=(float scalar);
    inline bool operator==(const Vector3 &other) const;
    inline bool operator!=(const Vector3 &other) const;

    [[nodiscard]] float Magnitude() const;
    [[nodiscard]] float SqrMagnitude() const;
    [[nodiscard]] Vector3 Normalized() const;
    void Normalize();

    static float Angle(const Vector3 &from, const Vector3 &to);
    static Vector3 ClampMagnitude(const Vector3 &vector, float maxLength);
    static Vector3 Cross(const Vector3 &v1, const Vector3 &v2);
    static float Distance(const Vector3 &a, const Vector3 &b);
    static float Dot(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Lerp(const Vector3 &a, const Vector3 &b, float t);
    static Vector3 LerpUnclamped(const Vector3 &a, const Vector3 &b, float t);
    static Vector3 Max(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Min(const Vector3 &v1, const Vector3 &v2);
    static Vector3 MoveTowards(const Vector3 &current, const Vector3 &target,
                               float maxDistance);
    static void OrthoNormalize(Vector3 &normal, Vector3 &tangent);
    static Vector3 Project(const Vector3 &vector, const Vector3 &onNormal);
    static Vector3 ProjectOnPlane(const Vector3 &vector, const Vector3 &planeNormal);
    static Vector3 Reflect(const Vector3 &direction, const Vector3 &normal);
    static Vector3 RotateTowards(const Vector3 &current, const Vector3 &target,
                                 float maxRadiansDelta, float maxMagnitudeDelta);
    static Vector3 Scale(const Vector3 &a, const Vector3 &b);
    static float SignedAngle(const Vector3 &from, const Vector3 &to, const Vector3 &axis);
    static Vector3 Slerp(const Vector3 &a, const Vector3 &b, float t);
    static Vector3 SlerpUnclamped(const Vector3 &a, const Vector3 &b, float t);
    static Vector3 SmoothDamp(const Vector3 &current, const Vector3 &target,
                              Vector3 &currentVelocity, float smoothTime, float maxSpeed,
                              float deltaTime);

    [[nodiscard]] ::Vector3 ToRaylib() const;
};

Vector3 Vector3::operator+(const Vector3 &other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator*(float scalar) const
{
    return {x * scalar, y * scalar, z * scalar};
}

Vector3 Vector3::operator/(float scalar) const
{
    return {x / scalar, y / scalar, z / scalar};
}

Vector3 &Vector3::operator+=(const Vector3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 &Vector3::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3 &Vector3::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

bool Vector3::operator==(const Vector3 &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3 &other) const
{
    return !(*this == other);
}

} // namespace Lumen