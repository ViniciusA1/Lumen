#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2PrismaticJointDef;

namespace Lumen
{

struct PrismaticJointDef2D
{
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float DampingRatio;
    bool EnableLimit;
    bool EnableMotor;
    bool EnableSpring;
    float Hertz;
    Vector2 LocalAnchorA;
    Vector2 LocalAnchorB;
    Vector2 LocalAxisA;
    float LowerTranslation;
    float MaxMotorForce;
    float MotorSpeed;
    float ReferenceAngle;
    float UpperTranslation;
    void *UserData;

    PrismaticJointDef2D();
    PrismaticJointDef2D(const b2PrismaticJointDef &def);

    operator b2PrismaticJointDef() const;
};

} // namespace Lumen