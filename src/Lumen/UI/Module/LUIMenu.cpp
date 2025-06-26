#include "Lumen/UI/Module/LUIMenu.hpp"

#include "imgui.h"
#include "imgui_internal.h"

namespace Lumen::LUI
{

bool BeginMainMenuBar()
{
    return ImGui::BeginMainMenuBar();
}

void EndMainMenuBar()
{
    ImGui::EndMainMenuBar();
}

bool BeginMenu(const std::string &label, bool enabled)
{
    return ImGui::BeginMenu(label.c_str(), enabled);
}

void EndMenu()
{
    ImGui::EndMenu();
}

bool BeginSideMenu(const std::string &label, WindowFlags flags)
{
    ImGui::PushID(label.c_str());
    ImGuiID dockspace_id = ImGui::GetID("##SideMenuDockspace");
    ImVec2 size = ImGui::GetContentRegionAvail();
    ImGui::DockSpace(dockspace_id, size, ImGuiDockNodeFlags_NoDockingSplit);

    ImGuiStorage *storage = ImGui::GetStateStorage();
    ImGuiID init_key = ImGui::GetID("##SideMenuInitialized");
    if (!storage->GetBool(init_key, false))
    {
        ImGui::DockBuilderRemoveNode(dockspace_id);
        ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dockspace_id, size);

        ImGuiID left_id, right_id;
        ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.25f, &left_id,
                                    &right_id);

        ImGui::DockBuilderDockWindow((label + "##SideMenu").c_str(), left_id);
        ImGui::DockBuilderDockWindow((label + "##MainContent").c_str(), right_id);

        ImGui::DockBuilderFinish(dockspace_id);
        storage->SetBool(init_key, true);
    }

    ImGui::PopID();

    ImGuiWindowClass windowClass;
    windowClass.DockNodeFlagsOverrideSet =
        ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoDockingOverMe;
    ImGui::SetNextWindowClass(&windowClass);
    return ImGui::Begin((label + "##SideMenu").c_str(), nullptr, static_cast<int>(flags));
}

void EndSideMenu()
{
    ImGui::End();
}

bool BeginMainContent(const std::string &label, WindowFlags flags)
{
    ImGuiWindowClass windowClass;
    windowClass.DockNodeFlagsOverrideSet =
        ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoDockingOverMe;
    ImGui::SetNextWindowClass(&windowClass);
    return ImGui::Begin((label + "##MainContent").c_str(), nullptr,
                        static_cast<int>(flags));
}

void EndMainContent()
{
    ImGui::End();
}

bool MenuItem(const std::string &label, const std::string &shortcut, bool selected,
              bool enabled)
{
    return ImGui::MenuItem(label.c_str(), shortcut.empty() ? nullptr : shortcut.c_str(),
                           selected, enabled);
}

} // namespace Lumen::LUI