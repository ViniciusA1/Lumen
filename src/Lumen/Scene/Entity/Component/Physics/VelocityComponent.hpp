#pragma once

#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct VelocityComponent : public ComponentBase
{
    Vector3 Velocity = {1.0f, 0.0f, 0.0f};

    VelocityComponent() = default;
    VelocityComponent(const Vector3 &velocity) : Velocity(velocity) {}
};

} // namespace Lumen