#include "Lumen/Graphics/Bone.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Font.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/ImageFactory.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/MeshFactory.hpp"
#include "Lumen/Graphics/Model.hpp"
#include "Lumen/Graphics/RenderTexture.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterBone();
static void RegisterColor();
static void RegisterFont();
static void RegisterImage();
static void RegisterMaterial();
static void RegisterMaterialMap();
static void RegisterMesh();
static void RegisterModel();
static void RegisterModelAnimation();
static void RegisterRenderer();
static void RegisterRenderTexture();
static void RegisterShader();
static void RegisterTexture();

void RegisterGraphicsAPI()
{
    RegisterBone();
    RegisterColor();
    RegisterFont();
    RegisterImage();
    RegisterMaterial();
    RegisterMaterialMap();
    RegisterMesh();
    RegisterModel();
    RegisterModelAnimation();
    RegisterRenderer();
    RegisterRenderTexture();
    RegisterShader();
    RegisterTexture();
}

static void RegisterBone()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Bone>("Bone")
        .Constructors<Bone()>()
        .Property("name", &Bone::GetName)
        .Property("parent", &Bone::GetParent);
}

static void RegisterColor()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Color>("Color")
        .Constructors<Color(),
                      Color(unsigned char, unsigned char, unsigned char, unsigned char)>()
        .Property("r", &Color::r)
        .Property("g", &Color::g)
        .Property("b", &Color::b)
        .Property("a", &Color::a)
        .Property("hex", &Color::ToHex)
        .Property("int", &Color::ToInt)
        .Property("normalize", &Color::Normalize)
        .Property("hsv", &Color::ToHSV)
        .StaticProperty("light_gray", Color::LightGray)
        .StaticProperty("gray", Color::Gray)
        .StaticProperty("dark_gray", Color::DarkGray)
        .StaticProperty("yellow", Color::Yellow)
        .StaticProperty("gold", Color::Gold)
        .StaticProperty("orange", Color::Orange)
        .StaticProperty("pink", Color::Pink)
        .StaticProperty("red", Color::Red)
        .StaticProperty("maroon", Color::Maroon)
        .StaticProperty("green", Color::Green)
        .StaticProperty("lime", Color::Lime)
        .StaticProperty("dark_green", Color::DarkGreen)
        .StaticProperty("sky_blue", Color::SkyBlue)
        .StaticProperty("blue", Color::Blue)
        .StaticProperty("dark_blue", Color::DarkBlue)
        .StaticProperty("purple", Color::Purple)
        .StaticProperty("violet", Color::Violet)
        .StaticProperty("dark_purple", Color::DarkPurple)
        .StaticProperty("beige", Color::Beige)
        .StaticProperty("brown", Color::Brown)
        .StaticProperty("dark_brown", Color::DarkBrown)
        .StaticProperty("white", Color::White)
        .StaticProperty("black", Color::Black)
        .StaticProperty("blank", Color::Blank)
        .StaticProperty("magenta", Color::Magenta)
        .StaticMethod("alpha", &Color::Alpha)
        .StaticMethod("fade", &Color::Fade)
        .StaticMethod("alpha_blend", &Color::AlphaBlend)
        .StaticMethod("brightness", &Color::Brightness)
        .StaticMethod("contrast", &Color::Contrast)
        .StaticMethod("from_hex", &Color::FromHex)
        .StaticMethod("from_hexa", &Color::FromHexa)
        .StaticMethod("from_hsv", &Color::FromHSV)
        .StaticMethod("from_normalized", &Color::FromNormalized)
        .StaticMethod("lerp", &Color::Lerp)
        .StaticMethod("tint", &Color::Tint);
}

static void RegisterFont()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Font>("Font")
        .Base<Asset>()
        .Constructors<Font()>()
        .Property("base_size", &Font::GetBaseSize)
        .Property("glyph_count", &Font::GetGlyphCount)
        .Property("glyph_padding", &Font::GetGlyphPadding)
        .Property("texture", &Font::GetTexture)
        .Property("type", &Font::GetType)
        .Method("is_valid", &Font::IsValid);
}

