#include "Lumen/Physics2D/RevoluteJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

RevoluteJointDef2D::RevoluteJointDef2D() : RevoluteJointDef2D(b2DefaultRevoluteJointDef())
{
}

RevoluteJointDef2D::RevoluteJointDef2D(const b2RevoluteJointDef &def)
{
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    DampingRatio = def.dampingRatio;
    DrawSize = def.drawSize;
    EnableLimit = def.enableLimit;
    EnableMotor = def.enableMotor;
    EnableSpring = def.enableSpring;
    Hertz = def.hertz;
    LocalAnchorA = def.localAnchorA;
    LocalAnchorB = def.localAnchorB;
    LowerAngle = def.lowerAngle;
    MaxMotorTorque = def.maxMotorTorque;
    MotorSpeed = def.motorSpeed;
    ReferenceAngle = def.referenceAngle;
    UpperAngle = def.upperAngle;
    UserData = def.userData;
}

RevoluteJointDef2D::operator b2RevoluteJointDef() const
{
    b2RevoluteJointDef def = b2DefaultRevoluteJointDef();

    def.bodyIdA = BodyA.GetID();
    def.bodyIdB = BodyB.GetID();
    def.collideConnected = CollideConnected;
    def.dampingRatio = DampingRatio;
    def.drawSize = DrawSize;
    def.enableLimit = EnableLimit;
    def.enableMotor = EnableMotor;
    def.enableSpring = EnableSpring;
    def.hertz = Hertz;
    def.localAnchorA = LocalAnchorA;
    def.localAnchorB = LocalAnchorB;
    def.lowerAngle = LowerAngle;
    def.maxMotorTorque = MaxMotorTorque;
    def.motorSpeed = MotorSpeed;
    def.referenceAngle = ReferenceAngle;
    def.upperAngle = UpperAngle;
    def.userData = UserData;

    return def;
}

} // namespace Lumen