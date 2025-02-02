#pragma once

#include "Lumen/Physics2D/Body2D.hpp"

namespace Lumen
{

class SensorBeginTouch2DEvent
{
public:
    Shape2D SensorShape;
    Shape2D VisitorShape;
};

class SensorEndTouch2DEvent
{
public:
    Shape2D SensorShape;
    Shape2D VisitorShape;
};

struct Sensor2DEvents
{
    std::vector<SensorBeginTouch2DEvent> BeginEvents;
    std::vector<SensorEndTouch2DEvent> EndEvents;
};

class ContactBeginTouch2DEvent
{
public:
    Shape2D ShapeA;
    Shape2D ShapeB;
};

class ContactEndTouch2DEvent
{
public:
    Shape2D ShapeA;
    Shape2D ShapeB;
};

class ContactHit2DEvent
{
public:
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

class BodyMove2DEvent
{
public:
    Transform2D Transform;
    Body2D Body;
    bool FellAsleep;
};

struct Body2DEvents
{
    std::vector<BodyMove2DEvent> MoveEvents;
};

} // namespace Lumen