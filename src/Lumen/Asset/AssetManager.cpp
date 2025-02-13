#include "Lumen/Asset/AssetManager.hpp"

namespace Lumen
{

std::map<UUID, Ref<Asset>> AssetManager::s_AssetMap;
std::map<UUID, AssetMetadata> AssetManager::s_AssetMetadataMap;
std::map<std::type_index, Ref<Asset>> AssetManager::s_DefaultAssetMap;
Path AssetManager::s_WorkingDirectory;
AssetManagerMode AssetManager::s_Mode = AssetManagerMode::Editor;

bool AssetManager::IsLoaded(UUID uuid)
{
    return s_AssetMap.find(uuid) != s_AssetMap.end();
}

bool AssetManager::IsValid(UUID uuid)
{
    if (uuid == 0 || !IsLoaded(uuid))
        return false;

    return s_AssetMap.at(uuid)->IsValid();
}

std::map<UUID, AssetMetadata> &AssetManager::GetMetadataMap()
{
    return s_AssetMetadataMap;
}

AssetMetadata AssetManager::GetMetadata(UUID uuid)
{
    auto it = s_AssetMetadataMap.find(uuid);
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

void AssetManager::SetMetadata(UUID uuid, const AssetMetadata &metadata)
{
    auto it = s_AssetMetadataMap.find(uuid);
    if (it == s_AssetMetadataMap.end())
        return;

    s_AssetMetadataMap[uuid] = metadata;
}

void AssetManager::SetMode(AssetManagerMode mode)
{
    s_Mode = mode;
}

void AssetManager::SetWorkingDirectory(const Path &path)
{
    s_WorkingDirectory = path;
}

} // namespace Lumen