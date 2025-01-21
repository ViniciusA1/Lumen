#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Path &path);
template <> void Deserialize(const Json &json, Path &path);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Path &path);
template <> void Deserialize(const Yaml &yaml, Path &path);

} // namespace Lumen::YamlSerializer