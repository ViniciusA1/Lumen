#include "Lumen/Asset/Importer/DefaultImporter.hpp"
#include "Lumen/Graphics/Font.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/Model.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/World/Scene.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> DefaultAudioImporter::Import()
{
    return {};
}

Scope<Asset> DefaultFontImporter::Import()
{
    return CreateScope<Font>(::GetFontDefault());
}

Scope<Asset> DefaultMaterialImporter::Import()
{
    return CreateScope<Material>(::LoadMaterialDefault());
}

Scope<Asset> DefaultMeshImporter::Import()
{
    return CreateScope<Mesh>(GenMeshCube(1.0f, 1.0f, 1.0f));
}

Scope<Asset> DefaultModelImporter::Import()
{
    ::Model model{0};
    model.meshes = new ::Mesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    model.meshCount = 1;
    return CreateScope<Model>(model);
}

Scope<Asset> DefaultPrefabImporter::Import()
{
    return {};
}

Scope<Asset> DefaultSceneImporter::Import()
{
    return {};
}

Scope<Asset> DefaultScriptImporter::Import()
{
    return {};
}

Scope<Asset> DefaultShaderImporter::Import()
{
    return {};
}

Scope<Asset> DefaultTexture2DImporter::Import()
{
    constexpr int width = 64;
    constexpr int height = 64;
    ::Image image = ::GenImageColor(width, height, WHITE);
    ::Texture2D texture = ::LoadTextureFromImage(image);
    ::UnloadImage(image);
    return CreateScope<Texture2D>(texture);
}

} // namespace Lumen