#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/UI/Style/Style.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Style &style);
template <> void Deserialize(const Json &json, Style &style);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Style &style);
template <> void Deserialize(const Yaml &yaml, Style &style);

} // namespace Lumen::YamlSerializer