#pragma once

#include "Lumen/Asset/AssetMetadata.hpp"
#include "Lumen/Core/UUID.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const std::unordered_map<UUID, AssetMetadata> &map);
template <>
void Deserialize(const Yaml &yaml, std::unordered_map<UUID, AssetMetadata> &map);

template <> Yaml Serialize(const AssetMetadata &metadata);
template <> void Deserialize(const Yaml &yaml, AssetMetadata &metadata);

} // namespace Lumen::YamlSerializer