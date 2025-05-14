#include "Lumen/Math/Vector4.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"

#include "imgui.h"
#include "raymath.h"

namespace Lumen
{

const Vector4 Vector4::One = {1, 1, 1, 1};
const Vector4 Vector4::Zero = {0, 0, 0, 0};

Vector4::Vector4(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f)
{
}

Vector4::Vector4(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f)
{
}

Vector4::Vector4(const ::Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{
}

Vector4::Vector4(const ::ImVec4 &vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{
}

Vector4::operator ::Vector4() const
{
    return ::Vector4{x, y, z, w};
}

Vector4::operator ::ImVec4() const
{
    return ::ImVec4{x, y, z, w};
}

} // namespace Lumen