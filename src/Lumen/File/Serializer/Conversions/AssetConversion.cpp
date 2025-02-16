#include "Lumen/File/Serializer/Conversions/AssetConversion.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const std::unordered_map<UUID, AssetMetadata> &map)
{
    Yaml assetsYaml;
    for (const auto &[uuid, metadata] : map)
    {
        Yaml assetYaml;
        assetYaml["ID"] << uuid;
        assetYaml << metadata;
        assetsYaml.PushBack(assetYaml);
    }

    Yaml yaml;
    yaml["AssetRegistry"] = assetsYaml;

    return yaml;
}

template <>
void Deserialize(const Yaml &yaml, std::unordered_map<UUID, AssetMetadata> &map)
{
    for (const auto &assetYaml : yaml["AssetRegistry"])
    {
        UUID uuid = 0;
        AssetMetadata metadata;
        assetYaml["ID"] >> uuid;
        assetYaml >> metadata;
        map[uuid] = metadata;
    }
}

template <> Yaml Serialize(const AssetMetadata &metadata)
{
    Yaml yaml;
    yaml["Path"] << metadata.Path;
    yaml["Name"] << metadata.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, AssetMetadata &metadata)
{

    yaml["Path"] >> metadata.Path;
    yaml["Name"] >> metadata.Name;
}

} // namespace Lumen::YamlSerializer