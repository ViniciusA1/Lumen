#pragma once

#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct TransformComponent : public ComponentBase
{
    Vector3 Position = {0.0f, 0.0f, 0.0f};
    Vector3 Rotation = {0.0f, 0.0f, 0.0f};
    Vector3 Scale = {1.0f, 1.0f, 1.0f};

    TransformComponent() = default;
    TransformComponent(const Vector3 &position) : Position(position) {}
};

} // namespace Lumen