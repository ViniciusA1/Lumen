#include "Lumen/Physics2D/MouseJointDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

MouseJointDef2D::MouseJointDef2D() : MouseJointDef2D(b2DefaultMouseJointDef())
{
}

MouseJointDef2D::MouseJointDef2D(const b2MouseJointDef &def)
{
    BodyA = def.bodyIdA;
    BodyB = def.bodyIdB;
    CollideConnected = def.collideConnected;
    DampingRatio = def.dampingRatio;
    Hertz = def.hertz;
    MaxForce = def.maxForce;
    Target = def.target;
    UserData = def.userData;
}

MouseJointDef2D::operator b2MouseJointDef() const
{
    b2MouseJointDef def = b2DefaultMouseJointDef();

    def.bodyIdA = BodyA.GetBodyID();
    def.bodyIdB = BodyB.GetBodyID();
    def.collideConnected = CollideConnected;
    def.dampingRatio = DampingRatio;
    def.hertz = Hertz;
    def.maxForce = MaxForce;
    def.target = Target;
    def.userData = UserData;

    return def;
}

} // namespace Lumen