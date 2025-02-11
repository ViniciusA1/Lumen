#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Matrix4.hpp"

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

namespace Lumen
{

static ::RenderTexture s_RenderTexture = {0};

void Renderer::BeginBlendMode()
{
    ::BeginBlendMode(0);
}

void Renderer::BeginCameraMode(const CameraComponent &camera)
{
    ::BeginMode3D({camera.Position, camera.Target, camera.Up, camera.Fov,
                   static_cast<int>(camera.Projection)});
}

void Renderer::BeginDrawing()
{
    ::BeginDrawing();
}

void Renderer::BeginScissorMode(const Rectangle &region)
{
    ::BeginScissorMode(region.x, region.y, region.Width, region.Height);
}

void Renderer::BeginShaderMode(const Ref<Shader> &shader)
{
    ::BeginShaderMode(*shader);
}

void Renderer::BeginTextureMode()
{
    ::BeginTextureMode(s_RenderTexture);
}

void Renderer::EndBlendMode()
{
    ::EndBlendMode();
}

void Renderer::EndCameraMode()
{
    ::EndMode3D();
}

void Renderer::EndDrawing()
{
    ::EndDrawing();
}

void Renderer::EndScissorMode()
{
    ::EndScissorMode();
}

void Renderer::EndShaderMode()
{
    ::EndShaderMode();
}

void Renderer::EndTextureMode()
{
    ::EndTextureMode();
}

void Renderer::ClearBackground(Color color)
{
    ::ClearBackground(color);
}

void Renderer::CreateDefaultRenderTexture()
{
    s_RenderTexture = ::LoadRenderTexture(0, 0);
}

RenderTexture &Renderer::GetRenderTexture()
{
    return s_RenderTexture;
}

void Renderer::ResizeRenderTexture(int width, int height)
{
    ::Texture texture = s_RenderTexture.texture;

    if (texture.width != width || texture.height != height)
    {
        ::UnloadRenderTexture(s_RenderTexture);
        s_RenderTexture = LoadRenderTexture(width, height);
    }
}

void Renderer::SetRenderTexture(const ::RenderTexture texture)
{
    s_RenderTexture = texture;
}

void Renderer::DrawFPS(const Vector2 position, int size, Color color)
{
    std::string fps = std::to_string(::GetFPS());
    ::DrawText(fps.c_str(), position.x, position.y, size, color);
}

void Renderer::DrawCapsule(const TransformComponent &transform, int slices, int rings,
                           Color color)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCapsule({0.0f, -0.5f, 0.0f}, {0.0f, 0.5f, 0.0f}, 0.5f, slices, rings, color);

    rlPopMatrix();
}

void Renderer::DrawCapsuleWire(const TransformComponent &transform, int slices, int rings,
                               Color color)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCapsuleWires({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 0.5f, slices, rings,
                       color);

    rlPopMatrix();
}

void Renderer::DrawCircle(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCircle3D(transform.Position, 1.0f, {0.0f, 0.0f, 0.0f}, 0, color);

    rlPopMatrix();
}

void Renderer::DrawCube(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeV(transform.Position, transform.Scale, color);

    rlPopMatrix();
}

void Renderer::DrawCubeWire(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeWiresV(transform.Position, transform.Scale, color);

    rlPopMatrix();
}

void Renderer::DrawCylinder(const TransformComponent &transform, int slices, Color color)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinder({0.0f, -0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, slices, color);

    rlPopMatrix();
}

void Renderer::DrawCylinder(const TransformComponent &transform, float radiusTop,
                            float radiusBottom, int slices, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinder(transform.Position, radiusTop, radiusBottom, 1.0f, slices, color);

    rlPopMatrix();
}

void Renderer::DrawCylinderWire(const TransformComponent &transform, int slices,
                                Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinderWires(transform.Position, 1.0f, 1.0f, 1.0f, slices, color);

    rlPopMatrix();
}

