#include "Lumen/UI/Module/LUIDock.hpp"

#include "imgui.h"
#include "imgui_internal.h"

namespace Lumen::LUI
{

void DockSpace(ID id, const Vector2 &size, DockNodeFlags flags)
{
    ImGui::DockSpace(id, size, static_cast<int>(flags));
}

void DockSpaceOverViewport(ID id, DockNodeFlags flags)
{
    ImGui::DockSpaceOverViewport(id, nullptr, static_cast<int>(flags));
}

void DockBuilderRemoveNode(ID nodeID)
{
    ImGui::DockBuilderRemoveNode(nodeID);
}

void DockBuilderAddNode(ID nodeID, DockNodeFlags flags)
{
    ImGui::DockBuilderAddNode(nodeID, static_cast<int>(flags));
}

void DockBuilderSetNodeSize(ID nodeID, const Vector2 &size)
{
    ImGui::DockBuilderSetNodeSize(nodeID, size);
}

ID DockBuilderSplitNode(ID nodeID, Direction splitDir, float sizeRatioForNodeAtDir,
                        ID *outIDAtDir, ID *outIDAtOppositeDir)
{
    return ImGui::DockBuilderSplitNode(nodeID, static_cast<ImGuiDir>(splitDir),
                                       sizeRatioForNodeAtDir, outIDAtDir,
                                       outIDAtOppositeDir);
}

void DockBuilderDockWindow(const std::string &windowName, ID nodeID)
{
    ImGui::DockBuilderDockWindow(windowName.c_str(), nodeID);
}

void DockBuilderFinish(ID nodeID)
{
    ImGui::DockBuilderFinish(nodeID);
}

} // namespace Lumen::LUI