static void RegisterImage()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Image>("Image")
        .Base<Asset>()
        .Constructors<Image()>()
        .Property("data", &Image::GetData)
        .Property("format", &Image::GetFormat)
        .Property("height", &Image::GetHeight)
        .Property("mipmap", &Image::GetMipmap)
        .Property("size", &Image::GetSize)
        .Property("type", &Image::GetType)
        .Property("width", &Image::GetWidth)
        .Method("is_valid", &Image::IsValid)
        .Method("color", &Image::GetColor)
        .Method("alpha_border", &Image::GetAlphaBorder)
        .Method("alpha_clear", &Image::AlphaClear)
        .Method("alpha_crop", &Image::AlphaCrop)
        .Method("alpha_mask", &Image::AlphaMask)
        .Method("alpha_premultiply", &Image::AlphaPremultiply)
        .Method("crop", &Image::Crop)
        .Method("dither", &Image::Dither)
        .Method("kernel_convolution", &Image::KernelConvolution)
        .Method("resize", &Image::Resize)
        .Method("resize_canvas", &Image::ResizeCanvas)
        .Method("resize_nn", &Image::ResizeNN)
        .Method("rotate", &Image::Rotate)
        .Method("rotate_ccw", &Image::RotateCCW)
        .Method("rotate_cw", &Image::RotateCW)
        .Method("to_mipmaps", &Image::ToMipmaps)
        .Method("to_pot", &Image::ToPOT)
        .Method("convert_format", &Image::ConvertFormat)
        .Method("blur_gaussian", &Image::BlurGaussian)
        .Method("color_brightness", &Image::ColorBrightness)
        .Method("color_contrast", &Image::ColorContrast)
        .Method("color_grayscale", &Image::ColorGrayscale)
        .Method("color_invert", &Image::ColorInvert)
        .Method("color_replace", &Image::ColorReplace)
        .Method("color_tint", &Image::ColorTint)
        .Method("flip_horizontal", &Image::FlipHorizontal)
        .Method("flip_vertical", &Image::FlipVertical)
        .StaticMethod("create_cellular", &ImageFactory::CreateCellular)
        .StaticMethod("create_checked", &ImageFactory::CreateChecked)
        .StaticMethod("create_color", &ImageFactory::CreateColor)
        .StaticMethod("create_gradient_linear", &ImageFactory::CreateGradientLinear)
        .StaticMethod("create_gradient_radial", &ImageFactory::CreateGradientRadial)
        .StaticMethod("create_gradient_square", &ImageFactory::CreateGradientSquare)
        .StaticMethod("create_perlin_noise", &ImageFactory::CreatePerlinNoise)
        .StaticMethod("create_text", &ImageFactory::CreateText)
        .StaticMethod("create_white_noise", &ImageFactory::CreateWhiteNoise);
}

static void RegisterMaterial()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Material>("Material")
        .Base<Asset>()
        .Constructors<Material()>()
        .Property("color", &Material::GetColor)
        .Property("map_count", &Material::GetMapCount)
        .Property("shader", &Material::GetShader)
        .Property("type", &Material::GetType)
        .Method("is_valid", &Material::IsValid)
        .Method("map", &Material::GetMap);
}

static void RegisterMaterialMap()
{
    auto &engine = ScriptEngine::GetInstance();

    engine->RegisterEnum<MaterialMapIndex>("MaterialMapIndex")
        .Value("Albedo", MaterialMapIndex::Albedo)
        .Value("Metalness", MaterialMapIndex::Metalness)
        .Value("Normal", MaterialMapIndex::Normal)
        .Value("Roughness", MaterialMapIndex::Roughness)
        .Value("Occlusion", MaterialMapIndex::Occlusion)
        .Value("Emission", MaterialMapIndex::Emission)
        .Value("Height", MaterialMapIndex::Height)
        .Value("Cubemap", MaterialMapIndex::Cubemap)
        .Value("Irradiance", MaterialMapIndex::Irradiance)
        .Value("Prefilter", MaterialMapIndex::Prefilter)
        .Value("Brdf", MaterialMapIndex::Brdf)
        .Value("Diffuse", MaterialMapIndex::Diffuse)
        .Value("Specular", MaterialMapIndex::Specular)
        .Value("MaxAmount", MaterialMapIndex::MaxAmount);

    engine->RegisterType<MaterialMap>("MaterialMap")
        .Constructors<MaterialMap()>()
        .Property("texture", &MaterialMap::GetTexture, &MaterialMap::SetTexture)
        .Property("color", &MaterialMap::GetColor, &MaterialMap::SetColor)
        .Property("value", &MaterialMap::GetValue, &MaterialMap::SetValue);
}

