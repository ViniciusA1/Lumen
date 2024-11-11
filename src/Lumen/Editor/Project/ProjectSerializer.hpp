#pragma once

#include "Lumen/Editor/Project/Project.hpp"
#include <vector>

namespace Lumen
{

class ProjectSerializer
{
public:
    ProjectSerializer() = default;

    bool SerializeProject(Project &project, const std::filesystem::path &path);
    bool DeserializeProject(Project &project, const std::filesystem::path &path);

    bool SerializeProjectList(std::vector<Project> &projectList,
                              const std::filesystem::path &path);
    bool DeserializeProjectList(std::vector<Project> &projectList,
                                const std::filesystem::path &path);
};

} // namespace Lumen