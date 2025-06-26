#pragma once

#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

bool CollapsingHeader(const std::string &label,
                      TreeNodeFlags flags = TreeNodeFlags::None);

bool TreeNode(const std::string &label, TreeNodeFlags flags = TreeNodeFlags::None);
void TreePop();

} // namespace Lumen::LUI