#include "Lumen/Math/Vector.hpp"
#include <raymath.h>

namespace Lumen
{

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

::Vector2 Vector2::ToRaylib() const
{
    return {x, y};
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

::Vector3 Vector3::ToRaylib() const
{
    return {x, y, z};
}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

::Vector4 Vector4::ToRaylib() const
{
    return {x, y, z, w};
}

} // namespace Lumen