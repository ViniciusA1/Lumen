#include "Lumen/Physics2D/ShapeTemplates2D.hpp"
#include "Lumen/Math/Math.hpp"

#include "box2d/collision.h"

namespace Lumen
{

CapsuleShape2D::operator b2Capsule() const
{
    return {Center1, Center2, Radius};
}

CircleShape2D::operator b2Circle() const
{
    return {Center, Radius};
}

PolygonShape2D::operator b2Polygon() const
{
    b2Polygon poly;

    poly.centroid = Centroid;
    poly.count = Count;
    poly.radius = Radius;

    for (int i = 0; i < 4; i++)
    {
        poly.vertices[i] = Vertices[i];
        poly.normals[i] = Normals[i];
    }

    return poly;
}

SegmentShape2D::operator b2Segment() const
{
    return {Point1, Point2};
}

static PolygonShape2D ConvertShape(const b2Polygon &polygon)
{
    PolygonShape2D poly;

    poly.Centroid = polygon.centroid;
    poly.Count = polygon.count;
    poly.Radius = polygon.radius;

    for (int i = 0; i < 4; i++)
    {
        poly.Vertices[i] = polygon.vertices[i];
        poly.Normals[i] = polygon.normals[i];
    }

    return poly;
}

PolygonShape2D ShapeFactory2D::CreateBox(const Vector2 &size)
{
    b2Polygon poly = b2MakeBox(size.x, size.y);
    return ConvertShape(poly);
}

CapsuleShape2D ShapeFactory2D::CreateCapsule(const Vector2 &center1,
                                             const Vector2 &center2, float radius)
{
    return {center1, center2, radius};
}

CircleShape2D ShapeFactory2D::CreateCircle(const Vector2 &center, float radius)
{
    return {center, radius};
}

PolygonShape2D ShapeFactory2D::CreateOffsetBox(const Vector2 &size, const Vector2 &center,
                                               float angle)
{
    b2Polygon poly = b2MakeOffsetBox(size.x, size.y, center, angle);
    return ConvertShape(poly);
}

PolygonShape2D ShapeFactory2D::CreateOffsetPolygon(
    const std::array<Vector2, MAX_POLYGON_VERTICES> &vertices, float radius,
    const Vector2 &position, float rotation)
{
    b2Hull hull =
        b2ComputeHull(reinterpret_cast<const b2Vec2 *>(vertices.data()), vertices.size());

    b2Polygon poly = b2MakeOffsetPolygon(
        &hull, radius, {position, {Math::Cos(rotation), Math::Sign(rotation)}});

    return ConvertShape(poly);
}

PolygonShape2D ShapeFactory2D::CreatePolygon(
    const std::array<Vector2, MAX_POLYGON_VERTICES> &vertices, float radius)
{
    b2Hull hull =
        b2ComputeHull(reinterpret_cast<const b2Vec2 *>(vertices.data()), vertices.size());

    b2Polygon poly = b2MakePolygon(&hull, radius);

    return ConvertShape(poly);
}

PolygonShape2D ShapeFactory2D::CreateRoundedBox(const Vector2 &size, float radius)
{
    b2Polygon poly = b2MakeRoundedBox(size.x, size.y, radius);
    return ConvertShape(poly);
}

SegmentShape2D ShapeFactory2D::CreateSegment(const Vector2 &point1, const Vector2 &point2)
{
    return {point1, point2};
}

PolygonShape2D ShapeFactory2D::CreateSquare(float size)
{
    return CreateBox({size, size});
}

} // namespace Lumen