#include "Lumen/Physics2D/WeldJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

WeldJointDef2D::WeldJointDef2D() : WeldJointDef2D(b2DefaultWeldJointDef())
{
}

WeldJointDef2D::WeldJointDef2D(const b2WeldJointDef &def)
{
    AngularDampingRatio = def.angularDampingRatio;
    AngularHertz = def.angularHertz;
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    LinearDampingRatio = def.linearDampingRatio;
    LinearHertz = def.linearHertz;
    LocalAnchorA = def.localAnchorA;
    LocalAnchorB = def.localAnchorB;
    ReferenceAngle = def.referenceAngle;
    UserData = def.userData;
}

WeldJointDef2D::operator b2WeldJointDef() const
{
    b2WeldJointDef def = b2DefaultWeldJointDef();

    def.angularDampingRatio = AngularDampingRatio;
    def.angularHertz = AngularHertz;
    def.bodyIdA = BodyA.GetBodyID();
    def.bodyIdB = BodyB.GetBodyID();
    def.collideConnected = CollideConnected;
    def.linearDampingRatio = LinearDampingRatio;
    def.linearHertz = LinearHertz;
    def.localAnchorA = LocalAnchorA;
    def.localAnchorB = LocalAnchorB;
    def.referenceAngle = ReferenceAngle;
    def.userData = UserData;

    return def;
}

} // namespace Lumen