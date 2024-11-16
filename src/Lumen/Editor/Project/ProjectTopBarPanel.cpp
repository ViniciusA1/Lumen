#include "Lumen/Editor/Project/ProjectTopBarPanel.hpp"
#include "ImGuiFileDialog.h"
#include "Lumen/Editor/Project/ProjectLayer.hpp"
#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "imgui.h"
#include <algorithm>

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
        m_ParentLayer.PushOverlay([this]() { DrawImportProjectOverlay(); });
    }
    ImGui::SameLine();

    ImGui::SetNextItemWidth(200);
    ImGui::InputTextWithHint("##filter", "Filter Projects", m_SearchBarFilter.data(),
                             m_SearchBarFilter.size());
    ImGui::SameLine();

    ImGui::Text("Sort by:");
    ImGui::SameLine();

    ImGui::SetNextItemWidth(150);

    int sortOption = m_CurrentSortOption;
    ImGui::Combo("##SortOrder", &m_CurrentSortOption, m_SortOption.data()->data(),
                 m_SortOption.size());
    if (m_CurrentSortOption != sortOption)
    {
        ProjectManager::SortProjectList(static_cast<ProjectSortOption>(sortOption));
    }
}

void ProjectTopBarPanel::DrawNewProjectOverlay()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(400, 150));

    ImGui::OpenPopup("New Project");

    if (ImGui::BeginPopupModal("New Project", nullptr, ImGuiWindowFlags_NoCollapse))
    {
        ImGui::Text("Project Name:");
        ImGui::InputTextWithHint("##ProjectName", "Name", m_NewProjectName.data(),
                                 m_NewProjectName.size());

        ImGui::Text("Project Path:");
        ImGui::InputTextWithHint("##ProjectPath", "Path", m_NewProjectPath.data(),
                                 m_NewProjectPath.size());

        ImGui::SameLine();
        if (ImGui::Button("Browse"))
        {
            ImGuiFileDialog::Instance()->OpenDialog("NewProject", "Choose File", nullptr,
                                                    {"."});
        }

        DrawFileDialog("NewProject", m_NewProjectPath);

        ImGui::Separator();

        if (ImGui::Button("Create"))
        {
            ProjectManager::New({m_NewProjectPath.data()}, m_NewProjectName.data());
            ProjectManager::SaveProjectList();
            m_NewProjectPath = {};
            m_NewProjectName = {};
            ImGui::CloseCurrentPopup();
            m_ParentLayer.PopOverlay();
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel"))
        {
            ImGui::CloseCurrentPopup();
            m_ParentLayer.PopOverlay();
        }

        ImGui::EndPopup();
    }
}

void ProjectTopBarPanel::DrawImportProjectOverlay()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(400, 100));

    ImGui::OpenPopup("Import Project");

    if (ImGui::BeginPopupModal("Import Project", nullptr,
                               ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::Text("Project Path:");
        ImGui::SetNextItemWidth(300);
        ImGui::InputText("##ImportProjectPath", m_ImportProjectPath.data(),
                         m_ImportProjectPath.size());

        ImGui::SameLine();
        if (ImGui::Button("Browse"))
        {
            ImGuiFileDialog::Instance()->OpenDialog(
                "ImportProject", "Choose Project File", ".lproj", {"."});
        }

        DrawFileDialog("ImportProject", m_ImportProjectPath);

        ImGui::Separator();
        if (ImGui::Button("Import"))
        {
            if (!m_ImportProjectPath.empty())
            {
                ProjectManager::Load({m_ImportProjectPath.data()});
                m_ImportProjectPath = {};
                ImGui::CloseCurrentPopup();
                m_ParentLayer.PopOverlay();
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Cancel"))
        {
            m_ImportProjectPath = {};
            ImGui::CloseCurrentPopup();
            m_ParentLayer.PopOverlay();
        }

        ImGui::EndPopup();
    }
}

void ProjectTopBarPanel::DrawFileDialog(const std::string &key,
                                        std::array<char, 256> &pathBuffer)
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(600, 400));

    if (ImGuiFileDialog::Instance()->Display(key))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            std::string tmpPath = ImGuiFileDialog::Instance()->GetCurrentFileName();
            if (tmpPath.empty())
            {
                tmpPath = ImGuiFileDialog::Instance()->GetCurrentPath();
            }
            pathBuffer = {};
            std::copy(tmpPath.begin(), tmpPath.end(), pathBuffer.begin());
        }

        ImGuiFileDialog::Instance()->Close();
    }
}

} // namespace Lumen