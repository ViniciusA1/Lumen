#pragma once

#include "Lumen/Math/Vector3.hpp"

namespace Lumen
{

enum class ProjectionType
{
    Perspective,
    Orthographic
};

struct CameraComponent
{
    Vector3 Position = {10.0f, 10.0f, 10.0f};
    Vector3 Target = {0.0f, 0.0f, 0.0f};
    Vector3 Up = {0.0f, 1.0f, 0.0f};
    float Fov = 60.0f;
    ProjectionType Projection = ProjectionType::Perspective;

    CameraComponent() = default;
    CameraComponent(const Vector3 &position, const Vector3 &target, const Vector3 &up,
                    float fov, ProjectionType type)
        : Position(position), Target(target), Up(up), Fov(fov), Projection(type)
    {
    }
};

} // namespace Lumen