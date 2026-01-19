#include "Lumen/Graphics/Renderer.hpp"

#include "Lumen/Math/Math.hpp"
#include "raylib.h"
#include "rlgl.h"

namespace Lumen::Renderer
{

void BeginBlendMode()
{
    ::BeginBlendMode(0);
}

void BeginCameraMode(const CameraComponent &camera)
{
    ::rlSetClipPlanes(camera.Near, camera.Far);
    ::BeginMode3D({
        camera.Position,
        camera.Target,
        camera.Up,
        camera.Projection == ProjectionType::Perspective ? camera.Fov
                                                         : camera.OrthographicSize * 2.0f,
        static_cast<int>(camera.Projection),
    });
}

void BeginDrawing()
{
    ::BeginDrawing();
}

void BeginScissorMode(const Rectangle &region)
{
    ::BeginScissorMode(region.x, region.y, region.Width, region.Height);
}

void BeginShaderMode(const Shader &shader)
{
    ::BeginShaderMode(shader);
}

void BeginTextureMode(const RenderTexture &texture)
{
    ::BeginTextureMode(texture);
}

void EndBlendMode()
{
    ::EndBlendMode();
}

void EndCameraMode()
{
    ::EndMode3D();
}

void EndDrawing()
{
    ::EndDrawing();
}

void EndScissorMode()
{
    ::EndScissorMode();
}

void EndShaderMode()
{
    ::EndShaderMode();
}

void EndTextureMode()
{
    ::EndTextureMode();
}

void ClearBackground(Color color)
{
    ::ClearBackground(color);
}

void DisableBackfaceCulling()
{
    ::rlDisableBackfaceCulling();
}

void EnableBackfaceCulling()
{
    ::rlEnableBackfaceCulling();
}

void DisableDepthMask()
{
    ::rlDisableDepthMask();
}

void EnableDepthMask()
{
    ::rlEnableDepthMask();
}

void Viewport(const Rectangle &viewport)
{
    ::rlViewport(viewport.x, viewport.y, viewport.Width, viewport.Height);
}

void ClearBackground(const Image &dst, Color color)
{
    ::ImageClearBackground(dst, color);
}

RenderTexture CreateRenderTexture(const Vector2 &size)
{
    return ::LoadRenderTexture(size.x, size.y);
}

void UnloadRenderTexture(const RenderTexture &texture)
{
    ::UnloadRenderTexture(texture);
}

void DrawCircle(const Image &dst, Vector2 center, int radius, Color color)
{
    ::ImageDrawCircleV(dst, center, radius, color);
}

void DrawCircleLines(const Image &dst, Vector2 center, int radius, Color color)
{
    ::ImageDrawCircleLinesV(dst, center, radius, color);
}

void DrawImage(const Image &dst, const Image &src, const Rectangle &srcRec,
               const Rectangle &dstRec, Color tint)
{
    ::ImageDraw(dst, src, srcRec, dstRec, tint);
}

void DrawLine(const Image &dst, Vector2 start, Vector2 end, Color color)
{
    ::ImageDrawLineV(dst, start, end, color);
}

void DrawLine(const Image &dst, Vector2 start, Vector2 end, int thick, Color color)
{
    ::ImageDrawLineEx(dst, start, end, thick, color);
}

void DrawPixel(const Image &dst, Vector2 position, Color color)
{
    ::ImageDrawPixelV(dst, position, color);
}

void DrawRectangle(const Image &dst, Rectangle rec, Color color)
{
    ::ImageDrawRectangleRec(dst, rec, color);
}

void DrawRectangleLines(const Image &dst, Rectangle rec, int thick, Color color)
{
    ::ImageDrawRectangleLines(dst, rec, thick, color);
}

void DrawText(const Image &dst, const std::string &text, Vector2 position, int fontSize,
              Color color)
{
    ::ImageDrawText(dst, text.c_str(), static_cast<int>(position.x),
                    static_cast<int>(position.y), fontSize, color);
}

void DrawText(const Image &dst, const std::string &text, Vector2 position, float fontSize,
              const Font &font, float spacing, Color color)
{
    ::ImageDrawTextEx(dst, font, text.c_str(), position, fontSize, spacing, color);
}

void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    ::ImageDrawTriangle(dst, v1, v2, v3, color);
}

void DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1,
                  Color c2, Color c3)
{
    ::ImageDrawTriangleEx(dst, v1, v2, v3, c1, c2, c3);
}

