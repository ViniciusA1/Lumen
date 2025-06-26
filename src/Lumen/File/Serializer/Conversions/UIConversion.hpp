#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/UI/Module/LUIStyle.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LUI::Style &style);
template <> void Deserialize(const Json &json, LUI::Style &style);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const LUI::Style &style);
template <> void Deserialize(const Yaml &yaml, LUI::Style &style);

} // namespace Lumen::YamlSerializer