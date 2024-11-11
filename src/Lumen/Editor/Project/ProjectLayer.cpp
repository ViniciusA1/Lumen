#include "Lumen/Editor/Project/ProjectLayer.hpp"
#include "ImGuiFileDialog.h"
#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "imgui.h"

namespace Lumen
{

ProjectLayer::ProjectLayer(std::string name, bool visible)
    : ImGuiLayer(std::move(name), visible), m_ProjectListPanel(*this),
      m_TopBarPanel(*this)
{
    ProjectManager::LoadProjectList();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void ProjectLayer::OnDraw()
{
    ImGui::DockSpaceOverViewport();
    ImGui::Begin("Project Manager", nullptr,
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    m_TopBarPanel.Draw();

    ImGui::Separator();
    ImGui::Text("Projects:");
    ImGui::Separator();

    m_ProjectListPanel.Draw();

    DrawOverlay();

    ImGui::End();
}

std::string ProjectLayer::DrawFileDialog()
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