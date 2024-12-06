#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Core/Application.hpp"
#include <raylib.h>

namespace Lumen
{

Color Renderer::s_Color = Color::Black;
static ::RenderTexture s_SceneRenderTexture;

void Renderer::BeginRenderTexture()
{
    BeginTextureMode(s_SceneRenderTexture);
}

void Renderer::EndRenderTexture()
{
    EndTextureMode();
}

void Renderer::CreateRenderTexture()
{
    Vector2 winSize = Application::Get().GetWindow().GetSize();
    s_SceneRenderTexture = LoadRenderTexture(winSize.x, winSize.y);
}

void Renderer::DestroyRenderTexture()
{
    UnloadRenderTexture(s_SceneRenderTexture);
}

::RenderTexture &Renderer::GetRenderTexture()
{
    return s_SceneRenderTexture;
}

void Renderer::ResizeRenderTexture(int width, int height)
{
    ::Texture texture = s_SceneRenderTexture.texture;

    if (texture.width != width || texture.height != height)
    {
        UnloadRenderTexture(s_SceneRenderTexture);
        s_SceneRenderTexture = LoadRenderTexture(width, height);
    }
}

void Renderer::BeginDrawing()
{
    ::BeginDrawing();
}

void Renderer::EndDrawing()
{
    ::EndDrawing();
}

void Renderer::Clear()
{
    ::ClearBackground(s_Color);
}

void Renderer::Begin2DMode()
{
    ::BeginMode2D({});
}

void Renderer::DrawQuad(const Vector2 &position, const Vector2 &size, const Color &color)
{
    ::DrawRectangleV({position.x - (size.x / 2), position.y - (size.y / 2)}, size, color);
}

void Renderer::DrawQuad(const Vector2 &position, float rotation, const Vector2 &size,
                        const Color &color)
{
    ::DrawRectanglePro(
        {position.x - (size.x / 2), position.y - (size.y / 2), size.x, size.y}, {0, 0},
        rotation, color);
}

void Renderer::DrawText(const std::string &text, const Vector2 &position, int fontSize,
                        const Color &color)
{
    ::DrawText(text.c_str(), position.x, position.y, fontSize, color);
}

void Renderer::DrawFPS(const Vector2 &position, int fontSize, const Color &color)
{
    ::DrawFPS(position.x, position.y);
}

void Renderer::End2DMode()
{
    ::EndMode2D();
}

void Renderer::BeginMode3D(const CameraComponent &camera)
{
    ::BeginMode3D({camera.Position, camera.Target, camera.Up, camera.Fov,
                   static_cast<int>(camera.Projection)});
}

void Renderer::EndMode3D()
{
    ::EndMode3D();
}

} // namespace Lumen