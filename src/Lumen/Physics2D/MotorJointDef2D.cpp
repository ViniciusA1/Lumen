#include "Lumen/Physics2D/MotorJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

MotorJointDef2D::MotorJointDef2D() : MotorJointDef2D(b2DefaultMotorJointDef())
{
}

MotorJointDef2D::MotorJointDef2D(const b2MotorJointDef &def)
{
    AngularOffset = def.angularOffset;
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    CorrectionFactor = def.correctionFactor;
    LinearOffset = def.linearOffset;
    MaxForce = def.maxForce;
    MaxTorque = def.maxTorque;
    UserData = def.userData;
}

MotorJointDef2D::operator b2MotorJointDef() const
{
    b2MotorJointDef def = b2DefaultMotorJointDef();

    def.angularOffset = AngularOffset;
    def.bodyIdA = BodyA.GetID();
    def.bodyIdB = BodyB.GetID();
    def.collideConnected = CollideConnected;
    def.correctionFactor = CorrectionFactor;
    def.linearOffset = LinearOffset;
    def.maxForce = MaxForce;
    def.maxTorque = MaxTorque;
    def.userData = UserData;

    return def;
}

} // namespace Lumen