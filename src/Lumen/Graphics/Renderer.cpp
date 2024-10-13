#include "Lumen/Graphics/Renderer.hpp"
#include <raylib.h>

namespace Lumen
{

Color Renderer::s_Color = Color::Black;

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
    ::ClearBackground(s_Color.ToRaylib());
}

void Renderer::DrawQuad(const Vector2 &position, const Vector2 &size, const Color &color)
{
    ::DrawRectangleV({position.x - (size.x / 2), position.y - (size.y / 2)},
                     size.ToRaylib(), color.ToRaylib());
}

void Renderer::DrawQuad(const Vector2 &position, float rotation, const Vector2 &size,
                        const Color &color)
{
    ::DrawRectanglePro(
        {position.x - (size.x / 2), position.y - (size.y / 2), size.x, size.y}, {0, 0},
        rotation, color.ToRaylib());
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
    ::DrawText(text.c_str(), position.x, position.y, fontSize, color.ToRaylib());
}

void Renderer::DrawFPS(const Vector2 &position, int fontSize, const Color &color)
{
    ::DrawFPS(position.x, position.y);
}

} // namespace Lumen