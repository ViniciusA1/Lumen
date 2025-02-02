#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Physics2D/ShapeDef2D.hpp"
#include "Lumen/Physics2D/ShapeTemplates2D.hpp"

#include "box2d/id.h"

namespace Lumen
{

class Body2D;

class Shape2D
{
public:
    Shape2D(const b2ShapeId &shapeID = {0, 0, 0});

    [[nodiscard]] bool AreContactEventsEnabled() const;
    [[nodiscard]] bool AreHitEventsEnabled() const;
    [[nodiscard]] bool ArePreSolveEventsEnabled() const;
    [[nodiscard]] bool AreSensorEventsEnabled() const;

    [[nodiscard]] bool IsSensor() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Body2D GetBody() const;
    [[nodiscard]] Vector2 GetClosestPoint(const Vector2 &point) const;
    [[nodiscard]] std::int32_t GetContactCapacity() const;
    [[nodiscard]] float GetDensity() const;
    [[nodiscard]] ShapeFilter2D GetFilter() const;
    [[nodiscard]] float GetFriction() const;
    [[nodiscard]] float GetRestitution() const;
    [[nodiscard]] b2ShapeId GetShapeID() const;
    [[nodiscard]] ShapeType2D GetType() const;

    void SetCapsule(const CapsuleShape2D &capsule);
    void SetCircle(const CircleShape2D &circle);
    void SetDensity(float density);
    void SetFilter(const ShapeFilter2D &filter);
    void SetFriction(float friction);
    void SetPolygon(const PolygonShape2D &polygon);
    void SetRestitution(float restitution);
    void SetSegment(const SegmentShape2D &segment);

    void EnableContactEvents(bool enable);
    void EnableHitEvents(bool enable);
    void EnablePreSolveEvents(bool enable);
    void EnableSensorEvents(bool enable);

private:
    b2ShapeId m_ShapeID;
};

} // namespace Lumen