#pragma once

#include "Lumen/Math/Vector3.hpp"

namespace Lumen
{

struct TransformComponent
{
    Vector3 Position = {0.0f, 0.0f, 0.0f};
    Vector3 Rotation = {0.0f, 0.0f, 0.0f};
    Vector3 Scale = {1.0f, 1.0f, 1.0f};
};

} // namespace Lumen