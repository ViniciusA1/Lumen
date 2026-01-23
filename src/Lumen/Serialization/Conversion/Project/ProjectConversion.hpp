#pragma once

#include "Lumen/Serialization/Json.hpp"

#include "Lumen/Project/Project.hpp"
#include "Lumen/Project/ProjectTemplate.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Project &project);
template <> void Deserialize(const Json &json, Project &project);

template <> Json Serialize(const ProjectTemplate &projTemplate);
template <> void Deserialize(const Json &json, ProjectTemplate &projTemplate);

} // namespace Lumen::JsonSerializer