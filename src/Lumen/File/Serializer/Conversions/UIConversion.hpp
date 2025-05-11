#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/UI/LUIStyle.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LUIStyle &style);
template <> void Deserialize(const Json &json, LUIStyle &style);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const LUIStyle &style);
template <> void Deserialize(const Yaml &yaml, LUIStyle &style);

} // namespace Lumen::YamlSerializer