#pragma once

#include <array>
#include <string>

namespace Lumen
{

class ProjectLayer;

class ProjectTopBarPanel
{
public:
    ProjectTopBarPanel(ProjectLayer &layer);

    void Draw();

private:
    void DrawNewProjectOverlay();
    std::string DrawFileDialog();

private:
    ProjectLayer &m_ParentLayer;
    std::array<char, 128> m_NewProjectName = {""};
    std::array<char, 256> m_NewProjectPath = {""};
    std::array<char, 128> m_SearchBarFilter = {""};
    const std::array<std::array<char, 14>, 2> m_SortOption = {"Last Modified", "Name"};
    int m_CurrentSortOption = 0;
};

} // namespace Lumen