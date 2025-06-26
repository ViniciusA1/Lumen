#include "Lumen/UI/Module/LUIPopup.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

bool BeginPopupContextWindow(const std::string &label, PopupFlags flags)
{
    return ImGui::BeginPopupContextWindow(label.empty() ? nullptr : label.c_str(),
                                          static_cast<int>(flags));
}

bool BeginPopupContextItem(const std::string &label, PopupFlags flags)
{
    return ImGui::BeginPopupContextItem(label.empty() ? nullptr : label.c_str(),
                                        static_cast<int>(flags));
}

bool BeginPopupModal(const std::string &name, bool *p_open, WindowFlags flags)
{
    return ImGui::BeginPopupModal(name.c_str(), p_open, static_cast<int>(flags));
}

void CloseCurrentPopup()
{
    ImGui::CloseCurrentPopup();
}

void EndPopup()
{
    ImGui::EndPopup();
}

void OpenPopup(const std::string &label, PopupFlags flags)
{
    ImGui::OpenPopup(label.c_str(), static_cast<int>(flags));
}

} // namespace Lumen::LUI