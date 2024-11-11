#include "Lumen/Editor/Project/ProjectTopBarPanel.hpp"
#include "ImGuiFileDialog.h"
#include "Lumen/Editor/Project/ProjectLayer.hpp"
#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "imgui.h"

namespace Lumen
{

ProjectTopBarPanel::ProjectTopBarPanel(ProjectLayer &projectLayer)
    : m_ParentLayer(projectLayer)
{
}

void ProjectTopBarPanel::Draw()
{
    if (ImGui::Button("Create"))
    {
        m_ParentLayer.PushOverlay([this]() { DrawNewProjectOverlay(); });
    }
    ImGui::SameLine();
    if (ImGui::Button("Import"))
    {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File",
                                                ".lproj", {"."});
    }
    ImGui::SameLine();

    ImGui::SetNextItemWidth(200);
    ImGui::InputTextWithHint("##filter", "Filter Projects", m_SearchBarFilter.data(),
                             m_SearchBarFilter.size());
    ImGui::SameLine();

    ImGui::Text("Sort by:");
    ImGui::SameLine();

    ImGui::SetNextItemWidth(150);
    ImGui::Combo("##SortOrder", &m_CurrentSortOption, m_SortOption.data()->data(),
                 m_SortOption.size());
}

void ProjectTopBarPanel::DrawNewProjectOverlay()
{
    ImGui::Begin("New Project", nullptr, ImGuiWindowFlags_NoCollapse);

    ImGui::Text("Project Name:");
    ImGui::InputText("##ProjectName", m_NewProjectName.data(), m_NewProjectName.size());

    ImGui::Text("Project Path:");
    ImGui::InputText("##ProjectPath", m_NewProjectPath.data(), m_NewProjectPath.size());

    ImGui::SameLine();
    if (ImGui::Button("Browse"))
    {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File",
                                                nullptr, {"."});
    }

    std::string path = DrawFileDialog();
    if (!path.empty())
    {
        m_NewProjectPath = {};
        std::copy(path.begin(), path.end(), m_NewProjectPath.begin());
    }

    ImGui::Separator();

    if (ImGui::Button("Create"))
    {
        ProjectManager::New(m_NewProjectPath.data());
        ProjectManager::SaveProjectList();
        m_ParentLayer.PopOverlay();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel"))
    {
        m_ParentLayer.PopOverlay();
    }

    ImGui::End();
}

std::string ProjectTopBarPanel::DrawFileDialog()
{
    std::string path = "";

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            path = ImGuiFileDialog::Instance()->GetCurrentFileName();
            if (path.empty())
            {
                path = ImGuiFileDialog::Instance()->GetCurrentPath();
            }
        }

        ImGuiFileDialog::Instance()->Close();
    }

    return path;
}

} // namespace Lumen