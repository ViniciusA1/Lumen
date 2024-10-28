#pragma once

struct Vector4;

namespace Lumen
{

class Vector4
{
public:
    static const Vector4 Zero;
    static const Vector4 One;

public:
    float x, y, z, w;

    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);

    inline Vector4 operator+(const Vector4 &other) const;
    inline Vector4 operator-(const Vector4 &other) const;
    inline Vector4 operator*(float scalar) const;
    inline Vector4 operator/(float scalar) const;
    inline Vector4 &operator+=(const Vector4 &other);
    inline Vector4 &operator-=(const Vector4 &other);
    inline Vector4 &operator*=(float scalar);
    inline Vector4 &operator/=(float scalar);
    inline bool operator==(const Vector4 &other) const;
    inline bool operator!=(const Vector4 &other) const;
    operator ::Vector4() const;

    [[nodiscard]] float Magnitude() const;
    [[nodiscard]] float SqrMagnitude() const;
    [[nodiscard]] Vector4 Normalized() const;
    void Normalize();

    static float Distance(const Vector4 &a, const Vector4 &b);
    static float Dot(const Vector4 &a, const Vector4 &b);
    static Vector4 Lerp(const Vector4 &a, const Vector4 &b, float t);
    static Vector4 LerpUnclamped(const Vector4 &a, const Vector4 &b, float t);
    static Vector4 Max(const Vector4 &a, const Vector4 &b);
    static Vector4 Min(const Vector4 &a, const Vector4 &b);
    static Vector4 MoveTowards(const Vector4 &current, const Vector4 &target,
                               float maxDistanceDelta);
    static Vector4 Normalize(const Vector4 &vec);
    static Vector4 Project(const Vector4 &a, const Vector4 &b);
    static Vector4 Scale(const Vector4 &a, const Vector4 &b);
};

Vector4 Vector4::operator+(const Vector4 &other) const
{
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

Vector4 Vector4::operator-(const Vector4 &other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

Vector4 Vector4::operator*(float scalar) const
{
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}

Vector4 Vector4::operator/(float scalar) const
{
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}

Vector4 &Vector4::operator+=(const Vector4 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vector4 &Vector4::operator-=(const Vector4 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vector4 &Vector4::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

Vector4 &Vector4::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

bool Vector4::operator==(const Vector4 &other) const
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4::operator!=(const Vector4 &other) const
{
    return !(*this == other);
}

} // namespace Lumen