static void RegisterMesh()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Mesh>("Mesh")
        .Base<Asset>()
        .Constructors<Mesh()>()
        .Property("anim_vertices", &Mesh::GetAnimVertices)
        .Property("anim_normals", &Mesh::GetAnimNormals)
        .Property("bone_count", &Mesh::GetBoneCount)
        .Property("bone_ids", &Mesh::GetBoneIds)
        .Property("bone_weights", &Mesh::GetBoneWeights)
        .Property("bounding_box", &Mesh::GetBoundingBox)
        .Property("colors", &Mesh::GetColors)
        .Property("indices", &Mesh::GetIndices)
        .Property("normals", &Mesh::GetNormals)
        .Property("tangents", &Mesh::GetTangents)
        .Property("tex_coords", &Mesh::GetTexCoords)
        .Property("tex_coords2", &Mesh::GetTexCoords2)
        .Property("triangle_count", &Mesh::GetTriangleCount)
        .Property("vao", &Mesh::GetVAO)
        .Property("vbos", &Mesh::GetVBOs)
        .Property("vertex_count", &Mesh::GetVertexCount)
        .Property("vertices", &Mesh::GetVertices)
        .Property("type", &Mesh::GetType)
        .Method("is_valid", &Mesh::IsValid)
        .StaticMethod("create_cone", &MeshFactory::CreateCone)
        .StaticMethod("create_cube", &MeshFactory::CreateCube)
        .StaticMethod("create_cubicmap", &MeshFactory::CreateCubicmap)
        .StaticMethod("create_cylinder", &MeshFactory::CreateCylinder)
        .StaticMethod("create_heightmap", &MeshFactory::CreateHeightmap)
        .StaticMethod("create_hemisphere", &MeshFactory::CreateHemiSphere)
        .StaticMethod("create_knot", &MeshFactory::CreateKnot)
        .StaticMethod("create_poly", &MeshFactory::CreatePoly)
        .StaticMethod("create_plane", &MeshFactory::CreatePlane)
        .StaticMethod("create_sphere", &MeshFactory::CreateSphere)
        .StaticMethod("create_torus", &MeshFactory::CreateTorus);
}

static void RegisterModel()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Model>("Model")
        .Base<Asset>()
        .Constructors<Model()>()
        .Property("animation_count", &Model::GetAnimationCount)
        .Property("animations", &Model::GetAnimations)
        .Property("bone_count", &Model::GetBoneCount)
        .Property("bones", &Model::GetBones)
        .Property("material_count", &Model::GetMaterialCount)
        .Property("materials", &Model::GetMaterials)
        .Property("mesh_count", &Model::GetMeshCount)
        .Property("meshes", &Model::GetMeshes)
        .Property("type", &Model::GetType)
        .Property("animation", &Model::GetAnimation)
        .Property("bone", &Model::GetBone)
        .Property("material", &Model::GetMaterial)
        .Property("mesh", &Model::GetMesh)
        .Method("is_valid", &Model::IsValid);
}

static void RegisterModelAnimation()
{
    ScriptEngine::GetInstance()
        ->RegisterType<ModelAnimation>("ModelAnimation")
        .Constructors<ModelAnimation()>()
        .Property("bone_count", &ModelAnimation::GetBoneCount)
        .Property("frame_count", &ModelAnimation::GetFrameCount)
        .Property("name", &ModelAnimation::GetName);
}

