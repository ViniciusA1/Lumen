#include "Lumen/UI/Module/LUITree.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

bool CollapsingHeader(const std::string &label, TreeNodeFlags flags)
{
    return ImGui::CollapsingHeader(label.c_str(), static_cast<int>(flags));
}

bool TreeNode(const std::string &label, TreeNodeFlags flags)
{
    return ImGui::TreeNodeEx(label.c_str(), static_cast<int>(flags));
}

void TreePop()
{
    ImGui::TreePop();
}

} // namespace Lumen::LUI