#pragma once

#include "Lumen/Asset/AssetMetadata.hpp"
#include "Lumen/Asset/AssetType.hpp"
#include "Lumen/Serialization/Json.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AssetType &assetType);
template <> void Deserialize(const Json &json, AssetType &assetType);

template <> Json Serialize(const AssetMetadata &metadata);
template <> void Deserialize(const Json &json, AssetMetadata &metadata);

template <> Json Serialize(const std::unordered_map<AssetHandle, AssetMetadata> &map);
template <>
void Deserialize(const Json &json, std::unordered_map<AssetHandle, AssetMetadata> &map);

} // namespace Lumen::JsonSerializer