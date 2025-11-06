#pragma once

#include "Lumen/Math/Vector2.hpp"

struct b2WorldDef;

namespace Lumen
{

struct PhysicsWorldDef2D
{
    Vector2 Gravity;
    float RestitutionThreshold;
    float ContactPushoutVelocity;
    float HitEventThreshold;
    float ContactHertz;
    float ContactDampingRatio;
    float JointHertz;
    float JointDampingRatio;
    float MaximumLinearVelocity;
    bool EnableSleep;
    bool EnableContinous;

    PhysicsWorldDef2D();
    PhysicsWorldDef2D(const b2WorldDef &def);

    operator b2WorldDef() const;
};

} // namespace Lumen