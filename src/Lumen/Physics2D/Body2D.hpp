#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Physics2D/BodyDef2D.hpp"
#include "Lumen/Physics2D/Shape2D.hpp"
#include "Lumen/Physics2D/ShapeTemplates2D.hpp"

#include "box2d/id.h"
#include <vector>

namespace Lumen
{

class Joint2D;

class Body2D
{
public:
    Body2D(const b2BodyId &bodyID = {0, 0, 0});

    [[nodiscard]] bool IsAwake() const;
    [[nodiscard]] bool IsBullet() const;
    [[nodiscard]] bool IsEnabled() const;
    [[nodiscard]] bool IsFixedRotation() const;
    [[nodiscard]] bool IsSleepEnabled() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] float GetAngularDamping() const;
    [[nodiscard]] float GetAngularVelocity() const;
    [[nodiscard]] bool GetAutomaticMass() const;
    [[nodiscard]] b2BodyId GetID() const;
    [[nodiscard]] int32_t GetContactCapacity() const;
    [[nodiscard]] float GetGravityScale() const;
    [[nodiscard]] int32_t GetJointCount() const;
    [[nodiscard]] std::vector<Joint2D> GetJoints(std::size_t count = 0) const;
    [[nodiscard]] float GetLinearDamping() const;
    [[nodiscard]] Vector2 GetLinearVelocity() const;
    [[nodiscard]] Vector2 GetLocalCenterOfMass() const;
    [[nodiscard]] Vector2 GetLocalPoint(const Vector2 &worldPoint) const;
    [[nodiscard]] Vector2 GetLocalVector(const Vector2 &worldVector) const;
    [[nodiscard]] float GetMass() const;
    [[nodiscard]] MassData2D GetMassData() const;
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] float GetRotation() const;
    [[nodiscard]] int32_t GetShapeCount() const;
    [[nodiscard]] std::vector<Shape2D> GetShapes(std::size_t count = 0) const;
    [[nodiscard]] float GetSleepThreshold() const;
    [[nodiscard]] Transform2D GetTransform() const;
    [[nodiscard]] BodyType2D GetType() const;
    [[nodiscard]] Vector2 GetWorldCenterOfMass() const;
    [[nodiscard]] Vector2 GetWorldPoint(const Vector2 &localPoint) const;
    [[nodiscard]] Vector2 GetWorldVector(const Vector2 &localVector) const;

    void SetAngularDamping(float damping);
    void SetAngularVelocity(float velocity);
    void SetAutomaticMass(bool enabled);
    void SetAwake(bool awake);
    void SetBullet(bool isBullet);
    void SetFixedRotation(bool fixedRotation);
    void SetGravityScale(float scale);
    void SetLinearDamping(float damping);
    void SetLinearVelocity(const Vector2 &velocity);
    void SetMassData(const MassData2D &massData);
    void SetSleepThreshold(float threshold);
    void SetTransform(const Vector2 &position, float angle);
    void SetType(BodyType2D type);

    Shape2D CreateCapsuleShape(const ShapeDef2D &def, const CapsuleShape2D &shape);
    Shape2D CreateCircleShape(const ShapeDef2D &def, const CircleShape2D &shape);
    Shape2D CreatePolygonShape(const ShapeDef2D &def, const PolygonShape2D &shape);
    Shape2D CreateSegmentShape(const ShapeDef2D &def, const SegmentShape2D &shape);

    void DestroyShape(const Shape2D &shape);

    void ApplyAngularImpulse(float impulse, bool wake);
    void ApplyForce(const Vector2 &force, const Vector2 &point, bool wake);
    void ApplyForceToCenter(const Vector2 &force, bool wake);
    void ApplyLinearImpulse(const Vector2 &impulse, const Vector2 &point, bool wake);
    void ApplyLinearImpulseToCenter(const Vector2 &impulse, bool wake);
    void ApplyMassFromShapes();
    void ApplyTorque(float torque, bool wake);
    void Disable();
    void Enable();
    void EnableHitEvents(bool enabled);
    void EnableSleep(bool enabled);

private:
    b2BodyId m_BodyID;
};

} // namespace Lumen