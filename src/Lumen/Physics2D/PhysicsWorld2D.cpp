#include "Lumen/Physics2D/PhysicsWorld2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

PhysicsWorld2D::PhysicsWorld2D(const PhysicsWorldDef2D &worldDef)
{
    b2WorldDef def = worldDef;
    m_WorldID = b2CreateWorld(&def);
}

PhysicsWorld2D::~PhysicsWorld2D()
{
    b2DestroyWorld(m_WorldID);
}

Body2DEvents PhysicsWorld2D::GetBodyEvents() const
{
    b2BodyEvents events = b2World_GetBodyEvents(m_WorldID);

    Body2DEvents bodyEvents;
    for (int i = 0; i < events.moveCount; i++)
    {
        BodyMove2DEvent moveEvent = {events.moveEvents[i].transform,
                                     events.moveEvents[i].bodyId,
                                     events.moveEvents[i].fellAsleep};
        bodyEvents.MoveEvents.push_back(moveEvent);
    }

    return bodyEvents;
}

Contact2DEvents PhysicsWorld2D::GetContactEvents() const
{
    b2ContactEvents events = b2World_GetContactEvents(m_WorldID);

    Contact2DEvents contactEvents;
    for (int i = 0; i < events.beginCount; i++)
    {
        ContactBeginTouch2DEvent contactEvent = {events.beginEvents[i].shapeIdA,
                                                 events.beginEvents[i].shapeIdB};
        contactEvents.BeginEvents.push_back(contactEvent);
    }
    for (int i = 0; i < events.endCount; i++)
    {
        ContactEndTouch2DEvent contactEvent = {events.endEvents[i].shapeIdA,
                                               events.endEvents[i].shapeIdB};
        contactEvents.EndEvents.push_back(contactEvent);
    }
    for (int i = 0; i < events.hitCount; i++)
    {
        ContactHit2DEvent contactEvent = {
            events.hitEvents[i].shapeIdA, events.hitEvents[i].shapeIdB,
            events.hitEvents[i].point, events.hitEvents[i].normal,
            events.hitEvents[i].approachSpeed};
        contactEvents.HitEvents.push_back(contactEvent);
    }

    return contactEvents;
}

PhysicsWorldCounters2D PhysicsWorld2D::GetCounters() const
{
    b2Counters count = b2World_GetCounters(m_WorldID);
    return {
        count.staticBodyCount, count.bodyCount,        count.shapeCount,
        count.contactCount,    count.jointCount,       count.islandCount,
        count.stackUsed,       count.staticTreeHeight, count.treeHeight,
        count.byteCount,       count.taskCount,
    };
}

Vector2 PhysicsWorld2D::GetGravity() const
{
    b2Vec2 vec = b2World_GetGravity(m_WorldID);
    return {vec.x, vec.y};
}

PhysicsWorldProfile2D PhysicsWorld2D::GetProfile() const
{
    b2Profile prof = b2World_GetProfile(m_WorldID);
    return {
        prof.step,
        prof.pairs,
        prof.collide,
        prof.solve,
        prof.buildIslands,
        prof.solveConstraints,
        prof.prepareTasks,
        prof.solverTasks,
        prof.prepareConstraints,
        prof.integrateVelocities,
        prof.warmStart,
        prof.solveVelocities,
        prof.integratePositions,
        prof.relaxVelocities,
        prof.applyRestitution,
        prof.storeImpulses,
        prof.finalizeBodies,
        prof.splitIslands,
        prof.sleepIslands,
        prof.hitEvents,
        prof.broadphase,
        prof.continuous,
    };
}

Sensor2DEvents PhysicsWorld2D::GetSensorEvents() const
{
    b2SensorEvents events = b2World_GetSensorEvents(m_WorldID);

    Sensor2DEvents sensorEvents;
    for (int i = 0; i < events.beginCount; i++)
    {
        SensorBeginTouch2DEvent sensorEvent = {
            events.beginEvents[i].sensorShapeId,
            events.beginEvents[i].visitorShapeId,
        };
        sensorEvents.BeginEvents.push_back(sensorEvent);
    }
    for (int i = 0; i < events.endCount; i++)
    {
        SensorEndTouch2DEvent sensorEvent = {
            events.beginEvents[i].sensorShapeId,
            events.beginEvents[i].visitorShapeId,
        };
        sensorEvents.EndEvents.push_back(sensorEvent);
    }

    return sensorEvents;
}

Body2D PhysicsWorld2D::CreateBody(const BodyDef2D &bodyDef)
{
    const b2BodyDef def = bodyDef;
    return b2CreateBody(m_WorldID, &def);
}

void PhysicsWorld2D::DestroyBody(const Body2D &body)
{
    b2DestroyBody(body.GetID());
}

void PhysicsWorld2D::Update(float timeStep, int subStepCount)
{
    b2World_Step(m_WorldID, timeStep, subStepCount);
}

} // namespace Lumen