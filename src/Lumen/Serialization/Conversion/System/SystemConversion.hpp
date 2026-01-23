#pragma once

#include "Lumen/Serialization/Json.hpp"

#include "Lumen/System/UUID.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const UUID &uuid);
template <> void Deserialize(const Json &json, UUID &uuid);

} // namespace Lumen::JsonSerializer