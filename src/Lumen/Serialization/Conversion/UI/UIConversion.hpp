#pragma once

#include "Lumen/Serialization/Json.hpp"

#include "Lumen/UI/Module/LUIStyle.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LUI::Style &style);
template <> void Deserialize(const Json &json, LUI::Style &style);

} // namespace Lumen::JsonSerializer