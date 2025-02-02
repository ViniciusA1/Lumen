#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2WheelJointDef;

namespace Lumen
{

struct WheelJointDef2D
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
    float MaxMotorTorque;
    float MotorSpeed;
    float UpperTranslation;
    void *UserData;

    WheelJointDef2D();
    WheelJointDef2D(const b2WheelJointDef &def);

    operator b2WheelJointDef() const;
};

} // namespace Lumen