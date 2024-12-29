#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Entity/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/CameraComponent.hpp"

#include <string>

struct RenderTexture;

namespace Lumen
{

class Renderer
{
public:
    static void BeginBlendMode();
    static void BeginCameraMode(const CameraComponent &camera);
    static void BeginDrawing();
    static void BeginScissorMode(const Rectangle &region);
    static void BeginShaderMode(const Ref<Shader> &shader);
    static void BeginTextureMode();

    static void EndBlendMode();
    static void EndCameraMode();
    static void EndDrawing();
    static void EndScissorMode();
    static void EndShaderMode();
    static void EndTextureMode();

    static void ClearBackground(Color color);
    static void CreateDefaultRenderTexture();
    static RenderTexture &GetRenderTexture();
    static void ResizeRenderTexture(int width, int height);
    static void SetRenderTexture(const ::RenderTexture texture);

    static void DrawFPS(const Vector2 position, int size, Color color);
    static void DrawText();

    static void DrawQuad(const TransformComponent &transform, Color color);

    static void DrawCube(const TransformComponent &transform, Color color);
    static void DrawGrid(Vector3 cameraPosition, float minorSpacing, int majorDivisions,
                         int gridLines);
};

} // namespace Lumen