#pragma once

struct Vector4;
struct ImVec4;

namespace Lumen
{

class Vector2;
class Vector3;

class Vector4
{
public:
    static const Vector4 One;
    static const Vector4 Zero;

public:
    float x, y, z, w;

    constexpr Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);

    Vector4(const Vector2 &vec);
    Vector4(const Vector3 &vec);
    Vector4(const ::Vector4 &vec);
    Vector4(const ::ImVec4 &vec);

    friend constexpr Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs);
    friend constexpr Vector4 operator-(const Vector4 &lhs, const Vector4 &rhs);
    friend constexpr Vector4 operator*(const Vector4 &vec, float scalar);
    friend constexpr Vector4 operator*(float scalar, const Vector4 &vec);
    friend constexpr Vector4 operator/(const Vector4 &vec, float scalar);
    friend constexpr Vector4 operator/(float scalar, const Vector4 &vec);
    friend constexpr Vector4 &operator+=(Vector4 &lhs, const Vector4 &rhs);
    friend constexpr Vector4 &operator-=(Vector4 &lhs, const Vector4 &rhs);
    friend constexpr Vector4 &operator*=(Vector4 &vec, float scalar);
    friend constexpr Vector4 &operator/=(Vector4 &vec, float scalar);
    friend constexpr bool operator==(const Vector4 &lhs, const Vector4 &rhs);
    friend constexpr bool operator!=(const Vector4 &lhs, const Vector4 &rhs);
    operator ::Vector4() const;
    operator ::ImVec4() const;

    [[nodiscard]] constexpr float Length() const;
    [[nodiscard]] constexpr float LengthSqr() const;
    [[nodiscard]] constexpr Vector4 Normalized() const;

    static constexpr float Distance(const Vector4 &v1, const Vector4 &v2);
    static constexpr float DistanceSqr(const Vector4 &v1, const Vector4 &v2);
    static constexpr float Dot(const Vector4 &v1, const Vector4 &v2);
    static constexpr Vector4 Lerp(const Vector4 &v1, const Vector4 &v2, float amount);
    static constexpr Vector4 Max(const Vector4 &v1, const Vector4 &v2);
    static constexpr Vector4 Min(const Vector4 &v1, const Vector4 &v2);
    static constexpr Vector4 MoveTowards(const Vector4 &v, const Vector4 &target,
                                         float maxDist);
};

} // namespace Lumen

#include "Lumen/Math/Vector4.inl"

namespace Lumen
{

inline constexpr Vector4 Vector4::One{1.0f, 1.0f, 1.0f, 1.0f};
inline constexpr Vector4 Vector4::Zero{0.0f, 0.0f, 0.0f, 0.0f};

} // namespace Lumen