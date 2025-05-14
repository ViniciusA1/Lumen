#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector4.hpp"

#include "raymath.h"

namespace Lumen
{

const Vector3 Vector3::One = {1, 1, 1};
const Vector3 Vector3::Zero = {0, 0, 0};

Vector3::Vector3(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f)
{
}

Vector3::Vector3(const Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

Vector3::Vector3(const ::Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

Vector3::operator ::Vector3() const
{
    return {x, y, z};
}

} // namespace Lumen