#pragma once

#include "Lumen/Math/BoundingBox.hpp"
#include "Lumen/Math/Matrix4.hpp"

namespace Lumen
{

constexpr BoundingBox::BoundingBox(const Vector3 &min, const Vector3 &max)
    : Min(min), Max(max)
{
}

constexpr bool BoundingBox::IsValid() const
{
    return Min.x <= Max.x && Min.y <= Max.y && Min.z <= Max.z;
}

constexpr bool BoundingBox::Contains(const Vector3 &point) const
{
    return point.x >= Min.x && point.x <= Max.x && point.y >= Min.y && point.y <= Max.y &&
           point.z >= Min.z && point.z <= Max.z;
}

constexpr bool BoundingBox::Contains(const BoundingBox &other) const
{
    return other.Min.x >= Min.x && other.Max.x <= Max.x && other.Min.y >= Min.y &&
           other.Max.y <= Max.y && other.Min.z >= Min.z && other.Max.z <= Max.z;
}

constexpr bool BoundingBox::Intersects(const BoundingBox &other) const
{
    return !(other.Max.x < Min.x || other.Min.x > Max.x || other.Max.y < Min.y ||
             other.Min.y > Max.y || other.Max.z < Min.z || other.Min.z > Max.z);
}

constexpr Vector3 BoundingBox::GetCenter() const
{
    return (Min + Max) * 0.5f;
}

constexpr Vector3 BoundingBox::GetCorner(int index) const
{
    return {(index & 1) ? Max.x : Min.x, (index & 2) ? Max.y : Min.y,
            (index & 4) ? Max.z : Min.z};
}

constexpr Vector3 BoundingBox::GetExtents() const
{
    return GetSize() * 0.5f;
}

constexpr Vector3 BoundingBox::GetSize() const
{
    return Max - Min;
}

constexpr float BoundingBox::GetSurfaceArea() const
{
    Vector3 size = GetSize();
    return 2.0f * (size.x * size.y + size.x * size.z + size.y * size.z);
}

constexpr float BoundingBox::GetVolume() const
{
    Vector3 size = GetSize();
    return size.x * size.y * size.z;
}

constexpr BoundingBox BoundingBox::Transform(const Matrix4 &transform) const
{
    const std::array<Vector3, 8> &corners = {
        Vector3(Min.x, Min.y, Min.z), Vector3(Min.x, Min.y, Max.z),
        Vector3(Min.x, Max.y, Min.z), Vector3(Min.x, Max.y, Max.z),
        Vector3(Max.x, Min.y, Min.z), Vector3(Max.x, Min.y, Max.z),
        Vector3(Max.x, Max.y, Min.z), Vector3(Max.x, Max.y, Max.z),
    };

    BoundingBox result;
    for (const Vector3 &corner : corners)
    {
        Vector3 transformed = Vector3::Transform(corner, transform);
        result.Min = Vector3::Min(result.Min, transformed);
        result.Max = Vector3::Max(result.Max, transformed);
    }

    return result;
}

} // namespace Lumen