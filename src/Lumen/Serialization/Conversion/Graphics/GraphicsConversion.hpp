#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Serialization/Json.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Color &color);
template <> void Deserialize(const Json &json, Color &color);

} // namespace Lumen::JsonSerializer