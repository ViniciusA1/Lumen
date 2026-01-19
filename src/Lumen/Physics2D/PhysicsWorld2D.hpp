#pragma once

#include "Lumen/Event/PhysicsEvent2D.hpp"
#include "Lumen/Physics2D/Body2D.hpp"
#include "Lumen/Physics2D/BodyDef2D.hpp"
#include "Lumen/Physics2D/PhysicsWorldCounters2D.hpp"
#include "Lumen/Physics2D/PhysicsWorldDef2D.hpp"
#include "Lumen/Physics2D/PhysicsWorldProfile2D.hpp"

#include "box2d/id.h"

namespace Lumen
{

class PhysicsWorld2D
{
public:
    PhysicsWorld2D(const PhysicsWorldDef2D &worldDef = {});
    ~PhysicsWorld2D();

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Body2DEvents GetBodyEvents() const;
    [[nodiscard]] Contact2DEvents GetContactEvents() const;
    [[nodiscard]] PhysicsWorldCounters2D GetCounters() const;
    [[nodiscard]] Vector2 GetGravity() const;
    [[nodiscard]] PhysicsWorldProfile2D GetProfile() const;
    [[nodiscard]] Sensor2DEvents GetSensorEvents() const;
    [[nodiscard]] b2WorldId GetWorldID() const;

    Body2D CreateBody(const BodyDef2D &bodyDef = {});

    void DestroyBody(const Body2D &body);

    void Update(float timeStep, int subStepCount);

private:
    b2WorldId m_WorldID;
};

} // namespace Lumen