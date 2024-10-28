#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct Camera2DComponent : public ComponentBase
{
    Vector2 Offset;
    Vector2 Target;
    float Rotation = 0.0f;
    float Zoom = 1.0f;
};

} // namespace Lumen