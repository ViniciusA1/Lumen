#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Serialization/Json.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Path &path);
template <> void Deserialize(const Json &json, Path &path);

} // namespace Lumen::JsonSerializer