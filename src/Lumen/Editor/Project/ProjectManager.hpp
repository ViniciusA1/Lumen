#pragma once

#include "Lumen/Editor/Project/Project.hpp"
#include <vector>

namespace Lumen
{

class ProjectManager
{
public:
    static void New(const Path &path, const std::string &name = "");
    static void Load(const Path &path);
    static void Save(Project &config = s_ActiveProject);
    static void Delete(Project &project);
    static bool IsLoaded(const Path &path);

    static inline Project &GetActiveProject();
    static inline auto &GetProjectList();
    static inline void SetActiveProject(const Project &project);

    static void LoadProjectList();
    static void SaveProjectList();

    static void SortProjectList(ProjectSortOption sortOption);

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

void ProjectManager::SetActiveProject(const Project &project)
{
    s_ActiveProject = project;
}

} // namespace Lumen