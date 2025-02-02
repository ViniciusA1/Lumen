#include "Lumen/Physics2D/Body2D.hpp"
#include "Lumen/Math/Math.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

Transform2D::Transform2D(const b2Transform &transform)
    : Position(transform.p), Rotation(b2Rot_GetAngle(transform.q))
{
}

Body2D::Body2D(const b2BodyId &bodyID) : m_BodyID(bodyID)
{
}

bool Body2D::IsAwake() const
{
    return b2Body_IsAwake(m_BodyID);
}

bool Body2D::IsBullet() const
{
    return b2Body_IsBullet(m_BodyID);
}

bool Body2D::IsEnabled() const
{
    return b2Body_IsEnabled(m_BodyID);
}

bool Body2D::IsFixedRotation() const
{
    return b2Body_IsFixedRotation(m_BodyID);
}

bool Body2D::IsSleepEnabled() const
{
    return b2Body_IsSleepEnabled(m_BodyID);
}

bool Body2D::IsValid() const
{
    return b2Body_IsValid(m_BodyID);
}

float Body2D::GetAngularDamping() const
{
    return b2Body_GetAngularDamping(m_BodyID);
}

float Body2D::GetAngularVelocity() const
{
    return b2Body_GetAngularVelocity(m_BodyID);
}

bool Body2D::GetAutomaticMass() const
{
    return b2Body_GetAutomaticMass(m_BodyID);
}

b2BodyId Body2D::GetBodyID() const
{
    return m_BodyID;
}

int32_t Body2D::GetContactCapacity() const
{
    return b2Body_GetContactCapacity(m_BodyID);
}

float Body2D::GetGravityScale() const
{
    return b2Body_GetGravityScale(m_BodyID);
}

int32_t Body2D::GetJointCount() const
{
    return b2Body_GetJointCount(m_BodyID);
}

float Body2D::GetLinearDamping() const
{
    return b2Body_GetLinearDamping(m_BodyID);
}

Vector2 Body2D::GetLinearVelocity() const
{
    return b2Body_GetLinearVelocity(m_BodyID);
}

Vector2 Body2D::GetLocalCenterOfMass() const
{
    return b2Body_GetLocalCenterOfMass(m_BodyID);
}

Vector2 Body2D::GetLocalPoint(const Vector2 &worldPoint) const
{
    return b2Body_GetLocalPoint(m_BodyID, worldPoint);
}

Vector2 Body2D::GetLocalVector(const Vector2 &worldVector) const
{
    return b2Body_GetLocalVector(m_BodyID, worldVector);
}

float Body2D::GetMass() const
{
    return b2Body_GetMass(m_BodyID);
}

MassData2D Body2D::GetMassData() const
{
    b2MassData data = b2Body_GetMassData(m_BodyID);
    return {data.center, data.mass, data.rotationalInertia};
}

Vector2 Body2D::GetPosition() const
{
    return b2Body_GetPosition(m_BodyID);
}

float Body2D::GetRotation() const
{
    b2Rot rotation = b2Body_GetRotation(m_BodyID);
    return b2Rot_GetAngle(rotation);
}

int32_t Body2D::GetShapeCount() const
{
    return b2Body_GetShapeCount(m_BodyID);
}

std::vector<Shape2D> Body2D::GetShapes(std::size_t count) const
{
    std::vector<b2ShapeId> idVec;
    idVec.reserve(count);
    int size = b2Body_GetShapes(m_BodyID, idVec.data(), count);

    std::vector<Shape2D> shapeVec;
    shapeVec.reserve(size);
    for (int i = 0; i < size; i++)
    {
        shapeVec[i] = idVec[i];
    }

    return shapeVec;
}

float Body2D::GetSleepThreshold() const
{
    return b2Body_GetSleepThreshold(m_BodyID);
}

Transform2D Body2D::GetTransform() const
{
    return b2Body_GetTransform(m_BodyID);
}

BodyType2D Body2D::GetType() const
{
    return static_cast<BodyType2D>(b2Body_GetType(m_BodyID));
}

Vector2 Body2D::GetWorldCenterOfMass() const
{
    return b2Body_GetWorldCenterOfMass(m_BodyID);
}

Vector2 Body2D::GetWorldPoint(const Vector2 &localPoint) const
{
    return b2Body_GetWorldPoint(m_BodyID, localPoint);
}

Vector2 Body2D::GetWorldVector(const Vector2 &localVector) const
{
    return b2Body_GetWorldVector(m_BodyID, localVector);
}

void Body2D::SetAngularDamping(float damping)
{
    b2Body_SetAngularDamping(m_BodyID, damping);
}

