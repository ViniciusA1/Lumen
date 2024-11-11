#pragma once

#include "Lumen/Editor/Project/Project.hpp"
#include <array>

namespace Lumen
{

class ProjectLayer;

class ProjectListPanel
{
public:
    ProjectListPanel(ProjectLayer &projectLayer);

    void Draw();

private:
    void DrawRenameProjectOverlay(Project &project);
    void DrawDeleteProjectOverlay(Project &project);

private:
    ProjectLayer &m_ParentLayer;
    std::array<char, 128> m_RenameString;
};

} // namespace Lumen