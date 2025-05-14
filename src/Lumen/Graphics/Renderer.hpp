#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Font.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/Model.hpp"
#include "Lumen/Graphics/RenderTexture.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Math/BoundingBox.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Scene/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Component/Graphics/CameraComponent.hpp"

#include <string>
#include <vector>

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
    static void BeginShaderMode(const Shader &shader);
    static void BeginTextureMode(const RenderTexture &texture = {});

    static void EndBlendMode();
    static void EndCameraMode();
    static void EndDrawing();
    static void EndScissorMode();
    static void EndShaderMode();
    static void EndTextureMode();

public:
    static void ClearBackground(Color color);

    static void CreateDefaultRenderTexture();
    static RenderTexture &GetDefaultRenderTexture();
    static void ResizeRenderTexture(int width, int height);
    static void SetDefaultRenderTexture(const ::RenderTexture &texture);

public:
    static void DisableBackfaceCulling();
    static void EnableBackfaceCulling();

    static void DisableDepthMask();
    static void EnableDepthMask();

    static void Viewport(const Rectangle &viewport);

public:
    static void ClearBackground(const Image &dst, Color color);

    static void DrawCircle(const Image &dst, Vector2 center, int radius, Color color);
    static void DrawCircleLines(const Image &dst, Vector2 center, int radius,
                                Color color);

    static void DrawImage(const Image &dst, const Image &src, const Rectangle &srcRec,
                          const Rectangle &dstRec, Color tint);

    static void DrawLine(const Image &dst, Vector2 start, Vector2 end, Color color);
    static void DrawLine(const Image &dst, Vector2 start, Vector2 end, int thick,
                         Color color);

    static void DrawPixel(const Image &dst, Vector2 position, Color color);

    static void DrawRectangle(const Image &dst, Rectangle rec, Color color);
    static void DrawRectangleLines(const Image &dst, Rectangle rec, int thick,
                                   Color color);

    static void DrawText(const Image &dst, const std::string &text, Vector2 position,
                         int fontSize, Color color);
    static void DrawText(const Image &dst, const std::string &text, Vector2 position,
                         float fontSize, const Font &font, float spacing, Color color);

    static void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                             Color color);
    static void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                             Color c1, Color c2, Color c3);
    static void DrawTriangleFan(const Image &dst, std::vector<Vector2> &points,
                                Color color);
    static void DrawTriangleLines(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                                  Color color);
    static void DrawTriangleStrip(const Image &dst, std::vector<Vector2> &points,
                                  Color color);

public:
    static void DrawCircle(const TransformComponent &transform, Color color);

    static void DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color);

    static void DrawPixel(const Vector2 &position, Color color);

    static void DrawQuad(const TransformComponent &transform, Color color);
    static void DrawQuad(const TransformComponent &transform, const Texture2D &texture,
                         Color color);
    static void DrawQuadLines(const TransformComponent &transform, float lineThick,
                              Color color);

    static void DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3,
                             Color color);

public:
    static void DrawBillboard(const TransformComponent &transform,
                              const CameraComponent &camera, const Texture2D &texture,
                              const Vector4 &uv, Color tint);

    static void DrawBoundingBox(const BoundingBox &box, float thickness, Color color);

    static void DrawCapsule(const TransformComponent &transform, int slices, int rings,
                            Color color);
    static void DrawCapsuleWire(const TransformComponent &transform, int slices,
                                int rings, Color color);

    static void DrawCube(const TransformComponent &transform, Color color);
    static void DrawCube(const TransformComponent &transform, const Texture2D &texture,
                         const Vector4 &uv, Color color);
    static void DrawCube(const TransformComponent &transform, const Texture2D &texture,
                         const std::array<Vector4, 6> &uvs, Color color);
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

    static void DrawMesh(const TransformComponent &transform, const Mesh &mesh,
                         const Material &material);

    static void DrawMeshTransformed(const TransformComponent &transform, const Mesh &mesh,
                                    const Material &material);

    static void DrawModel(const TransformComponent &transform, const Model &model,
                          Color tint);

    static void DrawPlane(const TransformComponent &transform, Color color);

    static void DrawPoint(const Vector3 &position, Color color);

    static void DrawSphere(const TransformComponent &transform, Color color);
    static void DrawSphere(const TransformComponent &transform, int rings, int slices,
                           Color color);
    static void DrawSphereWires(const TransformComponent &transform, int rings,
                                int slices, Color color);

public:
    static void DrawText(const TransformComponent &transform, const std::string &text,
                         float fontSize, Color color);
    static void DrawText(const TransformComponent &transform, const std::string &text,
                         float fontSize, Color color, const Font &font);
    static void DrawText(const Vector2 &position, const std::string &text, float fontSize,
                         Color color);
    static void DrawText(const Vector2 &position, const std::string &text, float rotation,
                         float fontSize, float spacing, Color color, const Font &font);
    static void DrawText3D(const TransformComponent &transform, const std::string &text,
                           Color color);

public:
    static void DrawFPS(const TransformComponent &transform, float fontSize, Color color);
    static void DrawFPS(const Vector2 &position, float fontSize, Color color);
};

} // namespace Lumen