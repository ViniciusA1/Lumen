#pragma once

#include "Lumen/Math/Vector3.hpp"

struct BoundingBox;

namespace Lumen
{

class BoundingBox
{
public:
    Vector3 Min;
    Vector3 Max;

public:
    constexpr BoundingBox() = default;
    constexpr BoundingBox(const Vector3 &min, const Vector3 &max);

    BoundingBox(const ::BoundingBox &box);

    [[nodiscard]] constexpr bool IsValid() const;

    [[nodiscard]] constexpr bool Contains(const Vector3 &point) const;
    [[nodiscard]] constexpr bool Contains(const BoundingBox &other) const;
    [[nodiscard]] constexpr bool Intersects(const BoundingBox &other) const;

    [[nodiscard]] constexpr Vector3 GetCenter() const;
    [[nodiscard]] constexpr Vector3 GetCorner(int index) const;
    [[nodiscard]] constexpr Vector3 GetExtents() const;
    [[nodiscard]] constexpr Vector3 GetSize() const;
    [[nodiscard]] constexpr float GetSurfaceArea() const;
    [[nodiscard]] constexpr float GetVolume() const;

    [[nodiscard]] constexpr BoundingBox Transform(const Matrix4 &transform) const;

    operator ::BoundingBox() const;
};

} // namespace Lumen

#include "Lumen/Math/BoundingBox.inl"