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

    inline const std::array<char, 128> &GetSearchFilter();

    void Draw();

private:
    void DrawNewProjectOverlay();
    void DrawImportProjectOverlay();
    void DrawFileDialog(const std::string &key, std::array<char, 256> &pathBuffer);

private:
    ProjectLayer &m_ParentLayer;
    std::array<char, 128> m_NewProjectName = {""};
    std::array<char, 256> m_NewProjectPath = {""};
    std::array<char, 256> m_ImportProjectPath = {""};
    std::array<char, 128> m_SearchBarFilter = {""};
    const std::array<std::array<char, 14>, 2> m_SortOption = {"Last Modified", "Name"};
    int m_CurrentSortOption = 0;
};

const std::array<char, 128> &ProjectTopBarPanel::GetSearchFilter()
{
    return m_SearchBarFilter;
}

} // namespace Lumen