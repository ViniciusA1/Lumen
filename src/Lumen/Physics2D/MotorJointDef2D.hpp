#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

struct b2MotorJointDef;

namespace Lumen
{

struct MotorJointDef2D
{
    float AngularOffset;
    Body2D BodyA;
    Body2D BodyB;
    bool CollideConnected;
    float CorrectionFactor;
    Vector2 LinearOffset;
    float MaxForce;
    float MaxTorque;
    void *UserData;

    MotorJointDef2D();
    MotorJointDef2D(const b2MotorJointDef &def);

    operator b2MotorJointDef() const;
};

} // namespace Lumen