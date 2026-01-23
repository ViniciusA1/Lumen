#include "Lumen/Serialization/Conversion/Asset/AssetConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AssetMetadata &metadata)
{
    Json json;
    json["Path"] << metadata.Path;
    json["Name"] << metadata.Name;
    return json;
}

template <> void Deserialize(const Json &json, AssetMetadata &metadata)
{
    json["Path"] >> metadata.Path;
    json["Name"] >> metadata.Name;
}

} // namespace Lumen::JsonSerializer