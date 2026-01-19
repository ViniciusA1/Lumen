#pragma once

#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"
#include "Lumen/System/Function.hpp"

#include <string>
#include <vector>

namespace Lumen
{

struct DropdownComponent : public UIComponentBase
{
    std::vector<std::string> Options;
    int SelectedIndex = 0;
    bool IsExpanded = false;
    int MaxVisibleItems = 5;
    Function<void(int, const std::string &)> OnValueChanged;
};

} // namespace Lumen