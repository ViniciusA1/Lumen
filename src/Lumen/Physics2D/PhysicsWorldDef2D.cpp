#include "Lumen/Physics2D/PhysicsWorldDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

PhysicsWorldDef2D::PhysicsWorldDef2D() : PhysicsWorldDef2D(b2DefaultWorldDef())
{
}

PhysicsWorldDef2D::PhysicsWorldDef2D(const b2WorldDef &def)
{
    Gravity = def.gravity;
    RestitutionThreshold = def.restitutionThreshold;
    ContactPushoutVelocity = def.contactPushoutVelocity;
    HitEventThreshold = def.hitEventThreshold;
    ContactHertz = def.contactHertz;
    ContactDampingRatio = def.contactDampingRatio;
    JointHertz = def.jointHertz;
    JointDampingRatio = def.jointDampingRatio;
    MaximumLinearVelocity = def.maximumLinearVelocity;
    EnableSleep = def.enableSleep;
    EnableContinous = def.enableContinous;
}

PhysicsWorldDef2D::operator b2WorldDef() const
{
    b2WorldDef def = b2DefaultWorldDef();

    def.gravity = Gravity;
    def.hitEventThreshold = HitEventThreshold;
    def.restitutionThreshold = RestitutionThreshold;
    def.contactPushoutVelocity = ContactPushoutVelocity;
    def.contactHertz = ContactHertz;
    def.contactDampingRatio = ContactDampingRatio;
    def.jointHertz = JointHertz;
    def.jointDampingRatio = JointDampingRatio;
    def.maximumLinearVelocity = MaximumLinearVelocity;
    def.enableSleep = EnableSleep;
    def.enableContinous = EnableContinous;

    return def;
}

} // namespace Lumen