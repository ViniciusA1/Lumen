#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Asset/Importer/DefaultImporter.hpp"

#define DEFINE_ASSET_STORAGE(Type)                                                       \
    template <> std::unordered_map<AssetHandle, Type> AssetStorage<Type>::s_Map = {};    \
    template <> Type DefaultAssetStorage<Type>::s_Asset = {};

namespace Lumen
{

template <typename T> std::unordered_map<AssetHandle, T> AssetStorage<T>::s_Map;
template <typename T> T DefaultAssetStorage<T>::s_Asset;

DEFINE_ASSET_STORAGE(Font)
DEFINE_ASSET_STORAGE(Image)
DEFINE_ASSET_STORAGE(Material)
DEFINE_ASSET_STORAGE(Mesh)
DEFINE_ASSET_STORAGE(Model)
DEFINE_ASSET_STORAGE(Shader)
DEFINE_ASSET_STORAGE(Texture2D)

std::unordered_map<UUID, AssetMetadata> AssetManager::s_AssetMetadataMap;
Path AssetManager::s_WorkingDirectory;
AssetManagerMode AssetManager::s_Mode = AssetManagerMode::Editor;

void AssetManager::LoadDefaultAssets()
{
    DefaultAssetStorage<Font>::s_Asset = DefaultAssetImporter::Import<Font>();
    DefaultAssetStorage<Image>::s_Asset = DefaultAssetImporter::Import<Image>();
    DefaultAssetStorage<Material>::s_Asset = DefaultAssetImporter::Import<Material>();
    DefaultAssetStorage<Mesh>::s_Asset = DefaultAssetImporter::Import<Mesh>();
    DefaultAssetStorage<Shader>::s_Asset = DefaultAssetImporter::Import<Shader>();
    DefaultAssetStorage<Texture2D>::s_Asset = DefaultAssetImporter::Import<Texture2D>();
}

std::unordered_map<UUID, AssetMetadata> &AssetManager::GetMetadataMap()
{
    return s_AssetMetadataMap;
}

AssetMetadata AssetManager::GetMetadata(const AssetHandle &handle)
{
    auto it = s_AssetMetadataMap.find(handle);
    if (it == s_AssetMetadataMap.end())
        return {};

    return it->second;
}

AssetManagerMode AssetManager::GetMode()
{
    return s_Mode;
}

Path AssetManager::GetWorkingDirectory()
{
    return s_WorkingDirectory;
}

void AssetManager::SetMetadata(const AssetHandle &handle, const AssetMetadata &metadata)
{
    auto it = s_AssetMetadataMap.find(handle);
    if (it == s_AssetMetadataMap.end())
        return;

    s_AssetMetadataMap[handle] = metadata;
}

void AssetManager::SetMode(AssetManagerMode mode)
{
    s_Mode = mode;
}

void AssetManager::SetWorkingDirectory(const Path &path)
{
    s_WorkingDirectory = path;
}

void AssetManager::Clear()
{
    AssetStorage<Font>::s_Map.clear();
    AssetStorage<Image>::s_Map.clear();
    AssetStorage<Material>::s_Map.clear();
    AssetStorage<Mesh>::s_Map.clear();
    AssetStorage<Model>::s_Map.clear();
    AssetStorage<Shader>::s_Map.clear();
    AssetStorage<Texture2D>::s_Map.clear();

    s_AssetMetadataMap.clear();
}

} // namespace Lumen