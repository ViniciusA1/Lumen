#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2DistanceJointDef;

namespace Lumen
{

struct DistanceJointDef2D
{
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float DampingRatio;
    bool EnableLimit;
    bool EnableMotor;
    bool EnableSpring;
    float Hertz;
    float Length;
    Vector2 LocalAnchorA;
    Vector2 LocalAnchorB;
    float MaxLength;
    float MaxMotorForce;
    float MinLength;
    float MotorSpeed;
    void *UserData;

    DistanceJointDef2D();
    DistanceJointDef2D(const b2DistanceJointDef &def);

    operator b2DistanceJointDef() const;
};

} // namespace Lumen