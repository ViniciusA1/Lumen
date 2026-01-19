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
    Vector3 Position = {0.0f, 0.0f, 0.0f};
    Vector3 Target = {1.0f, 0.0f, 0.0f};
    Vector3 Up = {0.0f, 1.0f, 0.0f};
    float Fov = 60.0f;
    float OrthographicSize = 5.0f;
    float Near = 0.1f;
    float Far = 1000.0f;
    float AspectRatio = 16.0f / 9.0f;
    ProjectionType Projection = ProjectionType::Perspective;
};

} // namespace Lumen