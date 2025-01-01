#include "Lumen/UI/Style/Style.hpp"

namespace Lumen
{

const std::map<std::string, UI::StyleFlags> Style::StyleMap = {
    {"Alpha", UI::StyleFlags::Alpha},
    {"DisabledAlpha", UI::StyleFlags::DisabledAlpha},
    {"WindowPadding", UI::StyleFlags::WindowPadding},
    {"WindowRounding", UI::StyleFlags::WindowRounding},
    {"WindowBorderSize", UI::StyleFlags::WindowBorderSize},
    {"WindowMinSize", UI::StyleFlags::WindowMinSize},
    {"WindowTitleAlign", UI::StyleFlags::WindowTitleAlign},
    {"ChildRounding", UI::StyleFlags::ChildRounding},
    {"ChildBorderSize", UI::StyleFlags::ChildBorderSize},
    {"PopupRounding", UI::StyleFlags::PopupRounding},
    {"PopupBorderSize", UI::StyleFlags::PopupBorderSize},
    {"FramePadding", UI::StyleFlags::FramePadding},
    {"FrameRounding", UI::StyleFlags::FrameRounding},
    {"FrameBorderSize", UI::StyleFlags::FrameBorderSize},
    {"ItemSpacing", UI::StyleFlags::ItemSpacing},
    {"ItemInnerSpacing", UI::StyleFlags::ItemInnerSpacing},
    {"IndentSpacing", UI::StyleFlags::IndentSpacing},
    {"CellPadding", UI::StyleFlags::CellPadding},
    {"ScrollbarSize", UI::StyleFlags::ScrollbarSize},
    {"ScrollbarRounding", UI::StyleFlags::ScrollbarRounding},
    {"GrabMinSize", UI::StyleFlags::GrabMinSize},
    {"GrabRounding", UI::StyleFlags::GrabRounding},
    {"TabRounding", UI::StyleFlags::TabRounding},
    {"TabBorderSize", UI::StyleFlags::TabBorderSize},
    {"TabBarBorderSize", UI::StyleFlags::TabBarBorderSize},
    {"TabBarOverlineSize", UI::StyleFlags::TabBarOverlineSize},
    {"TableAngledHeadersAngle", UI::StyleFlags::TableAngledHeadersAngle},
    {"TableAngledHeadersTextAlign", UI::StyleFlags::TableAngledHeadersTextAlign},
    {"ButtonTextAlign", UI::StyleFlags::ButtonTextAlign},
    {"SelectableTextAlign", UI::StyleFlags::SelectableTextAlign},
    {"SeparatorTextBorderSize", UI::StyleFlags::SeparatorTextBorderSize},
    {"SeparatorTextAlign", UI::StyleFlags::SeparatorTextAlign},
    {"SeparatorTextPadding", UI::StyleFlags::SeparatorTextPadding},
    {"DockingSeparatorSize", UI::StyleFlags::DockingSeparatorSize},
};

const std::map<std::string, UI::ColorFlags> Style::ColorMap = {
    {"Text", UI::ColorFlags::Text},
    {"TextDisabled", UI::ColorFlags::TextDisabled},
    {"WindowBg", UI::ColorFlags::WindowBg},
    {"ChildBg", UI::ColorFlags::ChildBg},
    {"PopupBg", UI::ColorFlags::PopupBg},
    {"Border", UI::ColorFlags::Border},
    {"BorderShadow", UI::ColorFlags::BorderShadow},
    {"FrameBg", UI::ColorFlags::FrameBg},
    {"FrameBgHovered", UI::ColorFlags::FrameBgHovered},
    {"FrameBgActive", UI::ColorFlags::FrameBgActive},
    {"TitleBg", UI::ColorFlags::TitleBg},
    {"TitleBgActive", UI::ColorFlags::TitleBgActive},
    {"TitleBgCollapsed", UI::ColorFlags::TitleBgCollapsed},
    {"MenuBarBg", UI::ColorFlags::MenuBarBg},
    {"ScrollbarBg", UI::ColorFlags::ScrollbarBg},
    {"ScrollbarGrab", UI::ColorFlags::ScrollbarGrab},
    {"ScrollbarGrabHovered", UI::ColorFlags::ScrollbarGrabHovered},
    {"ScrollbarGrabActive", UI::ColorFlags::ScrollbarGrabActive},
    {"CheckMark", UI::ColorFlags::CheckMark},
    {"SliderGrab", UI::ColorFlags::SliderGrab},
    {"SliderGrabActive", UI::ColorFlags::SliderGrabActive},
    {"Button", UI::ColorFlags::Button},
    {"ButtonHovered", UI::ColorFlags::ButtonHovered},
    {"ButtonActive", UI::ColorFlags::ButtonActive},
    {"Header", UI::ColorFlags::Header},
    {"HeaderHovered", UI::ColorFlags::HeaderHovered},
    {"HeaderActive", UI::ColorFlags::HeaderActive},
    {"Separator", UI::ColorFlags::Separator},
    {"SeparatorHovered", UI::ColorFlags::SeparatorHovered},
    {"SeparatorActive", UI::ColorFlags::SeparatorActive},
    {"ResizeGrip", UI::ColorFlags::ResizeGrip},
    {"ResizeGripHovered", UI::ColorFlags::ResizeGripHovered},
    {"ResizeGripActive", UI::ColorFlags::ResizeGripActive},
    {"TabHovered", UI::ColorFlags::TabHovered},
    {"Tab", UI::ColorFlags::Tab},
    {"TabSelected", UI::ColorFlags::TabSelected},
    {"TabSelectedOverline", UI::ColorFlags::TabSelectedOverline},
    {"TabDimmed", UI::ColorFlags::TabDimmed},
    {"TabDimmedSelected", UI::ColorFlags::TabDimmedSelected},
    {"TabDimmedSelectedOverline", UI::ColorFlags::TabDimmedSelectedOverline},
    {"DockingPreview", UI::ColorFlags::DockingPreview},
    {"DockingEmptyBg", UI::ColorFlags::DockingEmptyBg},
    {"PlotLines", UI::ColorFlags::PlotLines},
    {"PlotLinesHovered", UI::ColorFlags::PlotLinesHovered},
    {"PlotHistogram", UI::ColorFlags::PlotHistogram},
    {"PlotHistogramHovered", UI::ColorFlags::PlotHistogramHovered},
    {"TableHeaderBg", UI::ColorFlags::TableHeaderBg},
    {"TableBorderStrong", UI::ColorFlags::TableBorderStrong},
    {"TableBorderLight", UI::ColorFlags::TableBorderLight},
    {"TableRowBg", UI::ColorFlags::TableRowBg},
    {"TableRowBgAlt", UI::ColorFlags::TableRowBgAlt},
    {"TextLink", UI::ColorFlags::TextLink},
    {"TextSelectedBg", UI::ColorFlags::TextSelectedBg},
    {"DragDropTarget", UI::ColorFlags::DragDropTarget},
    {"NavHighlight", UI::ColorFlags::NavHighlight},
    {"NavWindowingHighlight", UI::ColorFlags::NavWindowingHighlight},
    {"NavWindowingDimBg", UI::ColorFlags::NavWindowingDimBg},
    {"ModalWindowDimBg", UI::ColorFlags::ModalWindowDimBg},
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