void DrawTriangleFan(const Image &dst, std::vector<Vector2> &points, Color color)
{
    ::ImageDrawTriangleFan(dst, reinterpret_cast<::Vector2 *>(points.data()),
                           points.size(), color);
}

void DrawTriangleLines(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    ::ImageDrawTriangleLines(dst, v1, v2, v3, color);
}

void DrawTriangleStrip(const Image &dst, std::vector<Vector2> &points, Color color)
{
    ::ImageDrawTriangleStrip(dst, reinterpret_cast<::Vector2 *>(points.data()),
                             points.size(), color);
}

void DrawCircle(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCircle3D(transform.Position, 1.0f, {0.0f, 0.0f, 0.0f}, 0, color);

    ::rlPopMatrix();
}

void DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color)
{
    ::DrawLine3D(startPos, endPos, color);
}

void DrawPixel(const Vector2 &position, Color color)
{
    ::DrawPixelV(position, color);
}

void DrawQuad(const TransformComponent &transform, Color color)
{
    rlPushMatrix();

    rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    rlNormal3f(0.0f, 0.0f, 1.0f);
    rlVertex3f(-0.5f, -0.5f, 0.0f);
    rlVertex3f(0.5f, -0.5f, 0.0f);
    rlVertex3f(0.5f, 0.5f, 0.0f);
    rlVertex3f(-0.5f, 0.5f, 0.0f);
    rlNormal3f(0.0f, 0.0f, -1.0f);
    rlVertex3f(-0.5f, -0.5f, 0.0f);
    rlVertex3f(-0.5f, 0.5f, 0.0f);
    rlVertex3f(0.5f, 0.5f, 0.0f);
    rlVertex3f(0.5f, -0.5f, 0.0f);
    rlEnd();

    rlPopMatrix();
}

void DrawQuad(const TransformComponent &transform, const Texture2D &texture,
              const Vector4 &uv, Color color)
{
    const float x = transform.Position.x;
    const float y = transform.Position.y;
    const float z = transform.Position.z;

    constexpr float epsilon = 0.001f;
    const float w = transform.Scale.x * 0.5f;
    const float h = transform.Scale.y * 0.5f;

    const float u0 = uv.z;
    const float v0 = uv.y;
    const float u1 = uv.x;
    const float v1 = uv.w;

    ::rlPushMatrix();
    ::rlTranslatef(x, y, z);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlSetTexture(texture.GetRendererID());
    ::rlBegin(RL_QUADS);
    ::rlColor4ub(color.r, color.g, color.b, color.a);

    ::rlNormal3f(0.0f, 0.0f, 1.0f);
    ::rlTexCoord2f(u0, v0);
    ::rlVertex3f(-w, -h, 0.0f);
    ::rlTexCoord2f(u1, v0);
    ::rlVertex3f(w, -h, 0.0f);
    ::rlTexCoord2f(u1, v1);
    ::rlVertex3f(w, h, 0.0f);
    ::rlTexCoord2f(u0, v1);
    ::rlVertex3f(-w, h, 0.0f);

    ::rlNormal3f(0.0f, 0.0f, -1.0f);
    ::rlTexCoord2f(u0, v0);
    ::rlVertex3f(-w, -h, 0.0f);
    ::rlTexCoord2f(u0, v1);
    ::rlVertex3f(-w, h, 0.0f);
    ::rlTexCoord2f(u1, v1);
    ::rlVertex3f(w, h, 0.0f);
    ::rlTexCoord2f(u1, v0);
    ::rlVertex3f(w, -h, 0.0f);

    ::rlEnd();
    ::rlSetTexture(0);
    ::rlPopMatrix();
}

void DrawQuad2D(const TransformComponent &transform, Color color)
{
    Vector2 origin = {
        transform.Scale.x * 0.5f,
        transform.Scale.y * 0.5f,
    };

    ::DrawRectanglePro(
        {
            transform.Position.x,
            transform.Position.y,
            transform.Scale.x,
            transform.Scale.y,
        },
        origin, transform.Rotation.z, color);
}

