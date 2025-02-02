#pragma once

#include "Lumen/Math/Vector2.hpp"

#include <array>
#include <cstdint>

#define MAX_POLYGON_VERTICES 8

struct b2Capsule;
struct b2Circle;
struct b2Polygon;
struct b2Segment;

namespace Lumen
{

struct CapsuleShape2D
{
    Vector2 Center1;
    Vector2 Center2 = {1, 1};
    float Radius = 1;

    operator b2Capsule() const;
};

struct CircleShape2D
{
    Vector2 Center;
    float Radius = 1;

    operator b2Circle() const;
};

struct PolygonShape2D
{
    Vector2 Centroid;
    int32_t Count = 0;
    std::array<Vector2, MAX_POLYGON_VERTICES> Normals;
    float Radius = 1;
    std::array<Vector2, MAX_POLYGON_VERTICES> Vertices;

    operator b2Polygon() const;
};

struct SegmentShape2D
{
    Vector2 Point1;
    Vector2 Point2;

    operator b2Segment() const;
};

class ShapeFactory2D
{
public:
    ShapeFactory2D() = delete;

    static PolygonShape2D CreateBox(const Vector2 &size);

    static CapsuleShape2D CreateCapsule(const Vector2 &center1, const Vector2 &center2,
                                        float radius);

    static CircleShape2D CreateCircle(const Vector2 &center, float radius);

    static PolygonShape2D CreateOffsetBox(const Vector2 &size, const Vector2 &center,
                                          float angle);

    static PolygonShape2D CreateOffsetPolygon(
        const std::array<Vector2, MAX_POLYGON_VERTICES> &vertices, float radius,
        const Vector2 &position, float rotation);

    static PolygonShape2D CreatePolygon(
        const std::array<Vector2, MAX_POLYGON_VERTICES> &vertices, float radius);

    static PolygonShape2D CreateRoundedBox(const Vector2 &size, float radius);

    static SegmentShape2D CreateSegment(const Vector2 &point1, const Vector2 &point2);

    static PolygonShape2D CreateSquare(float height);
};

} // namespace Lumen