void Renderer::DrawCylinderWire(const TransformComponent &transform, float radiusTop,
                                float radiusBottom, int slices, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinderWires(transform.Position, radiusTop, radiusBottom, 1.0f, slices, color);

    rlPopMatrix();
}

void Renderer::DrawGrid(Vector3 cameraPosition, float minorSpacing, int majorDivisions,
                        int gridLines)
{
    float halfGridSize = minorSpacing * gridLines;

    minorSpacing = Math::Clamp((int)cameraPosition.y / 50, 1, majorDivisions);
    majorDivisions += minorSpacing;

    float startX =
        Math::Floor((cameraPosition.x - halfGridSize) / minorSpacing) * minorSpacing;
    float endX =
        Math::Floor((cameraPosition.x + halfGridSize) / minorSpacing) * minorSpacing;
    float startZ =
        Math::Floor((cameraPosition.z - halfGridSize) / minorSpacing) * minorSpacing;
    float endZ =
        Math::Floor((cameraPosition.z + halfGridSize) / minorSpacing) * minorSpacing;

    for (float x = startX; x <= endX; x += minorSpacing)
    {
        bool isMajorLine = ((int)(x / minorSpacing) % majorDivisions) == 0;
        Color lineColor = isMajorLine ? LIGHTGRAY : DARKGRAY;
        DrawLine3D((Vector3){x, 0, startZ}, (Vector3){x, 0, endZ}, lineColor);
    }

    for (float z = startZ; z <= endZ; z += minorSpacing)
    {
        bool isMajorLine = ((int)(z / minorSpacing) % majorDivisions) == 0;
        Color lineColor = isMajorLine ? LIGHTGRAY : DARKGRAY;
        DrawLine3D((Vector3){startX, 0, z}, (Vector3){endX, 0, z}, lineColor);
    }
}

void Renderer::DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color)
{
    ::DrawLine3D(startPos, endPos, color);
}

void Renderer::DrawPlane(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawPlane(transform.Position, {transform.Scale.x, transform.Scale.y}, color);

    rlPopMatrix();
}

void Renderer::DrawPixel(const Vector2 &position, Color color)
{
    ::DrawPixelV(position, color);
}

void Renderer::DrawPoint(const Vector3 &position, Color color)
{
    ::DrawPoint3D(position, color);
}

void Renderer::DrawQuad(const TransformComponent &transform, Color color, float roundness,
                        int segments)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, 1.0f);

    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    rlVertex3f(-0.5f, -0.5f, 0.0f);
    rlVertex3f(0.5f, -0.5f, 0.0f);
    rlVertex3f(0.5f, 0.5f, 0.0f);
    rlVertex3f(-0.5f, 0.5f, 0.0f);
    rlEnd();

    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    rlVertex3f(-0.5f, -0.5f, 0.0f);
    rlVertex3f(-0.5f, 0.5f, 0.0f);
    rlVertex3f(0.5f, 0.5f, 0.0f);
    rlVertex3f(0.5f, -0.5f, 0.0f);
    rlEnd();

    rlPopMatrix();
}

void Renderer::DrawQuadLines(const TransformComponent &transform, Color color,
                             float roundness, int segments)
{
}

void Renderer::DrawSphere(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphere(transform.Position, 1.0f, color);

    rlPopMatrix();
}

void Renderer::DrawSphere(const TransformComponent &transform, int rings, int slices,
                          Color color)
{
    rlPushMatrix();

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphereEx(transform.Position, 1.0f, rings, slices, color);

    rlPopMatrix();
}

void Renderer::DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3,
                            Color color)
{
    ::DrawTriangle3D(v1, v2, v3, color);
}

void Renderer::DrawMesh(const TransformComponent &transform, const Mesh &mesh,
                        const Material &material)
{
    ::DrawMesh(mesh, material, Matrix4::Transform(transform));
}

} // namespace Lumen