#include "Lumen/UI/Module/LUIText.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

Vector2 CalcTextSize(const std::string &text)
{
    ImVec2 size = ImGui::CalcTextSize(text.c_str());
    return {size.x, size.y};
}

void Text(const std::string &text, FontScale scale)
{
    if (scale == FontScale::x100)
        ImGui::Text("%s", text.c_str());
    else
    {
        LUI::PushFont(scale);
        ImGui::Text("%s", text.c_str());
        LUI::PopFont();
    }
}

void TextDisabled(const std::string &text, FontScale scale)
{
    if (scale == FontScale::x100)
        ImGui::TextDisabled("%s", text.c_str());
    else
    {
        LUI::PushFont(scale);
        ImGui::TextDisabled("%s", text.c_str());
        LUI::PopFont();
    }
}

void TextWrapped(const std::string &text, FontScale scale)
{
    if (scale == FontScale::x100)
        ImGui::TextWrapped("%s", text.c_str());
    else
    {
        LUI::PushFont(scale);
        ImGui::TextWrapped("%s", text.c_str());
        LUI::PopFont();
    }
}

} // namespace Lumen::LUI