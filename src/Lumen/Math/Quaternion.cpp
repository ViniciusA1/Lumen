#include "Lumen/Math/Quaternion.hpp"

#include "raymath.h"

namespace Lumen
{

const Quaternion Quaternion::Identity = {0.0f, 0.0f, 0.0f, 1.0f};

Quaternion::Quaternion(const ::Vector4 &quaternion)
    : x(quaternion.x), y(quaternion.y), z(quaternion.z), w(quaternion.w)
{
}

Quaternion::operator ::Vector4() const
{
    return {x, y, z, w};
}

} // namespace Lumen