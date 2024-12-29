#include "Lumen/Graphics/Renderer.hpp"

#include "Lumen/Math/Math.hpp"
#include "raylib.h"
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
    ::BeginScissorMode(region.X, region.Y, region.Width, region.Height);
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

void Renderer::DrawQuad(const TransformComponent &transform, Color color)
{
}

void Renderer::DrawCube(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);

    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCube(Vector3::Zero, 1.0f, 1.0f, 1.0f, color);

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

} // namespace Lumen