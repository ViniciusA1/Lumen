#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Core/Application.hpp"
#include <raylib.h>

namespace Lumen
{

Color Renderer::s_Color = Color::Black;
static RenderTexture s_SceneRenderTexture;

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
    Window &window = Application::Get().GetWindow();
    s_SceneRenderTexture = LoadRenderTexture(window.GetWidth(), window.GetHeight());
}

void Renderer::DestroyRenderTexture()
{
    UnloadRenderTexture(s_SceneRenderTexture);
}

RenderTexture &Renderer::GetRenderTexture()
{
    return s_SceneRenderTexture;
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

void Renderer::DrawQuad(const Matrix4 &transform, const Color &color)
{
    Vector3 position = transform.GetPosition();
    Quaternion rotation = transform.GetRotation();
    Vector3 size = transform.GetScale();
    float floatRotation = 0;
    Vector3 axis;
    rotation.ToAngleAxis(floatRotation, axis);
    Renderer::DrawQuad({position.x, position.y}, floatRotation, {size.x, size.y}, color);
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

} // namespace Lumen