#include "Lumen/Serialization/Conversion/Asset/AssetConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AssetType &assetType)
{
    Json json;
    json << static_cast<int>(assetType);
    return json;
}

template <> void Deserialize(const Json &json, AssetType &assetType)
{
    int typeInt;
    json >> typeInt;
    assetType = static_cast<AssetType>(typeInt);
}

} // namespace Lumen::JsonSerializer