#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

namespace Lumen
{

struct SensorBeginTouch2DEvent
{
    Shape2D SensorShape;
    Shape2D VisitorShape;
};

struct SensorEndTouch2DEvent
{
    Shape2D SensorShape;
    Shape2D VisitorShape;
};

struct Sensor2DEvents
{
    std::vector<SensorBeginTouch2DEvent> BeginEvents;
    std::vector<SensorEndTouch2DEvent> EndEvents;
};

struct ContactBeginTouch2DEvent
{
    Shape2D ShapeA;
    Shape2D ShapeB;
};

struct ContactEndTouch2DEvent
{
    Shape2D ShapeA;
    Shape2D ShapeB;
};

struct ContactHit2DEvent
{
    Shape2D ShapeA;
    Shape2D ShapeB;
    Vector2 Point;
    Vector2 Normal;
    float ApproachSpeed;
};

struct Contact2DEvents
{
    std::vector<ContactBeginTouch2DEvent> BeginEvents;
    std::vector<ContactEndTouch2DEvent> EndEvents;
    std::vector<ContactHit2DEvent> HitEvents;
};

struct BodyMove2DEvent
{
    Transform2D Transform;
    Body2D Body;
    bool FellAsleep;
};

struct Body2DEvents
{
    std::vector<BodyMove2DEvent> MoveEvents;
};

} // namespace Lumen