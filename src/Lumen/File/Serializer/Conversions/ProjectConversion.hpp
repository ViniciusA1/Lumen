#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/Project/Project.hpp"
#include "Lumen/Project/ProjectTemplate.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Project &project);
template <> void Deserialize(const Json &json, Project &project);

template <> Json Serialize(const ProjectTemplate &projTemplate);
template <> void Deserialize(const Json &json, ProjectTemplate &projTemplate);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Project &project);
template <> void Deserialize(const Yaml &yaml, Project &project);

template <> Yaml Serialize(const ProjectTemplate &projTemplate);
template <> void Deserialize(const Yaml &yaml, ProjectTemplate &projTemplate);

} // namespace Lumen::YamlSerializer