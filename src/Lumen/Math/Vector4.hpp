#pragma once

struct Vector4;

namespace Lumen
{

class Vector4
{
public:
    static const Vector4 One;
    static const Vector4 Zero;

public:
    float x, y, z, w;

    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
    Vector4(const ::Vector4 &vec);

    friend Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs);
    friend Vector4 operator-(const Vector4 &lhs, const Vector4 &rhs);
    friend Vector4 operator*(const Vector4 &vec, float scalar);
    friend Vector4 operator*(float scalar, const Vector4 &vec);
    friend Vector4 operator/(const Vector4 &vec, float scalar);
    friend Vector4 operator/(float scalar, const Vector4 &vec);
    friend Vector4 &operator+=(Vector4 &lhs, const Vector4 &rhs);
    friend Vector4 &operator-=(Vector4 &lhs, const Vector4 &rhs);
    friend Vector4 &operator*=(Vector4 &vec, float scalar);
    friend Vector4 &operator/=(Vector4 &vec, float scalar);
    friend bool operator==(const Vector4 &lhs, const Vector4 &rhs);
    friend bool operator!=(const Vector4 &lhs, const Vector4 &rhs);
    operator ::Vector4() const;

    [[nodiscard]] float Length() const;
    [[nodiscard]] float LengthSqr() const;
    [[nodiscard]] Vector4 Normalized() const;

    static float Distance(const Vector4 &v1, const Vector4 &v2);
    static float DistanceSqr(const Vector4 &v1, const Vector4 &v2);
    static float Dot(const Vector4 &v1, const Vector4 &v2);
    static Vector4 Lerp(const Vector4 &v1, const Vector4 &v2, float amount);
    static Vector4 Max(const Vector4 &v1, const Vector4 &v2);
    static Vector4 Min(const Vector4 &v1, const Vector4 &v2);
    static Vector4 MoveTowards(const Vector4 &v, const Vector4 &target, float maxDist);
};

} // namespace Lumen