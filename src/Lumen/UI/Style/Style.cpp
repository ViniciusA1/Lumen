#include "Lumen/UI/Style/Style.hpp"

namespace Lumen
{

const std::map<std::string, ImGuiStyleVar_> Style::VarMap = {
    {"Alpha", ImGuiStyleVar_Alpha},
    {"DisabledAlpha", ImGuiStyleVar_DisabledAlpha},
    {"WindowPadding", ImGuiStyleVar_WindowPadding},
    {"WindowRounding", ImGuiStyleVar_WindowRounding},
    {"WindowBorderSize", ImGuiStyleVar_WindowBorderSize},
    {"WindowMinSize", ImGuiStyleVar_WindowMinSize},
    {"WindowTitleAlign", ImGuiStyleVar_WindowTitleAlign},
    {"ChildRounding", ImGuiStyleVar_ChildRounding},
    {"ChildBorderSize", ImGuiStyleVar_ChildBorderSize},
    {"PopupRounding", ImGuiStyleVar_PopupRounding},
    {"PopupBorderSize", ImGuiStyleVar_PopupBorderSize},
    {"FramePadding", ImGuiStyleVar_FramePadding},
    {"FrameRounding", ImGuiStyleVar_FrameRounding},
    {"FrameBorderSize", ImGuiStyleVar_FrameBorderSize},
    {"ItemSpacing", ImGuiStyleVar_ItemSpacing},
    {"ItemInnerSpacing", ImGuiStyleVar_ItemInnerSpacing},
    {"IndentSpacing", ImGuiStyleVar_IndentSpacing},
    {"CellPadding", ImGuiStyleVar_CellPadding},
    {"ScrollbarSize", ImGuiStyleVar_ScrollbarSize},
    {"ScrollbarRounding", ImGuiStyleVar_ScrollbarRounding},
    {"GrabMinSize", ImGuiStyleVar_GrabMinSize},
    {"GrabRounding", ImGuiStyleVar_GrabRounding},
    {"TabRounding", ImGuiStyleVar_TabRounding},
    {"TabBorderSize", ImGuiStyleVar_TabBorderSize},
    {"TabBarBorderSize", ImGuiStyleVar_TabBarBorderSize},
    {"TabBarOverlineSize", ImGuiStyleVar_TabBarOverlineSize},
    {"TableAngledHeadersAngle", ImGuiStyleVar_TableAngledHeadersAngle},
    {"TableAngledHeadersTextAlign", ImGuiStyleVar_TableAngledHeadersTextAlign},
    {"ButtonTextAlign", ImGuiStyleVar_ButtonTextAlign},
    {"SelectableTextAlign", ImGuiStyleVar_SelectableTextAlign},
    {"SeparatorTextBorderSize", ImGuiStyleVar_SeparatorTextBorderSize},
    {"SeparatorTextAlign", ImGuiStyleVar_SeparatorTextAlign},
    {"SeparatorTextPadding", ImGuiStyleVar_SeparatorTextPadding},
    {"DockingSeparatorSize", ImGuiStyleVar_DockingSeparatorSize},
};

const std::map<std::string, ImGuiCol_> Style::ColorMap = {
    {"Text", ImGuiCol_Text},
    {"TextDisabled", ImGuiCol_TextDisabled},
    {"WindowBg", ImGuiCol_WindowBg},
    {"ChildBg", ImGuiCol_ChildBg},
    {"PopupBg", ImGuiCol_PopupBg},
    {"Border", ImGuiCol_Border},
    {"BorderShadow", ImGuiCol_BorderShadow},
    {"FrameBg", ImGuiCol_FrameBg},
    {"FrameBgHovered", ImGuiCol_FrameBgHovered},
    {"FrameBgActive", ImGuiCol_FrameBgActive},
    {"TitleBg", ImGuiCol_TitleBg},
    {"TitleBgActive", ImGuiCol_TitleBgActive},
    {"TitleBgCollapsed", ImGuiCol_TitleBgCollapsed},
    {"MenuBarBg", ImGuiCol_MenuBarBg},
    {"ScrollbarBg", ImGuiCol_ScrollbarBg},
    {"ScrollbarGrab", ImGuiCol_ScrollbarGrab},
    {"ScrollbarGrabHovered", ImGuiCol_ScrollbarGrabHovered},
    {"ScrollbarGrabActive", ImGuiCol_ScrollbarGrabActive},
    {"CheckMark", ImGuiCol_CheckMark},
    {"SliderGrab", ImGuiCol_SliderGrab},
    {"SliderGrabActive", ImGuiCol_SliderGrabActive},
    {"Button", ImGuiCol_Button},
    {"ButtonHovered", ImGuiCol_ButtonHovered},
    {"ButtonActive", ImGuiCol_ButtonActive},
    {"Header", ImGuiCol_Header},
    {"HeaderHovered", ImGuiCol_HeaderHovered},
    {"HeaderActive", ImGuiCol_HeaderActive},
    {"Separator", ImGuiCol_Separator},
    {"SeparatorHovered", ImGuiCol_SeparatorHovered},
    {"SeparatorActive", ImGuiCol_SeparatorActive},
    {"ResizeGrip", ImGuiCol_ResizeGrip},
    {"ResizeGripHovered", ImGuiCol_ResizeGripHovered},
    {"ResizeGripActive", ImGuiCol_ResizeGripActive},
    {"TabHovered", ImGuiCol_TabHovered},
    {"Tab", ImGuiCol_Tab},
    {"TabSelected", ImGuiCol_TabSelected},
    {"TabSelectedOverline", ImGuiCol_TabSelectedOverline},
    {"TabDimmed", ImGuiCol_TabDimmed},
    {"TabDimmedSelected", ImGuiCol_TabDimmedSelected},
    {"TabDimmedSelectedOverline", ImGuiCol_TabDimmedSelectedOverline},
    {"DockingPreview", ImGuiCol_DockingPreview},
    {"DockingEmptyBg", ImGuiCol_DockingEmptyBg},
    {"PlotLines", ImGuiCol_PlotLines},
    {"PlotLinesHovered", ImGuiCol_PlotLinesHovered},
    {"PlotHistogram", ImGuiCol_PlotHistogram},
    {"PlotHistogramHovered", ImGuiCol_PlotHistogramHovered},
    {"TableHeaderBg", ImGuiCol_TableHeaderBg},
    {"TableBorderStrong", ImGuiCol_TableBorderStrong},
    {"TableBorderLight", ImGuiCol_TableBorderLight},
    {"TableRowBg", ImGuiCol_TableRowBg},
    {"TableRowBgAlt", ImGuiCol_TableRowBgAlt},
    {"TextLink", ImGuiCol_TextLink},
    {"TextSelectedBg", ImGuiCol_TextSelectedBg},
    {"DragDropTarget", ImGuiCol_DragDropTarget},
    {"NavHighlight", ImGuiCol_NavHighlight},
    {"NavWindowingHighlight", ImGuiCol_NavWindowingHighlight},
    {"NavWindowingDimBg", ImGuiCol_NavWindowingDimBg},
    {"ModalWindowDimBg", ImGuiCol_ModalWindowDimBg},
};

Style::Style(const ImGuiStyle &style) : m_ImGuiStyle(style)
{
}

Style::Style(std::string name) : m_Name(std::move(name))
{
}

Style::Style(std::string name, const ImGuiStyle &style)
    : m_Name(std::move(name)), m_ImGuiStyle(style)
{
}

const ImGuiStyle &Style::GetImGuiStyle() const
{
    return m_ImGuiStyle;
}

std::string Style::GetName() const
{
    return m_Name;
}

} // namespace Lumen