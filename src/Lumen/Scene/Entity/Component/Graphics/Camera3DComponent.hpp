#pragma once

#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

enum class ProjectionType
{
    Perspective,
    Orthographic
};

struct Camera3DComponent : public ComponentBase
{
    Vector3 Position;
    Vector3 Target;
    Vector3 Up;
    float Fov;
    ProjectionType Projection;

    Camera3DComponent() = default;
    Camera3DComponent(const Vector3 &positon, const Vector3 &target, const Vector3 &up,
                      float fov, ProjectionType type)
        : Position(positon), Target(target), Up(up), Fov(fov), Projection(type)
    {
    }
};

} // namespace Lumen