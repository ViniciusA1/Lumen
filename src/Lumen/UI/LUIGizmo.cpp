#include "Lumen/UI/LUIGizmo.hpp"
#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Matrix4.hpp"

#include "imgui.h"

#include "ImGuizmo.h"

namespace Lumen
{

void LUIGizmo::DrawCubeView(CameraComponent &camera, float length,
                            const Vector2 &position, const Vector2 &size,
                            const Color &backgroundColor)
{
    Matrix4 view = Matrix4::LookAt(camera.Position, camera.Target, camera.Up);
    ImGuizmo::ViewManipulate(view.ToFloat16().data(), length, {position.x, position.y},
                             {size.x, size.y},
                             IM_COL32(backgroundColor.r, backgroundColor.g,
                                      backgroundColor.b, backgroundColor.a));

    if (ImGuizmo::IsUsingViewManipulate())
    {
        Matrix4::DecomposeView(view, camera.Position, camera.Target, camera.Up);
    }
}

void LUIGizmo::DrawTransform(TransformComponent &transform, const CameraComponent &camera,
                             const Rectangle &viewport, TransformOperation operation,
                             TransformMode mode, const float *snap)
{
    Matrix4 view = Matrix4::LookAt(camera.Position, camera.Target, camera.Up);
    Matrix4 projection = Matrix4::Perspective(
        camera.Fov * Math::Deg2Rad, viewport.Width / viewport.Height, 0.01f, 1000.0f);
    Matrix4 model =
        Matrix4::Transform(transform.Position, transform.Rotation, transform.Scale);

    ImGuizmo::SetOrthographic(camera.Projection == ProjectionType::Orthographic);
    ImGuizmo::SetRect(viewport.x, viewport.y, viewport.Width, viewport.Height);
    ImGuizmo::SetDrawlist();

    ImGuizmo::Manipulate(view.ToFloat16().data(), projection.ToFloat16().data(),
                         static_cast<ImGuizmo::OPERATION>(operation),
                         static_cast<ImGuizmo::MODE>(mode), model.ToFloat16().data(),
                         nullptr, snap);

    if (ImGuizmo::IsUsing())
    {
        Matrix4::DecomposeTransform(model, transform.Position, transform.Rotation,
                                    transform.Scale);
    }
}

} // namespace Lumen