static void RegisterRenderer()
{
    auto &engine = ScriptEngine::GetInstance();

    engine->RegisterNamespace("Renderer")
        .Function("begin_blend_mode", &Renderer::BeginBlendMode)
        .Function("begin_camera_mode", &Renderer::BeginCameraMode)
        .Function("begin_drawing", &Renderer::BeginDrawing)
        .Function("begin_scissor_mode", &Renderer::BeginScissorMode)
        .Function("begin_shader_mode", &Renderer::BeginShaderMode)
        .Function("begin_texture_mode", &Renderer::BeginTextureMode)
        .Function("end_blend_mode", &Renderer::EndBlendMode)
        .Function("end_camera_mode", &Renderer::EndCameraMode)
        .Function("end_drawing", &Renderer::EndDrawing)
        .Function("end_scissor_mode", &Renderer::EndScissorMode)
        .Function("end_shader_mode", &Renderer::EndShaderMode)
        .Function("end_texture_mode", &Renderer::EndTextureMode)
        .Function("clear_background",
                  static_cast<void (*)(Color)>(&Renderer::ClearBackground),
                  static_cast<void (*)(const Image &, Color)>(&Renderer::ClearBackground))
        .Function("viewport", &Renderer::Viewport)
        .Function("create_render_texture", &Renderer::CreateRenderTexture)
        .Function("unload_render_texture", &Renderer::UnloadRenderTexture)
        .Function("draw_circle",
                  static_cast<void (*)(const Image &, Vector2, int, Color)>(
                      &Renderer::DrawCircle))
        .Function("draw_circle_lines", &Renderer::DrawCircleLines)
        .Function("draw_line",
                  static_cast<void (*)(const Image &, Vector2, Vector2, Color)>(
                      &Renderer::DrawLine),
                  static_cast<void (*)(const Image &, Vector2, Vector2, int, Color)>(
                      &Renderer::DrawLine))
        .Function("draw_rectangle", &Renderer::DrawRectangle)
        .Function("draw_rectangle_lines", &Renderer::DrawRectangleLines)
        .Function("draw_triangle",
                  static_cast<void (*)(const Image &, Vector2, Vector2, Vector2, Color)>(
                      &Renderer::DrawTriangle),
                  static_cast<void (*)(const Image &, Vector2, Vector2, Vector2, Color,
                                       Color, Color)>(&Renderer::DrawTriangle))
        .Function("draw_triangle_lines", &Renderer::DrawTriangleLines)
        .Function("draw_triangle_strip", &Renderer::DrawTriangleStrip)
        .Function("draw_triangle_fan", &Renderer::DrawTriangleFan)
        .Function("draw_image", &Renderer::DrawImage)
        .Function("draw_text",
                  static_cast<void (*)(const Image &, const std::string &, Vector2, int,
                                       Color)>(&Renderer::DrawText),
                  static_cast<void (*)(const Image &, const std::string &, Vector2, float,
                                       const Font &, float, Color)>(&Renderer::DrawText))
        .Function(
            "draw_quad",
            static_cast<void (*)(const TransformComponent &, Color)>(&Renderer::DrawQuad),
            static_cast<void (*)(const TransformComponent &, const Texture2D &,
                                 const Vector4 &, Color)>(&Renderer::DrawQuad))
        .Function(
            "draw_cube",
            static_cast<void (*)(const TransformComponent &, Color)>(&Renderer::DrawCube),
            static_cast<void (*)(const TransformComponent &, const Texture2D &,
                                 const Vector4 &, Color)>(&Renderer::DrawCube))
        .Function("draw_sphere",
                  static_cast<void (*)(const TransformComponent &, Color)>(
                      &Renderer::DrawSphere),
                  static_cast<void (*)(const TransformComponent &, int, int, Color)>(
                      &Renderer::DrawSphere))
        .Function("draw_cylinder",
                  static_cast<void (*)(const TransformComponent &, int, Color)>(
                      &Renderer::DrawCylinder))
        .Function("draw_mesh", &Renderer::DrawMesh)
        .Function("draw_model", &Renderer::DrawModel)
        .Function("draw_grid", &Renderer::DrawGrid);
}

static void RegisterRenderTexture()
{
    ScriptEngine::GetInstance()
        ->RegisterType<RenderTexture>("RenderTexture")
        .Constructors<RenderTexture()>()
        .Property("width", &RenderTexture::GetWidth)
        .Property("height", &RenderTexture::GetHeight)
        .Property("size", &RenderTexture::GetSize)
        .Property("renderer_id", &RenderTexture::GetRendererID)
        .Property("texture", &RenderTexture::GetTexture)
        .Property("depth_texture", &RenderTexture::GetDepthTexture)
        .Method("is_valid", &RenderTexture::IsValid)
        .Method("resize",
                static_cast<void (RenderTexture::*)(int, int)>(&RenderTexture::Resize),
                static_cast<void (RenderTexture::*)(const Vector2 &)>(
                    &RenderTexture::Resize));
}

