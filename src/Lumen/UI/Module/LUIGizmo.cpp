#include "Lumen/UI/Module/LUIGizmo.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Matrix4.hpp"

#include "imgui.h"

#include "ImGuizmo.h"

namespace Lumen::LUI::Gizmo
{

void CubeView(CameraComponent &camera, float length, const Vector2 &position,
              const Vector2 &size, const Color &backgroundColor)
{
    Matrix4 view = Matrix4::LookAt(camera.Position, camera.Target, camera.Up);

    ImGuizmo::ViewManipulate(view.ToFloat16().data(), length, {position.x, position.y},
                             {size.x, size.y},
                             IM_COL32(backgroundColor.r, backgroundColor.g,
                                      backgroundColor.b, backgroundColor.a));

    if (ImGuizmo::IsUsingViewManipulate())
        Matrix4::DecomposeView(view, camera.Position, camera.Target, camera.Up);
}

void Camera(const CameraComponent &camera, const Color &color)
{
    const Vector3 position = camera.Position;
    const Vector3 forward = (camera.Target - camera.Position).Normalized();
    const Vector3 up = camera.Up.Normalized();
    const Vector3 right = Vector3::Cross(forward, up).Normalized();

    float near = camera.Near;
    float far = camera.Far;

    Vector3 nearCenter = position + forward * near;
    Vector3 farCenter = position + forward * far;

    if (camera.Projection == ProjectionType::Perspective)
    {
        float fov = camera.Fov * Math::Deg2Rad;
        float aspect = camera.AspectRatio;

        float nearHeight = 2.0f * tanf(fov / 2.0f) * near;
        float nearWidth = nearHeight * aspect;
        float farHeight = 2.0f * tanf(fov / 2.0f) * far;
        float farWidth = farHeight * aspect;

        Vector3 nearUp = up * (nearHeight * 0.5f);
        Vector3 nearRight = right * (nearWidth * 0.5f);
        Vector3 farUp = up * (farHeight * 0.5f);
        Vector3 farRight = right * (farWidth * 0.5f);

        Vector3 ntl = nearCenter + nearUp - nearRight;
        Vector3 ntr = nearCenter + nearUp + nearRight;
        Vector3 nbl = nearCenter - nearUp - nearRight;
        Vector3 nbr = nearCenter - nearUp + nearRight;

        Vector3 ftl = farCenter + farUp - farRight;
        Vector3 ftr = farCenter + farUp + farRight;
        Vector3 fbl = farCenter - farUp - farRight;
        Vector3 fbr = farCenter - farUp + farRight;

        Renderer::DrawLine(ntl, ntr, color);
        Renderer::DrawLine(ntr, nbr, color);
        Renderer::DrawLine(nbr, nbl, color);
        Renderer::DrawLine(nbl, ntl, color);

        Renderer::DrawLine(ftl, ftr, color);
        Renderer::DrawLine(ftr, fbr, color);
        Renderer::DrawLine(fbr, fbl, color);
        Renderer::DrawLine(fbl, ftl, color);

        Renderer::DrawLine(ntl, ftl, color);
        Renderer::DrawLine(ntr, ftr, color);
        Renderer::DrawLine(nbl, fbl, color);
        Renderer::DrawLine(nbr, fbr, color);
    }
    else
    {
        float orthoHeight = camera.OrthographicSize * 2.0f;
        float orthoWidth = orthoHeight * camera.AspectRatio;

        Vector3 halfUp = up * (orthoHeight * 0.5f);
        Vector3 halfRight = right * (orthoWidth * 0.5f);

        Vector3 ntl = nearCenter + halfUp - halfRight;
        Vector3 ntr = nearCenter + halfUp + halfRight;
        Vector3 nbl = nearCenter - halfUp - halfRight;
        Vector3 nbr = nearCenter - halfUp + halfRight;

        Vector3 ftl = farCenter + halfUp - halfRight;
        Vector3 ftr = farCenter + halfUp + halfRight;
        Vector3 fbl = farCenter - halfUp - halfRight;
        Vector3 fbr = farCenter - halfUp + halfRight;

        Renderer::DrawLine(ntl, ntr, color);
        Renderer::DrawLine(ntr, nbr, color);
        Renderer::DrawLine(nbr, nbl, color);
        Renderer::DrawLine(nbl, ntl, color);

        Renderer::DrawLine(ftl, ftr, color);
        Renderer::DrawLine(ftr, fbr, color);
        Renderer::DrawLine(fbr, fbl, color);
        Renderer::DrawLine(fbl, ftl, color);

        Renderer::DrawLine(ntl, ftl, color);
        Renderer::DrawLine(ntr, ftr, color);
        Renderer::DrawLine(nbl, fbl, color);
        Renderer::DrawLine(nbr, fbr, color);
    }
}

void Grid(CameraComponent &camera, float minorSpacing, int majorDivisions, int gridLines,
          Color minorColor, Color majorColor, bool xyPlane)
{
    Renderer::DrawGrid(camera.Position, minorSpacing, majorDivisions, gridLines,
                       minorColor, majorColor, xyPlane);
}

void Transform(TransformComponent &transform, CameraComponent &camera,
               const Rectangle &viewport, TransformOperation operation,
               TransformMode mode, const float *snap)
{
    Matrix4 view = Matrix4::LookAt(camera.Position, camera.Target, camera.Up);

    float aspectRatio = viewport.Width / viewport.Height;
    Matrix4 projection;
    if (camera.Projection == ProjectionType::Perspective)
    {
        projection = Matrix4::Perspective(camera.Fov * Math::Deg2Rad, aspectRatio,
                                          camera.Near, camera.Far);
    }
    else
    {
        float orthoHeight = camera.OrthographicSize * 2.0f;
        float orthoWidth = orthoHeight * aspectRatio;

        projection =
            Matrix4::Ortho(-orthoWidth * 0.5f, orthoWidth * 0.5f, -orthoHeight * 0.5f,
                           orthoHeight * 0.5f, camera.Near, camera.Far);
    }

    Matrix4 model;
    ImGuizmo::RecomposeMatrixFromComponents(&transform.Position.x, &transform.Rotation.x,
                                            &transform.Scale.x, model.ToFloat16().data());

    ImGuizmo::SetOrthographic(camera.Projection == ProjectionType::Orthographic);
    ImGuizmo::SetRect(viewport.x, viewport.y, viewport.Width, viewport.Height);
    ImGuizmo::SetDrawlist();

    ImGuizmo::Manipulate(view.ToFloat16().data(), projection.ToFloat16().data(),
                         static_cast<ImGuizmo::OPERATION>(operation),
                         static_cast<ImGuizmo::MODE>(mode), model.ToFloat16().data(),
                         nullptr, snap);

    if (ImGuizmo::IsUsing())
    {
        ImGuizmo::DecomposeMatrixToComponents(model.ToFloat16().data(),
                                              &transform.Position.x,
                                              &transform.Rotation.x, &transform.Scale.x);
    }
}

} // namespace Lumen::LUI::Gizmo