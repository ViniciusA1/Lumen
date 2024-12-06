#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/CameraComponent.hpp"
#include <string>

struct RenderTexture;

namespace Lumen
{

class Renderer
{
public:
    static void BeginRenderTexture();
    static void EndRenderTexture();
    static void CreateRenderTexture();
    static void DestroyRenderTexture();
    static ::RenderTexture &GetRenderTexture();
    static void ResizeRenderTexture(int width, int height);

    static void BeginDrawing();
    static void EndDrawing();

    static void Clear();
    static void SetClearColor(const Color &color) { s_Color = color; }

    static void Begin2DMode();
    static void DrawQuad(const Vector2 &position, const Vector2 &size,
                         const Color &color);
    static void DrawQuad(const Vector2 &position, float rotation, const Vector2 &size,
                         const Color &color);

    static void DrawText(const std::string &text, const Vector2 &position, int fontSize,
                         const Color &color);
    static void DrawFPS(const Vector2 &position, int fontSize, const Color &color);
    static void End2DMode();

    static void BeginMode3D(const CameraComponent &camera);
    static void EndMode3D();

private:
    static Color s_Color;
};

} // namespace Lumen