static void RegisterShader()
{
    auto &engine = ScriptEngine::GetInstance();

    engine->RegisterEnum<ShaderUniformType>("ShaderUniformType")
        .Value("Float", ShaderUniformType::Float)
        .Value("Vec2", ShaderUniformType::Vec2)
        .Value("Vec3", ShaderUniformType::Vec3)
        .Value("Vec4", ShaderUniformType::Vec4)
        .Value("Int", ShaderUniformType::Int)
        .Value("IVec2", ShaderUniformType::IVec2)
        .Value("IVec3", ShaderUniformType::IVec3)
        .Value("IVec4", ShaderUniformType::IVec4)
        .Value("Sampler2D", ShaderUniformType::Sampler2D);

    engine->RegisterEnum<ShaderAttributeType>("ShaderAttributeType")
        .Value("Float", ShaderAttributeType::Float)
        .Value("Vec2", ShaderAttributeType::Vec2)
        .Value("Vec3", ShaderAttributeType::Vec3)
        .Value("Vec4", ShaderAttributeType::Vec4);

    engine->RegisterType<Shader>("Shader")
        .Base<Asset>()
        .Constructors<Shader()>()
        .Property("location", &Shader::GetLocation)
        .Property("location_attribute", &Shader::GetLocationAttribute)
        .Property("renderer_id", &Shader::GetRendererID)
        .Property("locations", &Shader::GetLocations)
        .Method("is_valid", &Shader::IsValid)
        .Method("has_attribute", &Shader::HasAttribute)
        .Method("has_uniform", &Shader::HasUniform)
        .Method("set_value_index",
                static_cast<void (Shader::*)(int, const void *, ShaderUniformType)>(
                    &Shader::SetValue),
                static_cast<void (Shader::*)(int, const Matrix4 &)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, const Texture2D &)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, const Vector2 &)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, const Vector3 &)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, const Vector4 &)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, float)>(&Shader::SetValue),
                static_cast<void (Shader::*)(int, int)>(&Shader::SetValue))
        .Method(
            "set_value",
            static_cast<void (Shader::*)(const std::string &, const void *,
                                         ShaderUniformType)>(&Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, const Matrix4 &)>(
                &Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, const Texture2D &)>(
                &Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, const Vector2 &)>(
                &Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, const Vector3 &)>(
                &Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, const Vector4 &)>(
                &Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, float)>(&Shader::SetValue),
            static_cast<void (Shader::*)(const std::string &, int)>(&Shader::SetValue));
}

static void RegisterTexture()
{
    auto &engine = ScriptEngine::GetInstance();

    engine->RegisterEnum<TextureFilter>("TextureFilter")
        .Value("Point", TextureFilter::Point)
        .Value("Bilinear", TextureFilter::Bilinear)
        .Value("Trilinear", TextureFilter::Trilinear)
        .Value("Anisotropic4X", TextureFilter::Anisotropic4X)
        .Value("Anisotropic8X", TextureFilter::Anisotropic8X)
        .Value("Anisotropic16X", TextureFilter::Anisotropic16X);

    engine->RegisterEnum<TextureWrap>("TextureWrap")
        .Value("Repeat", TextureWrap::Repeat)
        .Value("Clamp", TextureWrap::Clamp)
        .Value("MirrorRepeat", TextureWrap::MirrorRepeat)
        .Value("MirrorClamp", TextureWrap::MirrorClamp);

    engine->RegisterType<Texture2D>("Texture2D")
        .Base<Asset>()
        .Constructors<Texture2D()>()
        .Property("format", &Texture2D::GetFormat)
        .Property("height", &Texture2D::GetHeight)
        .Property("mipmap", &Texture2D::GetMipmap)
        .Property("renderer_id", &Texture2D::GetRendererID)
        .Property("size", &Texture2D::GetSize)
        .Property("type", &Texture2D::GetType)
        .Property("width", &Texture2D::GetWidth)
        .Method("is_valid", &Texture2D::IsValid)
        .Method("filter", &Texture2D::SetFilter)
        .Method("wrap", &Texture2D::SetWrap)
        .Method("update_data", &Texture2D::UpdateData)
        .Method("update_data_rect", &Texture2D::UpdateDataRect);
}

} // namespace Lumen