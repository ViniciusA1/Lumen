#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Entity/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/CameraComponent.hpp"

struct RenderTexture;

namespace Lumen
{

class Renderer
{
public:
    Renderer() = delete;

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

    static void DrawCapsule(const TransformComponent &transform, int slices, int rings,
                            Color color);
    static void DrawCapsuleWire(const TransformComponent &transform, int slices,
                                int rings, Color color);

    static void DrawCircle(const TransformComponent &transform, Color color);

    static void DrawCube(const TransformComponent &transform, Color color);
    static void DrawCubeWire(const TransformComponent &transform, Color color);

    static void DrawCylinder(const TransformComponent &transform, int slices,
                             Color color);
    static void DrawCylinder(const TransformComponent &transform, float radiusTop,
                             float radiusBottom, int slices, Color color);
    static void DrawCylinderWire(const TransformComponent &transform, int slices,
                                 Color color);
    static void DrawCylinderWire(const TransformComponent &transform, float radiusTop,
                                 float radiusBottom, int slices, Color color);

    static void DrawGrid(Vector3 cameraPosition, float minorSpacing, int majorDivisions,
                         int gridLines);

    static void DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color);

    static void DrawPlane(const TransformComponent &transform, Color color);

    static void DrawPixel(const Vector2 &position, Color color);

    static void DrawPoint(const Vector3 &position, Color color);

    static void DrawQuad(const TransformComponent &transform, Color color,
                         float roundness = 0.0f, int segments = 0.0f);
    static void DrawQuadLines(const TransformComponent &transform, Color color,
                              float roundness = 0.0f, int segments = 0.0f);

    static void DrawSphere(const TransformComponent &transform, Color color);
    static void DrawSphere(const TransformComponent &transform, int rings, int slices,
                           Color color);

    static void DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3,
                             Color color);

    static void DrawMesh(const TransformComponent &transform, const Mesh &mesh,
                         const Material &material);
};

} // namespace Lumen