void DrawQuad2D(const TransformComponent &transform, const Texture2D &texture,
                Color color)
{
    Vector2 origin = {
        transform.Scale.x * 0.5f,
        transform.Scale.y * 0.5f,
    };

    ::DrawTexturePro(texture,
                     {
                         0,
                         0,
                         static_cast<float>(texture.GetWidth()),
                         static_cast<float>(texture.GetHeight()),
                     },
                     {
                         transform.Position.x,
                         transform.Position.y,
                         transform.Scale.x,
                         transform.Scale.y,
                     },
                     origin, transform.Rotation.z, color);
}

void DrawQuadLines(const TransformComponent &transform, float lineThick, Color color)
{
    const Vector2 &topLeft = transform.Position - (transform.Scale * 0.5f);
    const Rectangle &rect = {
        topLeft.x,
        topLeft.y,
        transform.Scale.x,
        transform.Scale.y,
    };

    ::DrawRectangleLinesEx(rect, lineThick, color);
}

void DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, Color color)
{
    ::DrawTriangle3D(v1, v2, v3, color);
}

void DrawBillboard(const TransformComponent &transform, const CameraComponent &camera,
                   const Texture2D &texture, const Vector4 &uv, Color tint)
{
    Camera rayCamera = {
        .position = camera.Position,
        .target = camera.Target,
        .up = camera.Up,
        .fovy = camera.Fov,
        .projection = static_cast<int>(camera.Projection),
    };

    Rectangle sourceRect = {
        uv.x * texture.GetWidth(),
        uv.y * texture.GetHeight(),
        (uv.z - uv.x) * texture.GetWidth(),
        (uv.w - uv.y) * texture.GetHeight(),
    };

    ::DrawBillboardRec(rayCamera, texture, sourceRect, transform.Position,
                       {transform.Scale.x, transform.Scale.y}, tint);
}

void DrawBoundingBox(const BoundingBox &box, float thickness, Color color)
{
    const Vector3 &v0 = {box.Min.x, box.Min.y, box.Min.z};
    const Vector3 &v1 = {box.Max.x, box.Min.y, box.Min.z};
    const Vector3 &v2 = {box.Max.x, box.Max.y, box.Min.z};
    const Vector3 &v3 = {box.Min.x, box.Max.y, box.Min.z};
    const Vector3 &v4 = {box.Min.x, box.Min.y, box.Max.z};
    const Vector3 &v5 = {box.Max.x, box.Min.y, box.Max.z};
    const Vector3 &v6 = {box.Max.x, box.Max.y, box.Max.z};
    const Vector3 &v7 = {box.Min.x, box.Max.y, box.Max.z};

    constexpr int cylinderSides = 6;
    const float radius = thickness * 0.5f;

    ::DrawCylinderEx(v0, v1, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v1, v2, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v2, v3, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v3, v0, radius, radius, cylinderSides, color);

    ::DrawCylinderEx(v4, v5, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v5, v6, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v6, v7, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v7, v4, radius, radius, cylinderSides, color);

    ::DrawCylinderEx(v0, v4, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v1, v5, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v2, v6, radius, radius, cylinderSides, color);
    ::DrawCylinderEx(v3, v7, radius, radius, cylinderSides, color);
}

void DrawCapsule(const TransformComponent &transform, int slices, int rings, Color color)
{
    ::rlPushMatrix();

    ::rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCapsule(
        {
            0.0f,
            -0.5f,
            0.0f,
        },
        {
            0.0f,
            0.5f,
            0.0f,
        },
        0.5f, slices, rings, color);

    ::rlPopMatrix();
}

void DrawCapsuleWire(const TransformComponent &transform, int slices, int rings,
                     Color color)
{
    ::rlPushMatrix();

    ::rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCapsuleWires(
        {
            0.0f,
            -0.5f,
            0.0f,
        },
        {
            0.0f,
            0.5f,
            0.0f,
        },
        0.5f, slices, rings, color);

    ::rlPopMatrix();
}

void DrawCube(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeV(transform.Position, transform.Scale, color);

    ::rlPopMatrix();
}