void Body2D::SetAngularVelocity(float velocity)
{
    b2Body_SetAngularVelocity(m_BodyID, velocity);
}

void Body2D::SetAutomaticMass(bool enabled)
{
    b2Body_SetAutomaticMass(m_BodyID, enabled);
}

void Body2D::SetAwake(bool awake)
{
    b2Body_SetAwake(m_BodyID, awake);
}

void Body2D::SetBullet(bool isBullet)
{
    b2Body_SetBullet(m_BodyID, isBullet);
}

void Body2D::SetFixedRotation(bool fixedRotation)
{
    b2Body_SetFixedRotation(m_BodyID, fixedRotation);
}

void Body2D::SetGravityScale(float scale)
{
    b2Body_SetGravityScale(m_BodyID, scale);
}

void Body2D::SetLinearDamping(float damping)
{
    b2Body_SetLinearDamping(m_BodyID, damping);
}

void Body2D::SetLinearVelocity(const Vector2 &velocity)
{
    b2Body_SetLinearVelocity(m_BodyID, velocity);
}

void Body2D::SetMassData(const MassData2D &massData)
{
    b2Body_SetMassData(m_BodyID,
                       {massData.Mass, massData.Center, massData.RotationalInertia});
}

void Body2D::SetSleepThreshold(float threshold)
{
    b2Body_SetSleepThreshold(m_BodyID, threshold);
}

void Body2D::SetTransform(const Vector2 &position, float angle)
{
    b2Rot rotation = {Math::Cos(angle), Math::Sin(angle)};
    b2Body_SetTransform(m_BodyID, position, rotation);
}

void Body2D::SetType(BodyType2D type)
{
    b2Body_SetType(m_BodyID, static_cast<b2BodyType>(type));
}

Shape2D Body2D::CreateCapsuleShape(const ShapeDef2D &def, const CapsuleShape2D &shape)
{
    b2ShapeDef shapeDef = def;
    b2Capsule capsule = shape;
    return {b2CreateCapsuleShape(m_BodyID, &shapeDef, &capsule)};
}

Shape2D Body2D::CreateCircleShape(const ShapeDef2D &def, const CircleShape2D &shape)
{
    b2ShapeDef shapeDef = def;
    b2Circle circle = shape;
    return {b2CreateCircleShape(m_BodyID, &shapeDef, &circle)};
}

Shape2D Body2D::CreatePolygonShape(const ShapeDef2D &def, const PolygonShape2D &shape)
{
    b2ShapeDef shapeDef = def;
    b2Polygon polygon = shape;
    return {b2CreatePolygonShape(m_BodyID, &shapeDef, &polygon)};
}

Shape2D Body2D::CreateSegmentShape(const ShapeDef2D &def, const SegmentShape2D &shape)
{
    b2ShapeDef shapeDef = def;
    b2Segment segment = shape;
    return {b2CreateSegmentShape(m_BodyID, &shapeDef, &segment)};
}

void Body2D::DestroyShape(const Shape2D &shape)
{
    b2DestroyShape(shape.GetShapeID());
}

void Body2D::ApplyAngularImpulse(float impulse, bool wake)
{
    b2Body_ApplyAngularImpulse(m_BodyID, impulse, wake);
}

void Body2D::ApplyForce(const Vector2 &force, const Vector2 &point, bool wake)
{
    b2Body_ApplyForce(m_BodyID, force, point, wake);
}

void Body2D::ApplyForceToCenter(const Vector2 &force, bool wake)
{
    b2Body_ApplyForceToCenter(m_BodyID, force, wake);
}

void Body2D::ApplyLinearImpulse(const Vector2 &impulse, const Vector2 &point, bool wake)
{
    b2Body_ApplyLinearImpulse(m_BodyID, impulse, point, wake);
}

void Body2D::ApplyLinearImpulseToCenter(const Vector2 &impulse, bool wake)
{
    b2Body_ApplyLinearImpulseToCenter(m_BodyID, impulse, wake);
}

void Body2D::ApplyMassFromShapes()
{
    b2Body_ApplyMassFromShapes(m_BodyID);
}

void Body2D::ApplyTorque(float torque, bool wake)
{
    b2Body_ApplyTorque(m_BodyID, torque, wake);
}

void Body2D::Disable()
{
    b2Body_Disable(m_BodyID);
}

void Body2D::Enable()
{
    b2Body_Enable(m_BodyID);
}

void Body2D::EnableHitEvents(bool enabled)
{
    b2Body_EnableHitEvents(m_BodyID, enabled);
}

void Body2D::EnableSleep(bool enabled)
{
    b2Body_EnableSleep(m_BodyID, enabled);
}

} // namespace Lumen