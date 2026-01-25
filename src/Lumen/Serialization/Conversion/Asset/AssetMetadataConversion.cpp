#include "Lumen/Serialization/Conversion/Asset/AssetConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AssetMetadata &metadata)
{
    Json json;
    json["Handle"] << metadata.Handle;
    json["Type"] << metadata.Type;
    return json;
}

template <> void Deserialize(const Json &json, AssetMetadata &metadata)
{
    json["Handle"] >> metadata.Handle;
    json["Type"] >> metadata.Type;
}

} // namespace Lumen::JsonSerializer