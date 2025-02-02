#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2WeldJointDef;

namespace Lumen
{

struct WeldJointDef2D
{
    float AngularDampingRatio;
    float AngularHertz;
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float LinearDampingRatio;
    float LinearHertz;
    Vector2 LocalAnchorA;
    Vector2 LocalAnchorB;
    float ReferenceAngle;
    void *UserData;

    WeldJointDef2D();
    WeldJointDef2D(const b2WeldJointDef &def);

    operator b2WeldJointDef() const;
};

} // namespace Lumen