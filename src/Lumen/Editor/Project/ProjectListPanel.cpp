#include "Lumen/Editor/Project/ProjectListPanel.hpp"
#include "Lumen/Editor/Project/ProjectLayer.hpp"
#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "imgui.h"

namespace Lumen
{
ProjectListPanel::ProjectListPanel(ProjectLayer &projectLayer)
    : m_ParentLayer(projectLayer)
{
}

void ProjectListPanel::Draw()
{
    for (auto &project : ProjectManager::GetProjectList())
    {
        ProjectConfig &config = project.GetConfig();

        ImGui::PushID(config.Name.c_str());

        ImGui::SameLine();

        ImGui::BeginGroup();
        ImGui::Text("%s", config.Name.c_str());
        ImGui::Text("%s", config.RootDirectory.string().c_str());
        ImGui::EndGroup();

        ImGui::SameLine(ImGui::GetWindowContentRegionMax().x - 200);
        if (ImGui::Button("Run"))
        {
        }
        ImGui::SameLine();
        if (ImGui::Button("Rename"))
        {
            m_ParentLayer.PushOverlay(
                [this, &project = project]() { DrawRenameProjectOverlay(project); });
        }
        ImGui::SameLine();
        if (ImGui::Button("Delete"))
        {
            m_ParentLayer.PushOverlay(
                [this, &project = project]() { DrawDeleteProjectOverlay(project); });
        }

        ImGui::Separator();
        ImGui::PopID();
    }
}

void ProjectListPanel::DrawRenameProjectOverlay(Project &project)
{
    ImGui::OpenPopup("Rename Project");

    if (ImGui::BeginPopupModal("Rename Project", nullptr,
                               ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::InputText("New Name", m_RenameString.data(), m_RenameString.size());
        if (ImGui::Button("OK"))
        {
            project.GetConfig().Name = m_RenameString.data();
            ImGui::CloseCurrentPopup();
            m_RenameString = {""};
            ProjectManager::Save(project);
            m_ParentLayer.PopOverlay();
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel"))
        {
            ImGui::CloseCurrentPopup();
            m_RenameString = {""};
            m_ParentLayer.PopOverlay();
        }
        ImGui::EndPopup();
    }
}

void ProjectListPanel::DrawDeleteProjectOverlay(Project &project)
{
    ImGui::OpenPopup("Delete Project");

    if (ImGui::BeginPopupModal("Delete Project", nullptr,
                               ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Are you sure you want to delete this project?");
        if (ImGui::Button("Yes"))
        {
            ProjectManager::Delete(project);
            ImGui::CloseCurrentPopup();
            ProjectManager::SaveProjectList();
            m_ParentLayer.PopOverlay();
        }
        ImGui::SameLine();
        if (ImGui::Button("No"))
        {
            ImGui::CloseCurrentPopup();
            m_ParentLayer.PopOverlay();
        }
        ImGui::EndPopup();
    }
}

} // namespace Lumen