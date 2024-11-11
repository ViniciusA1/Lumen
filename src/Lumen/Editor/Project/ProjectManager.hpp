#pragma once

#include "Lumen/Editor/Project/Project.hpp"
#include <vector>

namespace Lumen
{

class ProjectManager
{
public:
    static void New(const std::filesystem::path &path, const std::string &name = "");
    static void Load(const std::filesystem::path &path);
    static void Save(Project &config = s_ActiveProject);
    static void Delete(Project &project);

    static inline Project &GetActiveProject();
    static inline auto &GetProjectList();

    static void LoadProjectList();
    static void SaveProjectList();

private:
    static Project s_ActiveProject;
    static std::vector<Project> s_ProjectList;
};

Project &ProjectManager::GetActiveProject()
{
    return s_ActiveProject;
}

auto &ProjectManager::GetProjectList()
{
    return s_ProjectList;
}

} // namespace Lumen