#include "Lumen/Physics2D/WorldDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

WorldDef2D::WorldDef2D() : WorldDef2D(b2DefaultWorldDef())
{
}

WorldDef2D::WorldDef2D(const b2WorldDef &def)
{
    Gravity = {def.gravity.x, def.gravity.y};
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

WorldDef2D::operator b2WorldDef() const
{
    b2WorldDef def = b2DefaultWorldDef();

    def.gravity = {Gravity.x, Gravity.y};
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