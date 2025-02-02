#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2MouseJointDef;

namespace Lumen
{

struct MouseJointDef2D
{
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float DampingRatio;
    float Hertz;
    float MaxForce;
    Vector2 Target;
    void *UserData;

    MouseJointDef2D();
    MouseJointDef2D(const b2MouseJointDef &def);

    operator b2MouseJointDef() const;
};

} // namespace Lumen