#include "Lumen/Asset/AssetManagerSerializer.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool AssetManagerSerializer::Serialize(const Path &path)
{
    Yaml yaml;
    yaml << AssetManager::GetMetadataMap();
    return yaml.ToFile(path / "AssetRegistry.lasset");
}

bool AssetManagerSerializer::Deserialize(const Path &path)
{
    Yaml yaml = Yaml::FromFile(path / "AssetRegistry.lasset");
    if (yaml.IsNull())
        return false;

    yaml >> AssetManager::GetMetadataMap();
    return true;
}

} // namespace Lumen