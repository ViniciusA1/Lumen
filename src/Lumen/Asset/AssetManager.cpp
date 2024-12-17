#include "Lumen/Asset/AssetManager.hpp"

namespace Lumen
{

std::map<std::type_index, std::map<UUID, Ref<Asset>>> AssetManager::m_AssetCache;
std::map<std::type_index, Ref<Asset>> AssetManager::m_DefaultAsset;

} // namespace Lumen