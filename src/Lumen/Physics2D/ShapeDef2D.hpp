#pragma once

#include "Lumen/Graphics/Color.hpp"

#include <cstdint>

struct b2Filter;
struct b2ShapeDef;

namespace Lumen
{

struct ShapeFilter2D
{
    std::uint32_t CategoryBits;
    std::uint32_t MaskBits;
    std::int32_t GroupIndex;

    operator b2Filter() const;
};

struct ShapeDef2D
{
    float Friction;
    float Restitution;
    float Density;
    ShapeFilter2D Filter;
    Color CustomColor;
    bool IsSensor;
    bool EnableSensorEvents;
    bool EnableContactEvents;
    bool EnableHitEvents;
    bool EnablePreSolveEvents;
    bool ForceContactCreation;

    ShapeDef2D();
    ShapeDef2D(const b2ShapeDef &def);

    operator b2ShapeDef() const;
};

enum class ShapeType2D
{
    Circle,
    Capsule,
    Segment,
    Polygon,
    SmoothSegment,
    Count
};

} // namespace Lumen