#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"
#include "Lumen/Serialization/Json.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ApplicationArgs &args);
template <> void Deserialize(const Json &json, ApplicationArgs &args);

template <> Json Serialize(const WindowFlags &flags);
template <> void Deserialize(const Json &json, WindowFlags &flags);

} // namespace Lumen::JsonSerializer