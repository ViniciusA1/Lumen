#include "Lumen/Graphics/Renderer.hpp"

#include "Lumen/Math/Math.hpp"
#include "raylib.h"
#include "rlgl.h"

namespace Lumen
{

static RenderTexture s_RenderTexture;

void Renderer::BeginBlendMode()
{
    ::BeginBlendMode(0);
}

void Renderer::BeginCameraMode(const CameraComponent &camera)
{
    ::BeginMode3D({
        camera.Position,
        camera.Target,
        camera.Up,
        camera.Fov,
        static_cast<int>(camera.Projection),
    });
}

void Renderer::BeginDrawing()
{
    ::BeginDrawing();
}

void Renderer::BeginScissorMode(const Rectangle &region)
{
    ::BeginScissorMode(region.x, region.y, region.Width, region.Height);
}

void Renderer::BeginShaderMode(const Shader &shader)
{
    ::BeginShaderMode(shader);
}

void Renderer::BeginTextureMode(const RenderTexture &texture)
{
    ::BeginTextureMode(texture.IsValid() ? texture : s_RenderTexture);
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

RenderTexture &Renderer::GetDefaultRenderTexture()
{
    return s_RenderTexture;
}

void Renderer::ResizeRenderTexture(int width, int height)
{
    Texture2D texture = s_RenderTexture.GetColorTexture();

    if (texture.GetWidth() != width || texture.GetHeight() != height)
    {
        ::UnloadRenderTexture(s_RenderTexture);
        s_RenderTexture = LoadRenderTexture(width, height);
    }
}

void Renderer::SetDefaultRenderTexture(const ::RenderTexture &texture)
{
    s_RenderTexture = texture;
}

void Renderer::DisableBackfaceCulling()
{
    ::rlDisableBackfaceCulling();
}

void Renderer::EnableBackfaceCulling()
{
    ::rlEnableBackfaceCulling();
}

void Renderer::DisableDepthMask()
{
    ::rlDisableDepthMask();
}

void Renderer::EnableDepthMask()
{
    ::rlEnableDepthMask();
}

void Renderer::Viewport(const Rectangle &viewport)
{
    ::rlViewport(viewport.x, viewport.y, viewport.Width, viewport.Height);
}

void Renderer::ClearBackground(const Image &dst, Color color)
{
    ::ImageClearBackground(dst, color);
}

void Renderer::DrawCircle(const Image &dst, Vector2 center, int radius, Color color)
{
    ::ImageDrawCircleV(dst, center, radius, color);
}

void Renderer::DrawCircleLines(const Image &dst, Vector2 center, int radius, Color color)
{
    ::ImageDrawCircleLinesV(dst, center, radius, color);
}

void Renderer::DrawImage(const Image &dst, const Image &src, const Rectangle &srcRec,
                         const Rectangle &dstRec, Color tint)
{
    ::ImageDraw(dst, src, srcRec, dstRec, tint);
}

void Renderer::DrawLine(const Image &dst, Vector2 start, Vector2 end, Color color)
{
    ::ImageDrawLineV(dst, start, end, color);
}

void Renderer::DrawLine(const Image &dst, Vector2 start, Vector2 end, int thick,
                        Color color)
{
    ::ImageDrawLineEx(dst, start, end, thick, color);
}

void Renderer::DrawPixel(const Image &dst, Vector2 position, Color color)
{
    ::ImageDrawPixelV(dst, position, color);
}

void Renderer::DrawRectangle(const Image &dst, Rectangle rec, Color color)
{
    ::ImageDrawRectangleRec(dst, rec, color);
}

void Renderer::DrawRectangleLines(const Image &dst, Rectangle rec, int thick, Color color)
{
    ::ImageDrawRectangleLines(dst, rec, thick, color);
}

void Renderer::DrawText(const Image &dst, const std::string &text, Vector2 position,
                        int fontSize, Color color)
{
    ::ImageDrawText(dst, text.c_str(), static_cast<int>(position.x),
                    static_cast<int>(position.y), fontSize, color);
}

void Renderer::DrawText(const Image &dst, const std::string &text, Vector2 position,
                        float fontSize, const Font &font, float spacing, Color color)
{
    ::ImageDrawTextEx(dst, font, text.c_str(), position, fontSize, spacing, color);
}

void Renderer::DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                            Color color)
{
    ::ImageDrawTriangle(dst, v1, v2, v3, color);
}

void Renderer::DrawTriangle(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                            Color c1, Color c2, Color c3)
{
    ::ImageDrawTriangleEx(dst, v1, v2, v3, c1, c2, c3);
}

void Renderer::DrawTriangleFan(const Image &dst, std::vector<Vector2> &points,
                               Color color)
{
    ::ImageDrawTriangleFan(dst, reinterpret_cast<::Vector2 *>(points.data()),
                           points.size(), color);
}

void Renderer::DrawTriangleLines(const Image &dst, Vector2 v1, Vector2 v2, Vector2 v3,
                                 Color color)
{
    ::ImageDrawTriangleLines(dst, v1, v2, v3, color);
}

void Renderer::DrawTriangleStrip(const Image &dst, std::vector<Vector2> &points,
                                 Color color)
{
    ::ImageDrawTriangleStrip(dst, reinterpret_cast<::Vector2 *>(points.data()),
                             points.size(), color);
}

void Renderer::DrawCircle(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCircle3D(transform.Position, 1.0f, {0.0f, 0.0f, 0.0f}, 0, color);

    ::rlPopMatrix();
}

void Renderer::DrawLine(const Vector3 &startPos, const Vector3 &endPos, Color color)
{
    ::DrawLine3D(startPos, endPos, color);
}

void Renderer::DrawPixel(const Vector2 &position, Color color)
{
    ::DrawPixelV(position, color);
}

void Renderer::DrawQuad(const TransformComponent &transform, Color color)
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

void Renderer::DrawQuad(const TransformComponent &transform, const Texture2D &texture,
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

void Renderer::DrawQuad2D(const TransformComponent &transform, Color color)
{
    const Vector2 &origin = {
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

void Renderer::DrawQuad2D(const TransformComponent &transform, const Texture2D &texture,
                          Color color)
{
    const Vector2 &origin = {
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

void Renderer::DrawQuadLines(const TransformComponent &transform, float lineThick,
                             Color color)
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

void Renderer::DrawTriangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3,
                            Color color)
{
    ::DrawTriangle3D(v1, v2, v3, color);
}

void Renderer::DrawBillboard(const TransformComponent &transform,
                             const CameraComponent &camera, const Texture2D &texture,
                             const Vector4 &uv, Color tint)
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

void Renderer::DrawBoundingBox(const BoundingBox &box, float thickness, Color color)
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

void Renderer::DrawCapsule(const TransformComponent &transform, int slices, int rings,
                           Color color)
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

void Renderer::DrawCapsuleWire(const TransformComponent &transform, int slices, int rings,
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

void Renderer::DrawCube(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeV(transform.Position, transform.Scale, color);

    ::rlPopMatrix();
}

void Renderer::DrawCube(const TransformComponent &transform, const Texture2D &texture,
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

void Renderer::DrawCube(const TransformComponent &transform, const Texture2D &texture,
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

void Renderer::DrawCubeWire(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawCubeWiresV(transform.Position, transform.Scale, color);

    ::rlPopMatrix();
}

void Renderer::DrawCylinder(const TransformComponent &transform, int slices, Color color)
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

void Renderer::DrawCylinder(const TransformComponent &transform, float radiusTop,
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

void Renderer::DrawCylinderWire(const TransformComponent &transform, int slices,
                                Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawCylinderWires(transform.Position, 1.0f, 1.0f, 1.0f, slices, color);

    ::rlPopMatrix();
}

void Renderer::DrawCylinderWire(const TransformComponent &transform, float radiusTop,
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

void Renderer::DrawMesh(const TransformComponent &transform, const Mesh &mesh,
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

void Renderer::DrawMeshTransformed(const TransformComponent &transform, const Mesh &mesh,
                                   const Material &material)
{
    ::DrawMesh(
        mesh, material,
        Matrix4::Transform(transform.Position, transform.Rotation, transform.Scale));
}

void Renderer::DrawModel(const TransformComponent &transform, const Model &model,
                         Color tint)
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

void Renderer::DrawPlane(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);

    ::DrawPlane(transform.Position, {transform.Scale.x, transform.Scale.y}, color);

    ::rlPopMatrix();
}

void Renderer::DrawPoint(const Vector3 &position, Color color)
{
    ::DrawPoint3D(position, color);
}

void Renderer::DrawSphere(const TransformComponent &transform, Color color)
{
    ::rlPushMatrix();

    ::rlRotatef(transform.Rotation.x, 1.0f, 0.0f, 0.0f);
    ::rlRotatef(transform.Rotation.y, 0.0f, 1.0f, 0.0f);
    ::rlRotatef(transform.Rotation.z, 0.0f, 0.0f, 1.0f);
    ::rlScalef(transform.Scale.x, transform.Scale.y, transform.Scale.z);

    ::DrawSphere(transform.Position, 1.0f, color);

    ::rlPopMatrix();
}

void Renderer::DrawSphere(const TransformComponent &transform, int rings, int slices,
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

void Renderer::DrawSphereWires(const TransformComponent &transform, int rings, int slices,
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

void Renderer::DrawText(const TransformComponent &transform, const std::string &text,
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

void Renderer::DrawText(const TransformComponent &transform, const std::string &text,
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

void Renderer::DrawText(const Vector2 &position, const std::string &text, float fontSize,
                        Color color)
{
    ::DrawText(text.c_str(), position.x, position.y, fontSize, color);
}

void Renderer::DrawText(const Vector2 &position, const std::string &text, float rotation,
                        float fontSize, float spacing, Color color, const Font &font)
{
    ::DrawTextPro(font, text.c_str(), position, {0.0f, 0.0f}, rotation, fontSize, spacing,
                  color);
}

void Renderer::DrawText3D(const TransformComponent &transform, const std::string &text,
                          Color color)
{
}

void Renderer::DrawFPS(const TransformComponent &transform, float fontSize, Color color)
{
    DrawText(transform, std::to_string(::GetFPS()), fontSize, color);
}

void Renderer::DrawFPS(const Vector2 &position, float fontSize, Color color)
{
    DrawText(position, std::to_string(::GetFPS()), fontSize, color);
}

} // namespace Lumen