void DrawCube(const TransformComponent &transform, const Texture2D &texture,
              const Vector4 &uv, Color color)
{
    const float x = transform.Position.x;
    const float y = transform.Position.y;
    const float z = transform.Position.z;

    const float w = transform.Scale.x * 0.5f;
    const float h = transform.Scale.y * 0.5f;
    const float l = transform.Scale.z * 0.5f;

    const float u0 = uv.z;
    const float v0 = uv.y;
    const float u1 = uv.x;
    const float v1 = uv.w;

    ::rlPushMatrix();
    ::rlTranslatef(x, y, z);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlSetTexture(texture.GetRendererID());
    ::rlBegin(RL_QUADS);
    ::rlColor4ub(color.r, color.g, color.b, color.a);

    ::rlNormal3f(0.0f, 0.0f, 1.0f);
    ::rlTexCoord2f(u0, v0);
    ::rlVertex3f(-w, -h, l);
    ::rlTexCoord2f(u1, v0);
    ::rlVertex3f(w, -h, l);
    ::rlTexCoord2f(u1, v1);
    ::rlVertex3f(w, h, l);
    ::rlTexCoord2f(u0, v1);
    ::rlVertex3f(-w, h, l);

    ::rlNormal3f(0.0f, 0.0f, -1.0f);
    ::rlTexCoord2f(u0, v0);
    ::rlVertex3f(w, -h, -l);
    ::rlTexCoord2f(u1, v0);
    ::rlVertex3f(-w, -h, -l);
    ::rlTexCoord2f(u1, v1);
    ::rlVertex3f(-w, h, -l);
    ::rlTexCoord2f(u0, v1);
    ::rlVertex3f(w, h, -l);

    ::rlEnd();
    ::rlSetTexture(0);
    ::rlPopMatrix();
}

void DrawCube(const TransformComponent &transform, const Texture2D &texture,
              const std::array<Vector4, 6> &uvs, Color color)
{
    const float x = transform.Position.x;
    const float y = transform.Position.y;
    const float z = transform.Position.z;

    constexpr float epsilon = 0.001f;
    const float w = transform.Scale.x * 0.5f + epsilon;
    const float h = transform.Scale.y * 0.5f + epsilon;
    const float l = transform.Scale.z * 0.5f + epsilon;

    const float texWidth = texture.GetWidth();
    const float texHeight = texture.GetHeight();

    constexpr std::array<unsigned char, 6> faceShade = {
        204, 204, 153, 153, 127, 255,
    };

    ::rlPushMatrix();
    ::rlTranslatef(x, y, z);

    ::rlRotatef(transform.Rotation.z, 0, 0, 1);
    ::rlRotatef(transform.Rotation.y, 0, 1, 0);
    ::rlRotatef(transform.Rotation.x, 1, 0, 0);

    ::rlSetTexture(texture.GetRendererID());
    ::rlBegin(RL_QUADS);

    const auto &drawFace = [&](int face, Vector3 normal, Vector3 v0, Vector3 v1,
                               Vector3 v2, Vector3 v3) {
        const Vector4 &uv = uvs[face];
        const float u0 = uv.x;
        const float v0_ = uv.w;
        const float u1 = uv.z;
        const float v1_ = uv.y;

        const unsigned char shade = faceShade[face];
        const Color &faceColor = {
            (unsigned char)((color.r * shade) / 255),
            (unsigned char)((color.g * shade) / 255),
            (unsigned char)((color.b * shade) / 255),
            color.a,
        };

        ::rlColor4ub(faceColor.r, faceColor.g, faceColor.b, faceColor.a);
        ::rlNormal3f(normal.x, normal.y, normal.z);
        ::rlTexCoord2f(u0, v0_);
        ::rlVertex3f(v0.x, v0.y, v0.z);
        ::rlTexCoord2f(u1, v0_);
        ::rlVertex3f(v1.x, v1.y, v1.z);
        ::rlTexCoord2f(u1, v1_);
        ::rlVertex3f(v2.x, v2.y, v2.z);
        ::rlTexCoord2f(u0, v1_);
        ::rlVertex3f(v3.x, v3.y, v3.z);
    };

    drawFace(0, {0, 0, 1}, {-w, -h, l}, {w, -h, l}, {w, h, l}, {-w, h, l});
    drawFace(1, {0, 0, -1}, {w, -h, -l}, {-w, -h, -l}, {-w, h, -l}, {w, h, -l});
    drawFace(2, {-1, 0, 0}, {-w, -h, -l}, {-w, -h, l}, {-w, h, l}, {-w, h, -l});
    drawFace(3, {1, 0, 0}, {w, -h, l}, {w, -h, -l}, {w, h, -l}, {w, h, l});
    drawFace(4, {0, -1, 0}, {-w, -h, -l}, {w, -h, -l}, {w, -h, l}, {-w, -h, l});
    drawFace(5, {0, 1, 0}, {-w, h, l}, {w, h, l}, {w, h, -l}, {-w, h, -l});

    ::rlEnd();
    ::rlSetTexture(0);
    ::rlPopMatrix();
}

