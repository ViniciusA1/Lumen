#include "Lumen/Asset/AssetManager.hpp"

namespace Lumen
{

std::map<std::type_index, std::map<UUID, Ref<Asset>>> AssetManager::s_AssetCache;
std::map<std::type_index, Ref<Asset>> AssetManager::s_DefaultAsset;
Path AssetManager::s_WorkingDirectory;

Path AssetManager::GetWorkingDirectory()
{
    return s_WorkingDirectory;
}

void AssetManager::SetWorkingDirectory(const Path &path)
{
    s_WorkingDirectory = path;
}

} // namespace Lumen