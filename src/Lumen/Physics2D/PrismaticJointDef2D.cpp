#include "Lumen/Physics2D/PrismaticJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

PrismaticJointDef2D::PrismaticJointDef2D()
    : PrismaticJointDef2D(b2DefaultPrismaticJointDef())
{
}

PrismaticJointDef2D::PrismaticJointDef2D(const b2PrismaticJointDef &def)
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
    MaxMotorForce = def.maxMotorForce;
    MotorSpeed = def.motorSpeed;
    ReferenceAngle = def.referenceAngle;
    UpperTranslation = def.upperTranslation;
    UserData = def.userData;
}

PrismaticJointDef2D::operator b2PrismaticJointDef() const
{
    b2PrismaticJointDef def = b2DefaultPrismaticJointDef();

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
    def.maxMotorForce = MaxMotorForce;
    def.motorSpeed = MotorSpeed;
    def.referenceAngle = ReferenceAngle;
    def.upperTranslation = UpperTranslation;
    def.userData = UserData;

    return def;
}

} // namespace Lumen