void DrawCubeWire(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeWiresV(transform.Position, transform.Scale, color);

    ::rlPopMatrix();
}

void DrawCylinder(const TransformComponent &transform, int slices, Color color)
{
    ::rlPushMatrix();

    ::rlTranslatef(transform.Position.x, transform.Position.y, transform.Position.z);
    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinder({0.0f, -0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, slices, color);

    ::rlPopMatrix();
}

void DrawCylinder(const TransformComponent &transform, float radiusTop,
                  float radiusBottom, int slices, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinder(transform.Position, radiusTop, radiusBottom, 1.0f, slices, color);

    ::rlPopMatrix();
}

void DrawCylinderWire(const TransformComponent &transform, int slices, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinderWires(transform.Position, 1.0f, 1.0f, 1.0f, slices, color);

    ::rlPopMatrix();
}

void DrawCylinderWire(const TransformComponent &transform, float radiusTop,
                      float radiusBottom, int slices, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinderWires(transform.Position, radiusTop, radiusBottom, 1.0f, slices, color);

    ::rlPopMatrix();
}

void DrawGrid(Vector3 cameraPosition, float baseSpacing, int majorDivisions,
              int gridLines, Color minorColor, Color majorColor, bool xyPlane)
{
    // Determine grid scale based on camera distance
    // (similar to Unity: powers of 10 adjustment)
    float distance = xyPlane ? fabsf(cameraPosition.z) : fabsf(cameraPosition.y);
    float logScale = log10f(distance + 1.0f);
    int scalePower = (int)floorf(logScale);
    float spacing = baseSpacing * powf(10.0f, (float)scalePower);

    // The grid extends halfGridSize units around the camera
    float halfGridSize = spacing * gridLines;

    float start1, end1, start2, end2;
    if (xyPlane)
    {
        start1 = floorf((cameraPosition.x - halfGridSize) / spacing) * spacing;
        end1 = floorf((cameraPosition.x + halfGridSize) / spacing) * spacing;
        start2 = floorf((cameraPosition.y - halfGridSize) / spacing) * spacing;
        end2 = floorf((cameraPosition.y + halfGridSize) / spacing) * spacing;

        for (float x = start1; x <= end1; x += spacing)
        {
            bool isMajor = fmodf(fabsf(x), spacing * majorDivisions) < 0.0001f;
            Color c = isMajor ? majorColor : minorColor;
            DrawLine3D({x, start2, 0.001f}, {x, end2, 0.001f}, c);
        }

        for (float y = start2; y <= end2; y += spacing)
        {
            bool isMajor = fmodf(fabsf(y), spacing * majorDivisions) < 0.0001f;
            Color c = isMajor ? majorColor : minorColor;
            DrawLine3D({start1, y, 0.001f}, {end1, y, 0.001f}, c);
        }
    }
    else // XZ plane
    {
        start1 = floorf((cameraPosition.x - halfGridSize) / spacing) * spacing;
        end1 = floorf((cameraPosition.x + halfGridSize) / spacing) * spacing;
        start2 = floorf((cameraPosition.z - halfGridSize) / spacing) * spacing;
        end2 = floorf((cameraPosition.z + halfGridSize) / spacing) * spacing;

        for (float x = start1; x <= end1; x += spacing)
        {
            bool isMajor = fmodf(fabsf(x), spacing * majorDivisions) < 0.0001f;
            Color c = isMajor ? majorColor : minorColor;
            DrawLine3D({x, 0.0f, start2}, {x, 0.0f, end2}, c);
        }

        for (float z = start2; z <= end2; z += spacing)
        {
            bool isMajor = fmodf(fabsf(z), spacing * majorDivisions) < 0.0001f;
            Color c = isMajor ? majorColor : minorColor;
            DrawLine3D({start1, 0.0f, z}, {end1, 0.0f, z}, c);
        }
    }

    // Optionally, draw world axes for orientation
    DrawLine3D({0, 0, 0}, {1, 0, 0}, {255, 0, 0, 255}); // X axis - red
    DrawLine3D({0, 0, 0}, {0, 1, 0}, {0, 255, 0, 255}); // Y axis - green
    DrawLine3D({0, 0, 0}, {0, 0, 1}, {0, 0, 255, 255}); // Z axis - blue
}

void DrawMesh(const TransformComponent &transform, const Mesh &mesh,
              const Material &material)
{
    ::rlPushMatrix();

    const Vector3 &position = transform.Position;
    ::rlTranslatef(position.x, position.y, position.z);

    const Vector3 &rotation = transform.Rotation;
    ::rlRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

    const Vector3 &scale = transform.Scale;
    ::rlScalef(scale.x, scale.y, scale.z);

    const BoundingBox &meshBounds = GetMeshBoundingBox(mesh);
    const Vector3 &meshCenter = meshBounds.GetCenter();
    ::rlTranslatef(-meshCenter.x, -meshCenter.y, -meshCenter.z);

    ::DrawMesh(mesh, material, Matrix4::Identity);

    ::rlPopMatrix();
}

void DrawMeshTransformed(const TransformComponent &transform, const Mesh &mesh,
                         const Material &material)
{
    ::DrawMesh(
        mesh, material,
        Matrix4::Transform(transform.Position, transform.Rotation, transform.Scale));
}

void DrawModel(const TransformComponent &transform, const Model &model, Color tint)
{
    ::rlPushMatrix();

    const Vector3 &position = transform.Position;
    ::rlTranslatef(position.x, position.y, position.z);

    const Vector3 &rotation = transform.Rotation;
    ::rlRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

    const Vector3 &scale = transform.Scale;
    ::rlScalef(scale.x, scale.y, scale.z);

    ::DrawModel(model, {}, 1.0f, tint);

    ::rlPopMatrix();
}

void DrawPlane(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawPlane(transform.Position, {transform.Scale.x, transform.Scale.y}, color);

    ::rlPopMatrix();
}

void DrawPoint(const Vector3 &position, Color color)
{
    ::DrawPoint3D(position, color);
}

void DrawSphere(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphere(transform.Position, 1.0f, color);

    ::rlPopMatrix();
}

void DrawSphere(const TransformComponent &transform, int rings, int slices, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphereEx(transform.Position, 1.0f, rings, slices, color);

    ::rlPopMatrix();
}

void DrawSphereWires(const TransformComponent &transform, int rings, int slices,
                     Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphereEx(transform.Position, 1.0f, rings, slices, color);

    ::rlPopMatrix();
}

void DrawText(const TransformComponent &transform, const std::string &text,
              float fontSize, Color color)
{
    const Vector2 &position = {transform.Position.x, transform.Position.y};
    const float rotation = transform.Rotation.z;
    constexpr float spacing = 0.0f;
    const ::Font &font = ::GetFontDefault();
    const Vector2 &textSize = ::MeasureTextEx(font, text.c_str(), fontSize, spacing);
    const Vector2 &origin = {textSize.x / 2, textSize.y / 2};

    ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing,
                  color);
}

