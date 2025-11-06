#pragma once

#include "Lumen/Graphics/Color.hpp"

namespace Lumen
{

enum class LightType
{
    Directional,
    Point,
    Spot
};

struct LightComponent
{
    LightType Type = LightType::Point;
    Color Color = Color::White;
    float Intensity = 1.0f;
    float Range = 10.0f;
    float InnerCone = 15.0f;
    float OuterCone = 25.0f;
    bool CastShadows = false;
};

} // namespace Lumen