#include "Lumen/Physics2D/Shape2D.hpp"
#include "Lumen/Physics2D/Body2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

Shape2D::Shape2D(const b2ShapeId &shapeID) : m_ShapeID(shapeID)
{
}

bool Shape2D::AreContactEventsEnabled() const
{
    return b2Shape_AreContactEventsEnabled(m_ShapeID);
}

bool Shape2D::AreHitEventsEnabled() const
{
    return b2Shape_AreHitEventsEnabled(m_ShapeID);
}

bool Shape2D::ArePreSolveEventsEnabled() const
{
    return b2Shape_ArePreSolveEventsEnabled(m_ShapeID);
}

bool Shape2D::AreSensorEventsEnabled() const
{
    return b2Shape_AreSensorEventsEnabled(m_ShapeID);
}

bool Shape2D::IsSensor() const
{
    return b2Shape_IsSensor(m_ShapeID);
}

bool Shape2D::IsValid() const
{
    return b2Shape_IsValid(m_ShapeID);
}

Body2D Shape2D::GetBody() const
{
    return {b2Shape_GetBody(m_ShapeID)};
}

Vector2 Shape2D::GetClosestPoint(const Vector2 &point) const
{
    return b2Shape_GetClosestPoint(m_ShapeID, point);
}

std::int32_t Shape2D::GetContactCapacity() const
{
    return b2Shape_GetContactCapacity(m_ShapeID);
}

float Shape2D::GetDensity() const
{
    return b2Shape_GetDensity(m_ShapeID);
}

ShapeFilter2D Shape2D::GetFilter() const
{
    b2Filter filter = b2Shape_GetFilter(m_ShapeID);
    return {filter.categoryBits, filter.maskBits, filter.groupIndex};
}

float Shape2D::GetFriction() const
{
    return b2Shape_GetFriction(m_ShapeID);
}

float Shape2D::GetRestitution() const
{
    return b2Shape_GetRestitution(m_ShapeID);
}

b2ShapeId Shape2D::GetShapeID() const
{
    return m_ShapeID;
}

ShapeType2D Shape2D::GetType() const
{
    return static_cast<ShapeType2D>(b2Shape_GetType(m_ShapeID));
}

void Shape2D::SetCapsule(const CapsuleShape2D &capsule)
{
    b2Capsule shape = capsule;
    b2Shape_SetCapsule(m_ShapeID, &shape);
}

void Shape2D::SetCircle(const CircleShape2D &circle)
{
    b2Circle shape = circle;
    b2Shape_SetCircle(m_ShapeID, &shape);
}

void Shape2D::SetDensity(float density)
{
    b2Shape_SetDensity(m_ShapeID, density);
}

void Shape2D::SetFilter(const ShapeFilter2D &filter)
{
    b2Shape_SetFilter(m_ShapeID, filter);
}

void Shape2D::SetFriction(float friction)
{
    b2Shape_SetFriction(m_ShapeID, friction);
}

void Shape2D::SetPolygon(const PolygonShape2D &polygon)
{
    b2Polygon shape = polygon;
    b2Shape_SetPolygon(m_ShapeID, &shape);
}

void Shape2D::SetRestitution(float restitution)
{
    b2Shape_SetRestitution(m_ShapeID, restitution);
}

void Shape2D::SetSegment(const SegmentShape2D &segment)
{
    b2Segment shape = segment;
    b2Shape_SetSegment(m_ShapeID, &shape);
}

void Shape2D::EnableContactEvents(bool enable)
{
    b2Shape_EnableContactEvents(m_ShapeID, enable);
}

void Shape2D::EnableHitEvents(bool enable)
{
    b2Shape_EnableHitEvents(m_ShapeID, enable);
}

void Shape2D::EnablePreSolveEvents(bool enable)
{
    b2Shape_EnablePreSolveEvents(m_ShapeID, enable);
}

void Shape2D::EnableSensorEvents(bool enable)
{
    b2Shape_EnableSensorEvents(m_ShapeID, enable);
}

} // namespace Lumen