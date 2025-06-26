#pragma once

#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

bool BeginPopupContextWindow(const std::string &label = "",
                             PopupFlags flags = PopupFlags::MouseButtonRight);

bool BeginPopupContextItem(const std::string &label = "",
                           PopupFlags flags = PopupFlags::MouseButtonRight);

bool BeginPopupModal(const std::string &name, bool *p_open = nullptr,
                     WindowFlags flags = WindowFlags::None);
void CloseCurrentPopup();
void EndPopup();

void OpenPopup(const std::string &label, PopupFlags flags = PopupFlags::None);

} // namespace Lumen::LUI