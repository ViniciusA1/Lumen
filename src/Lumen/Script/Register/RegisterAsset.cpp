#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetMetadata.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterAsset();
static void RegisterAssetManager();
static void RegisterAssetMetadata();
static void RegisterAssetType();

void RegisterAssetAPI()
{
    RegisterAsset();
    RegisterAssetManager();
    RegisterAssetMetadata();
    RegisterAssetType();
}

static void RegisterAsset()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Asset>("Asset")
        .Property("handle", &Asset::GetHandle)
        .Property("type", &Asset::GetType)
        .Method("is_valid", &Asset::IsValid);
}

static void RegisterAssetManager()
{
}

static void RegisterAssetMetadata()
{
    ScriptEngine::GetInstance()
        ->RegisterType<AssetMetadata>("AssetMetadata")
        .Property("path", &AssetMetadata::Path)
        .Property("name", &AssetMetadata::Name)
        .OperatorEq([](const AssetMetadata &self, const AssetMetadata &other) {
            return self == other;
        });
}

static void RegisterAssetType()
{
    ScriptEngine::GetInstance()
        ->RegisterEnum<AssetType>("AssetType")
        .Value("None", AssetType::None)
        .Value("Animation", AssetType::Animation)
        .Value("Audio", AssetType::Audio)
        .Value("Font", AssetType::Font)
        .Value("Image", AssetType::Image)
        .Value("Material", AssetType::Material)
        .Value("Mesh", AssetType::Mesh)
        .Value("Model", AssetType::Model)
        .Value("Prefab", AssetType::Prefab)
        .Value("Scene", AssetType::Scene)
        .Value("Script", AssetType::Script)
        .Value("Shader", AssetType::Shader)
        .Value("Texture2D", AssetType::Texture2D)
        .Value("Tilemap", AssetType::Tilemap)
        .Value("Video", AssetType::Video)
        .Value("Folder", AssetType::Folder)
        .Value("TextFile", AssetType::TextFile)
        .Value("JSON", AssetType::JSON)
        .Value("XML", AssetType::XML)
        .Value("YAML", AssetType::YAML)
        .Value("Markdown", AssetType::Markdown)
        .Value("CSV", AssetType::CSV)
        .Value("Binary", AssetType::Binary)
        .Value("Config", AssetType::Config);
}

} // namespace Lumen