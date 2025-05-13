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
    BoundingBox() = default;
    BoundingBox(const Vector3 &min, const Vector3 &max);
    BoundingBox(const ::BoundingBox &box);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] bool Contains(const Vector3 &point) const;
    [[nodiscard]] bool Contains(const BoundingBox &other) const;
    [[nodiscard]] bool Intersects(const BoundingBox &other) const;

    [[nodiscard]] Vector3 GetCenter() const;
    [[nodiscard]] Vector3 GetCorner(int index) const;
    [[nodiscard]] Vector3 GetExtents() const;
    [[nodiscard]] Vector3 GetSize() const;
    [[nodiscard]] float GetSurfaceArea() const;
    [[nodiscard]] float GetVolume() const;

    [[nodiscard]] BoundingBox Transform(const Matrix4 &transform) const;

    operator ::BoundingBox() const;
};

} // namespace Lumen