#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"

#include "box2d/math_functions.h"
#include "imgui.h"
#include "raymath.h"

namespace Lumen
{

Vector2::Vector2(const Vector3 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const Vector4 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::Vector2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::ImVec2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::Vector2(const ::b2Vec2 &vec) : x(vec.x), y(vec.y)
{
}

Vector2::operator ::Vector2() const
{
    return {x, y};
}

Vector2::operator ::ImVec2() const
{
    return {x, y};
}

Vector2::operator ::b2Vec2() const
{
    return {x, y};
}

} // namespace Lumen