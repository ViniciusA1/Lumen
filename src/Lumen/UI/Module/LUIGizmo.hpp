#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/World/Component/Core/TransformComponent.hpp"
#include "Lumen/World/Component/Graphics/CameraComponent.hpp"

namespace Lumen::LUI::Gizmo
{

enum class Type
{
    Grid,
    Transform,
    Camera,
    CubeView,
    Count
};

enum class TransformOperation
{
    TranslateX = (1u << 0),
    TranslateY = (1u << 1),
    TranslateZ = (1u << 2),
    RotateX = (1u << 3),
    RotateY = (1u << 4),
    RotateZ = (1u << 5),
    RotateScreen = (1u << 6),
    ScaleX = (1u << 7),
    ScaleY = (1u << 8),
    ScaleZ = (1u << 9),
    Bounds = (1u << 10),
    ScaleXU = (1u << 11),
    ScaleYU = (1u << 12),
    ScaleZU = (1u << 13),

    Hand,
    Translate = TranslateX | TranslateY | TranslateZ,
    Rotate = RotateX | RotateY | RotateZ | RotateScreen,
    Scale = ScaleX | ScaleY | ScaleZ,
    ScaleU = ScaleXU | ScaleYU | ScaleZU,
    Rect,
    Universal = Translate | Rotate | ScaleU
};

enum class TransformMode
{
    Local,
    World
};

} // namespace Lumen::LUI::Gizmo

namespace Lumen::LUI::Gizmo
{

void CubeView(CameraComponent &camera, float length, const Vector2 &position,
              const Vector2 &size, const Color &backgroundColor);

void Camera(const CameraComponent &camera, const Color &color = {255, 255, 0, 255});

void Grid(CameraComponent &camera, float minorSpacing, int majorDivisions, int gridLines,
          Color minorColor = Color::DarkGray, Color majorColor = Color::LightGray,
          bool xyPlane = false);

void Transform(TransformComponent &transform, CameraComponent &camera,
               const Rectangle &viewport, TransformOperation operation,
               TransformMode mode, const float *snap = nullptr);

} // namespace Lumen::LUI::Gizmo