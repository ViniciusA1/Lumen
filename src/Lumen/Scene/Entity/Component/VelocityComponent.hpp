#pragma once

#include "Lumen/Math/Vector3.hpp"

namespace Lumen
{

struct VelocityComponent
{
    Vector3 Velocity = {1.0f, 0.0f, 0.0f};

    VelocityComponent() = default;
    VelocityComponent(const Vector3 &velocity) : Velocity(velocity) {}
};

} // namespace Lumen