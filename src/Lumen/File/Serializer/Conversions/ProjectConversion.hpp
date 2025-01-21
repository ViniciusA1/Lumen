#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/Project/Project.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Project &project);
template <> void Deserialize(const Json &json, Project &project);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Project &project);
template <> void Deserialize(const Yaml &yaml, Project &project);

} // namespace Lumen::YamlSerializer