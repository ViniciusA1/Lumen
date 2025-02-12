#pragma once

#include "Lumen/Project/ProjectTemplate.hpp"

namespace Lumen
{

class ProjectTemplateSerializer
{
public:
    ProjectTemplateSerializer() = default;

    bool Deserialize(ProjectTemplate &projTemplate, const Path &path);
    bool Serialize(const ProjectTemplate &projTemplate, const Path &path);
};

} // namespace Lumen