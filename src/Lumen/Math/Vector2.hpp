#pragma once

struct Vector2;
struct ImVec2;
struct b2Vec2;

namespace Lumen
{

class Vector3;
class Vector4;
class Matrix4;

class Vector2
{
public:
    static const Vector2 One;
    static const Vector2 Zero;

public:
    float x, y;

    constexpr Vector2(float x = 0.0f, float y = 0.0f);

    Vector2(const Vector3 &vec);
    Vector2(const Vector4 &vec);
    Vector2(const ::Vector2 &vec);
    Vector2(const ::ImVec2 &vec);
    Vector2(const ::b2Vec2 &vec);

    [[nodiscard]] constexpr float Length() const;
    [[nodiscard]] constexpr float LengthSqr() const;
    [[nodiscard]] constexpr Vector2 Normalized() const;

    static constexpr float Angle(const Vector2 &v1, const Vector2 &v2);
    static constexpr Vector2 Clamp(const Vector2 &v, const Vector2 &min,
                                   const Vector2 &max);
    static constexpr Vector2 Clamp(const Vector2 &v, float min, float max);
    static constexpr float Distance(const Vector2 &v1, const Vector2 &v2);
    static constexpr float DistanceSqr(const Vector2 &v1, const Vector2 &v2);
    static constexpr float Dot(const Vector2 &v1, const Vector2 &v2);
    static constexpr Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, float t);
    static constexpr Vector2 MoveTowards(const Vector2 &v, const Vector2 &target,
                                         float maxDist);
    static constexpr Vector2 Reflect(const Vector2 &v, const Vector2 &normal);
    static constexpr Vector2 Rotate(const Vector2 &v, float angle);
    static constexpr Vector2 Transform(const Vector2 &v, const Matrix4 &mat);

    friend constexpr Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs);
    friend constexpr Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs);
    friend constexpr Vector2 operator*(const Vector2 &vec, float scalar);
    friend constexpr Vector2 operator*(float scalar, const Vector2 &vec);
    friend constexpr Vector2 operator/(const Vector2 &vec, float scalar);
    friend constexpr Vector2 operator/(float scalar, const Vector2 &vec);
    friend constexpr Vector2 &operator+=(Vector2 &lhs, const Vector2 &rhs);
    friend constexpr Vector2 &operator-=(Vector2 &lhs, const Vector2 &rhs);
    friend constexpr Vector2 &operator*=(Vector2 &vec, float scalar);
    friend constexpr Vector2 &operator/=(Vector2 &vec, float scalar);
    friend constexpr bool operator==(const Vector2 &lhs, const Vector2 &rhs);
    friend constexpr bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
    operator ::Vector2() const;
    operator ::ImVec2() const;
    operator ::b2Vec2() const;
};

} // namespace Lumen

#include "Lumen/Math/Vector2.inl"

namespace Lumen
{

inline constexpr Vector2 Vector2::One{1.0f, 1.0f};
inline constexpr Vector2 Vector2::Zero{0.0f, 0.0f};

} // namespace Lumen