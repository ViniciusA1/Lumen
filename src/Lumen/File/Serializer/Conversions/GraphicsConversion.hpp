#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/Graphics/Color.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Color &color);
template <> void Deserialize(const Json &json, Color &color);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Color &color);
template <> void Deserialize(const Yaml &yaml, Color &color);

} // namespace Lumen::YamlSerializer