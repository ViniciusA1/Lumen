#pragma once

struct Vector2;

namespace Lumen
{

class Matrix4;

class Vector2
{
public:
    static const Vector2 One;
    static const Vector2 Zero;

public:
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f);

    friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 operator*(const Vector2 &vec, float scalar);
    friend Vector2 operator*(float scalar, const Vector2 &vec);
    friend Vector2 operator/(const Vector2 &vec, float scalar);
    friend Vector2 operator/(float scalar, const Vector2 &vec);
    friend Vector2 &operator+=(Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 &operator-=(Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 &operator*=(Vector2 &vec, float scalar);
    friend Vector2 &operator/=(Vector2 &vec, float scalar);
    friend bool operator==(const Vector2 &lhs, const Vector2 &rhs);
    friend bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
    operator ::Vector2() const;

    [[nodiscard]] float Length() const;
    [[nodiscard]] float LengthSqr() const;
    [[nodiscard]] Vector2 Normalized() const;

    static float Angle(const Vector2 &v1, const Vector2 &v2);
    static Vector2 Clamp(const Vector2 &v, const Vector2 &min, const Vector2 &max);
    static Vector2 Clamp(const Vector2 &v, float min, float max);
    static float Distance(const Vector2 &v1, const Vector2 &v2);
    static float DistanceSqr(const Vector2 &v1, const Vector2 &v2);
    static float Dot(const Vector2 &v1, const Vector2 &v2);
    static Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, float amount);
    static Vector2 MoveTowards(const Vector2 &v, const Vector2 &target, float maxDist);
    static Vector2 Reflect(const Vector2 &v, const Vector2 &normal);
    static Vector2 Rotate(const Vector2 &v, float angle);
    static Vector2 Transform(const Vector2 &v, const Matrix4 &mat);
};

} // namespace Lumen