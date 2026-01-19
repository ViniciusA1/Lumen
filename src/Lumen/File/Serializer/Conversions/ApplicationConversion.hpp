#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const WindowFlags &flags);
template <> void Deserialize(const Yaml &yaml, WindowFlags &flags);

template <> Yaml Serialize(const ApplicationArgs &args);
template <> void Deserialize(const Yaml &yaml, ApplicationArgs &args);

} // namespace Lumen::YamlSerializer