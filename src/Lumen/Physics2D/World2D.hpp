#pragma once

#include "Lumen/Event/PhysicsEvent2D.hpp"
#include "Lumen/Physics2D/Body2D.hpp"
#include "Lumen/Physics2D/BodyDef2D.hpp"
#include "Lumen/Physics2D/WorldDef2D.hpp"

#include "box2d/id.h"

namespace Lumen
{

class World2D
{
public:
    World2D(const WorldDef2D &worldDef = {});
    ~World2D();

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Body2DEvents GetBodyEvents() const;
    [[nodiscard]] Contact2DEvents GetContactEvents() const;
    [[nodiscard]] WorldCounters2D GetCounters() const;
    [[nodiscard]] Vector2 GetGravity() const;
    [[nodiscard]] WorldProfile2D GetProfile() const;
    [[nodiscard]] Sensor2DEvents GetSensorEvents() const;
    [[nodiscard]] b2WorldId GetWorldID() const;

    Body2D CreateBody(const BodyDef2D &bodyDef = {});

    void DestroyBody(const Body2D &body);

    void Update(float timeStep, int subStepCount);

private:
    b2WorldId m_WorldID;
};

} // namespace Lumen