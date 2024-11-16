#pragma once

#include "Lumen/Editor/Project/Project.hpp"
#include <vector>

namespace Lumen
{

class ProjectSerializer
{
public:
    ProjectSerializer() = default;

    bool SerializeProject(Project &project, const Path &path);
    bool DeserializeProject(Project &project, const Path &path);

    bool SerializeProjectList(std::vector<Project> &projectList, const Path &path);
    bool DeserializeProjectList(std::vector<Project> &projectList, const Path &path);
};

} // namespace Lumen