void DrawText(const TransformComponent &transform, const std::string &text,
              float fontSize, Color color, const Font &font)
{
    const Vector2 &position = {transform.Position.x, transform.Position.y};
    const float rotation = transform.Rotation.z;
    constexpr float spacing = 0.0f;
    const ::Font &curFont = font;
    const Vector2 &textSize = ::MeasureTextEx(curFont, text.c_str(), fontSize, spacing);
    const Vector2 &origin = {textSize.x / 2, textSize.y / 2};

    ::DrawTextPro(curFont, text.c_str(), position, origin, rotation, fontSize, spacing,
                  color);
}

void DrawText(const Vector2 &position, const std::string &text, float fontSize,
              Color color)
{
    ::DrawText(text.c_str(), position.x, position.y, fontSize, color);
}

void DrawText(const Vector2 &position, const std::string &text, float rotation,
              float fontSize, float spacing, Color color, const Font &font)
{
    ::DrawTextPro(font, text.c_str(), position, {0.0f, 0.0f}, rotation, fontSize, spacing,
                  color);
}

void DrawText3D(const TransformComponent &transform, const std::string &text, Color color)
{
}

void DrawFPS(const TransformComponent &transform, float fontSize, Color color)
{
    DrawText(transform, std::to_string(::GetFPS()), fontSize, color);
}

void DrawFPS(const Vector2 &position, float fontSize, Color color)
{
    DrawText(position, std::to_string(::GetFPS()), fontSize, color);
}

} // namespace Lumen::Renderer