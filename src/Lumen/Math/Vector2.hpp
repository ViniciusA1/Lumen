#pragma once

struct Vector2;

namespace Lumen
{

class Vector2
{
public:
    static const Vector2 Down;
    static const Vector2 Left;
    static const Vector2 Right;
    static const Vector2 Up;
    static const Vector2 Zero;
    static const Vector2 One;

public:
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f);

    inline Vector2 operator+(const Vector2 &other) const;
    inline Vector2 operator-(const Vector2 &other) const;
    inline Vector2 operator*(float scalar) const;
    inline Vector2 operator/(float scalar) const;
    inline Vector2 &operator+=(const Vector2 &other);
    inline Vector2 &operator-=(const Vector2 &other);
    inline Vector2 &operator*=(float scalar);
    inline Vector2 &operator/=(float scalar);
    inline bool operator==(const Vector2 &other) const;
    inline bool operator!=(const Vector2 &other) const;

    [[nodiscard]] float Magnitude() const;
    [[nodiscard]] float SqrMagnitude() const;
    [[nodiscard]] Vector2 Normalized() const;
    void Normalize();

    static float Angle(const Vector2 &from, const Vector2 &to);
    static float Distance(const Vector2 &v1, const Vector2 &v2);
    static float Dot(const Vector2 &v1, const Vector2 &v2);
    static Vector2 Lerp(const Vector2 &a, const Vector2 &b, float t);
    static Vector2 LerpUnclamped(const Vector2 &a, const Vector2 &b, float t);
    static Vector2 Max(const Vector2 &v1, const Vector2 &v2);
    static Vector2 Min(const Vector2 &v1, const Vector2 &v2);
    static Vector2 Perpendicular(const Vector2 &v);
    static Vector2 Reflect(const Vector2 &direction, const Vector2 &normal);
    static Vector2 Scale(const Vector2 &v1, const Vector2 &v2);
    static float SignedAngle(const Vector2 &from, const Vector2 &to);

    [[nodiscard]] ::Vector2 ToRaylib() const;
};

Vector2 Vector2::operator+(const Vector2 &other) const
{
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2 &other) const
{
    return {x - other.x, y - other.y};
}

Vector2 Vector2::operator*(float scalar) const
{
    return {x * scalar, y * scalar};
}

Vector2 Vector2::operator/(float scalar) const
{
    return {x / scalar, y / scalar};
}

Vector2 &Vector2::operator+=(const Vector2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 &Vector2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2 &Vector2::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2 &other) const
{
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2 &other) const
{
    return !(*this == other);
}

} // namespace Lumen