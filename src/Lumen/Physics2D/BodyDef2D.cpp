#include "Lumen/Physics2D/BodyDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

BodyDef2D::BodyDef2D() : BodyDef2D(b2DefaultBodyDef())
{
}

BodyDef2D::BodyDef2D(const b2BodyDef &def)
{
    Type = static_cast<BodyType2D>(def.type);
    Position = def.position;
    Rotation = {def.rotation.c, def.rotation.s};
    LinearVelocity = def.linearVelocity;
    AngularVelocity = def.angularVelocity;
    LinearDamping = def.linearDamping;
    AngularDamping = def.angularDamping;
    GravityScale = def.gravityScale;
    SleepThreshold = def.sleepThreshold;
    EnableSleep = def.enableSleep;
    IsAwake = def.isAwake;
    FixedRotation = def.fixedRotation;
    IsBullet = def.isBullet;
    IsEnabled = def.isEnabled;
    AutomaticMass = def.automaticMass;
    AllowFastRotation = def.allowFastRotation;
}

BodyDef2D::operator b2BodyDef() const
{
    b2BodyDef def = b2DefaultBodyDef();

    def.type = static_cast<b2BodyType>(Type);
    def.position = Position;
    def.rotation = {Rotation.x, Rotation.y};
    def.linearVelocity = LinearVelocity;
    def.angularVelocity = AngularVelocity;
    def.linearDamping = LinearDamping;
    def.angularDamping = AngularDamping;
    def.gravityScale = GravityScale;
    def.sleepThreshold = SleepThreshold;
    def.enableSleep = EnableSleep;
    def.isAwake = IsAwake;
    def.fixedRotation = FixedRotation;
    def.isBullet = IsBullet;
    def.isEnabled = IsEnabled;
    def.automaticMass = AutomaticMass;
    def.allowFastRotation = AllowFastRotation;

    return def;
}

Transform2D::Transform2D(const b2Transform &transform)
    : Position(transform.p), Rotation(b2Rot_GetAngle(transform.q))
{
}

} // namespace Lumen