#include "Lumen/Physics2D/DistanceJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

DistanceJointDef2D::DistanceJointDef2D() : DistanceJointDef2D(b2DefaultDistanceJointDef())
{
}

DistanceJointDef2D::DistanceJointDef2D(const b2DistanceJointDef &def)
{
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    DampingRatio = def.dampingRatio;
    EnableLimit = def.enableLimit;
    EnableMotor = def.enableMotor;
    EnableSpring = def.enableSpring;
    Hertz = def.hertz;
    Length = def.length;
    LocalAnchorA = def.localAnchorA;
    LocalAnchorB = def.localAnchorB;
    MaxLength = def.maxLength;
    MaxMotorForce = def.maxMotorForce;
    MinLength = def.minLength;
    MotorSpeed = def.motorSpeed;
    UserData = def.userData;
}

DistanceJointDef2D::operator b2DistanceJointDef() const
{
    b2DistanceJointDef def = b2DefaultDistanceJointDef();

    def.bodyIdA = BodyA.GetID();
    def.bodyIdB = BodyB.GetID();
    def.collideConnected = CollideConnected;
    def.dampingRatio = DampingRatio;
    def.enableLimit = EnableLimit;
    def.enableMotor = EnableMotor;
    def.enableSpring = EnableSpring;
    def.hertz = Hertz;
    def.length = Length;
    def.localAnchorA = LocalAnchorA;
    def.localAnchorB = LocalAnchorB;
    def.maxLength = MaxLength;
    def.maxMotorForce = MaxMotorForce;
    def.minLength = MinLength;
    def.motorSpeed = MotorSpeed;
    def.userData = UserData;

    return def;
}

} // namespace Lumen