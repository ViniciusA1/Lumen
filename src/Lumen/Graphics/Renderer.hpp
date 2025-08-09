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

namespace Lumen::Renderer
{

void BeginBlendMode();
void BeginCameraMode(const CameraComponent &camera);
void BeginDrawing();
void BeginScissorMode(const Rectangle &region);
void BeginShaderMode(const Shader &shader);
void BeginTextureMode(const RenderTexture &texture);

void EndBlendMode();
void EndCameraMode();
void EndDrawing();
void EndScissorMode();
void EndShaderMode();
void EndTextureMode();

void ClearBackground(Color color);

RenderTexture CreateRenderTexture(const Vector2 &size);
void UnloadRenderTexture(const RenderTexture &texture);

void DisableBackfaceCulling();
void EnableBackfaceCulling();

void DisableDepthMask();
void EnableDepthMask();

void Viewport(const Rectangle &viewport);

void ClearBackground(const Image &dst, Color color);

void DrawCircle(const Image &dst, Vector2 center, int radius, Color color);
void DrawCircleLines(const Image &dst, Vector2 center, int radius, Color color);

void DrawImage(const Image &dst, const Image &src, const Rectangle &srcRec,
               const Rectangle &dstRec, Color tint);

void DrawLine(const Image &dst, Vector2 start, Vector2 end, Color color);
void DrawLine(const Image &dst, Vector2 start, Vector2 end, int thick, Color color);

void DrawPixel(const Image &dst, Vector2 position, Color color);

void DrawRectangle(const Image &dst, Rectangle rec, Color color);
void DrawRectangleLines(const Image &dst, Rectangle rec, int thick, Color color);

void DrawText(const Image &dst, const std::string &text, Vector2 position, int fontSize,
              Color color);
void DrawText(const Image &dst, const std::string &text, Vector2 position, float fontSize,
              const Font &font, float spacing, Color color);

void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1,
                  Color c2, Color c3);
void DrawTriangleFan(const Image &dst, std::vector<Vector2> &points, Color color);
void DrawTriangleLines(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
void DrawTriangleStrip(const Image &dst, std::vector<Vector2> &points, Color color);

void DrawCircle(const TransformComponent &transform, Color color);

void DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color);

void DrawPixel(const Vector2 &position, Color color);

void DrawQuad(const TransformComponent &transform, Color color = Color::White);
void DrawQuad(const TransformComponent &transform, const Texture2D &texture,
              const Vector4 &uv = {0, 0, 1, 1}, Color color = Color::White);
void DrawQuad2D(const TransformComponent &transform, Color color = Color::White);
void DrawQuad2D(const TransformComponent &transform, const Texture2D &texture,
                Color color = Color::White);
void DrawQuadLines(const TransformComponent &transform, float lineThick,
                   Color color = Color::White);

void DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3,
                  Color color = Color::White);

void DrawBillboard(const TransformComponent &transform, const CameraComponent &camera,
                   const Texture2D &texture, const Vector4 &uv, Color tint);

void DrawBoundingBox(const BoundingBox &box, float thickness, Color color);

void DrawCapsule(const TransformComponent &transform, int slices, int rings, Color color);
void DrawCapsuleWire(const TransformComponent &transform, int slices, int rings,
                     Color color);

void DrawCube(const TransformComponent &transform, Color color);
void DrawCube(const TransformComponent &transform, const Texture2D &texture,
              const Vector4 &uv, Color color);
void DrawCube(const TransformComponent &transform, const Texture2D &texture,
              const std::array<Vector4, 6> &uvs, Color color);
void DrawCubeWire(const TransformComponent &transform, Color color);

void DrawCylinder(const TransformComponent &transform, int slices, Color color);
void DrawCylinder(const TransformComponent &transform, float radiusTop,
                  float radiusBottom, int slices, Color color);
void DrawCylinderWire(const TransformComponent &transform, int slices, Color color);
void DrawCylinderWire(const TransformComponent &transform, float radiusTop,
                      float radiusBottom, int slices, Color color);

void DrawGrid(Vector3 cameraPosition, float minorSpacing, int majorDivisions,
              int gridLines, Color minorColor = Color::DarkGray,
              Color majorColor = Color::LightGray, bool xyPlane = false);

void DrawMesh(const TransformComponent &transform, const Mesh &mesh,
              const Material &material);

void DrawMeshTransformed(const TransformComponent &transform, const Mesh &mesh,
                         const Material &material);

void DrawModel(const TransformComponent &transform, const Model &model, Color tint);

void DrawPlane(const TransformComponent &transform, Color color);

void DrawPoint(const Vector3 &position, Color color);

void DrawSphere(const TransformComponent &transform, Color color);
void DrawSphere(const TransformComponent &transform, int rings, int slices, Color color);
void DrawSphereWires(const TransformComponent &transform, int rings, int slices,
                     Color color);

void DrawText(const TransformComponent &transform, const std::string &text,
              float fontSize, Color color);
void DrawText(const TransformComponent &transform, const std::string &text,
              float fontSize, Color color, const Font &font);
void DrawText(const Vector2 &position, const std::string &text, float fontSize,
              Color color);
void DrawText(const Vector2 &position, const std::string &text, float rotation,
              float fontSize, float spacing, Color color, const Font &font);
void DrawText3D(const TransformComponent &transform, const std::string &text,
                Color color);

void DrawFPS(const TransformComponent &transform, float fontSize, Color color);
void DrawFPS(const Vector2 &position, float fontSize, Color color);

} // namespace Lumen::Renderer