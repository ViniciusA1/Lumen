#include "Lumen/Asset/AssetImporterRegistry.hpp"
#include "Lumen/Asset/Importer/AudioImporter.hpp"
#include "Lumen/Asset/Importer/DefaultImporter.hpp"
#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Asset/Importer/MaterialImporter.hpp"
#include "Lumen/Asset/Importer/MeshImporter.hpp"
#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Asset/Importer/PrefabImporter.hpp"
#include "Lumen/Asset/Importer/SceneImporter.hpp"
#include "Lumen/Asset/Importer/ScriptImporter.hpp"
#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Asset/Importer/TextureImporter.hpp"

namespace Lumen
{

AssetImporterMap AssetImporterRegistry::s_ImporterMap = {
    {AssetType::Audio, CreateRef<AudioImporter>()},
    {AssetType::Font, CreateRef<FontImporter>()},
    {AssetType::Material, CreateRef<MaterialImporter>()},
    {AssetType::Mesh, CreateRef<MeshImporter>()},
    {AssetType::Model, CreateRef<ModelImporter>()},
    {AssetType::Prefab, CreateRef<PrefabImporter>()},
    {AssetType::Scene, CreateRef<SceneImporter>()},
    {AssetType::Script, CreateRef<ScriptImporter>()},
    {AssetType::Shader, CreateRef<ShaderImporter>()},
    {AssetType::Texture2D, CreateRef<Texture2DImporter>()},
};

DefaultImporterMap AssetImporterRegistry::s_DefaultImporterMap = {
    {AssetType::Audio, CreateRef<DefaultAudioImporter>()},
    {AssetType::Font, CreateRef<DefaultFontImporter>()},
    {AssetType::Material, CreateRef<DefaultMaterialImporter>()},
    {AssetType::Mesh, CreateRef<DefaultMeshImporter>()},
    {AssetType::Model, CreateRef<DefaultModelImporter>()},
    {AssetType::Prefab, CreateRef<DefaultPrefabImporter>()},
    {AssetType::Scene, CreateRef<DefaultSceneImporter>()},
    {AssetType::Script, CreateRef<DefaultScriptImporter>()},
    {AssetType::Shader, CreateRef<DefaultShaderImporter>()},
    {AssetType::Texture2D, CreateRef<DefaultTexture2DImporter>()},
};

bool AssetImporterRegistry::Has(AssetType type)
{
    return s_ImporterMap.contains(type);
}

bool AssetImporterRegistry::HasDefault(AssetType type)
{
    return s_DefaultImporterMap.contains(type);
}

Ref<AssetImporter> AssetImporterRegistry::Get(AssetType type)
{
    auto it = s_ImporterMap.find(type);
    if (it == s_ImporterMap.end())
        return nullptr;

    return it->second;
}

Ref<DefaultAssetImporter> AssetImporterRegistry::GetDefault(AssetType type)
{
    auto it = s_DefaultImporterMap.find(type);
    if (it == s_DefaultImporterMap.end())
        return nullptr;

    return it->second;
}

void AssetImporterRegistry::Register(AssetType type, Ref<AssetImporter> importer)
{
    s_ImporterMap[type] = std::move(importer);
}

} // namespace Lumen