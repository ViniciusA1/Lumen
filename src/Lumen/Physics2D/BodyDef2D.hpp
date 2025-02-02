#pragma once

#include "Lumen/Math/Vector2.hpp"

struct b2BodyDef;
struct b2Transform;

namespace Lumen
{

enum class BodyType2D
{
    StaticBody,
    KinematicBody,
    DynamicBody,
    Count,
};

struct MassData2D
{
    Vector2 Center;
    float Mass;
    float RotationalInertia;
};

struct BodyDef2D
{
    BodyType2D Type;
    Vector2 Position;
    Vector2 Rotation;
    Vector2 LinearVelocity;
    float AngularVelocity;
    float LinearDamping;
    float AngularDamping;
    float GravityScale;
    float SleepThreshold;
    bool EnableSleep;
    bool IsAwake;
    bool FixedRotation;
    bool IsBullet;
    bool IsEnabled;
    bool AutomaticMass;
    bool AllowFastRotation;

    BodyDef2D();
    BodyDef2D(const b2BodyDef &def);

    operator b2BodyDef() const;
};

struct Transform2D
{
    Vector2 Position;
    float Rotation;

    Transform2D(const b2Transform &transform);
};

} // namespace Lumen