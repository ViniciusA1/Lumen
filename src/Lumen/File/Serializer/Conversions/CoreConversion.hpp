#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/System/UUID.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const UUID &uuid);
template <> void Deserialize(const Json &json, UUID &uuid);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const UUID &uuid);
template <> void Deserialize(const Yaml &yaml, UUID &uuid);

} // namespace Lumen::YamlSerializer