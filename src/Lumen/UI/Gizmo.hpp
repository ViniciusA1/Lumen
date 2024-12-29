#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Entity/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/CameraComponent.hpp"

namespace Lumen
{

class Gizmo
{
public:
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

        Translate = TranslateX | TranslateY | TranslateZ,
        Rotate = RotateX | RotateY | RotateZ | RotateScreen,
        Scale = ScaleX | ScaleY | ScaleZ,
        ScaleU = ScaleXU | ScaleYU | ScaleZU,
        Universal = Translate | Rotate | ScaleU
    };

    enum class TransformMode
    {
        Local,
        World
    };

public:
    Gizmo() = delete;

    static void DrawCubeView(CameraComponent &camera, float length,
                             const Vector2 &position, const Vector2 &size,
                             const Color &backgroundColor);

    static void DrawTransform(TransformComponent &transform,
                              const CameraComponent &camera, const Rectangle &viewport,
                              TransformOperation operation, TransformMode mode,
                              const float *snap = nullptr);
};

} // namespace Lumen