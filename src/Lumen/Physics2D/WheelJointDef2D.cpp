#include "Lumen/Physics2D/WheelJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

WheelJointDef2D::WheelJointDef2D() : WheelJointDef2D(b2DefaultWheelJointDef())
{
}

WheelJointDef2D::WheelJointDef2D(const b2WheelJointDef &def)
{
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    DampingRatio = def.dampingRatio;
    EnableLimit = def.enableLimit;
    EnableMotor = def.enableMotor;
    EnableSpring = def.enableSpring;
    Hertz = def.hertz;
    LocalAnchorA = def.localAnchorA;
    LocalAnchorB = def.localAnchorB;
    LocalAxisA = def.localAxisA;
    LowerTranslation = def.lowerTranslation;
    MaxMotorTorque = def.maxMotorTorque;
    MotorSpeed = def.motorSpeed;
    UpperTranslation = def.upperTranslation;
    UserData = def.userData;
}

WheelJointDef2D::operator b2WheelJointDef() const
{
    b2WheelJointDef def = b2DefaultWheelJointDef();

    def.bodyIdA = BodyA.GetID();
    def.bodyIdB = BodyB.GetID();
    def.collideConnected = CollideConnected;
    def.dampingRatio = DampingRatio;
    def.enableLimit = EnableLimit;
    def.enableMotor = EnableMotor;
    def.enableSpring = EnableSpring;
    def.hertz = Hertz;
    def.localAnchorA = LocalAnchorA;
    def.localAnchorB = LocalAnchorB;
    def.localAxisA = LocalAxisA;
    def.lowerTranslation = LowerTranslation;
    def.maxMotorTorque = MaxMotorTorque;
    def.motorSpeed = MotorSpeed;
    def.upperTranslation = UpperTranslation;
    def.userData = UserData;

    return def;
}

} // namespace Lumen