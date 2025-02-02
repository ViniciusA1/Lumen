#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2RevoluteJointDef;

namespace Lumen
{

struct RevoluteJointDef2D
{
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float DampingRatio;
    float DrawSize;
    bool EnableLimit;
    bool EnableMotor;
    bool EnableSpring;
    float Hertz;
    Vector2 LocalAnchorA;
    Vector2 LocalAnchorB;
    float LowerAngle;
    float MaxMotorTorque;
    float MotorSpeed;
    float ReferenceAngle;
    float UpperAngle;
    void *UserData;

    RevoluteJointDef2D();
    RevoluteJointDef2D(const b2RevoluteJointDef &def);

    operator b2RevoluteJointDef() const;
};

} // namespace Lumen