#include "Lumen/UI/Module/LUIStyle.hpp"
#include "Lumen/UI/LUIStyleSerializer.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

static Style s_Style;

void InitStyle()
{
    LUIStyleSerializer serializer;
    if (serializer.Deserialize("assets/LUI/Style/Dark.json", s_Style))
    {
        SetStyle(s_Style);
    }
}

Style GetStyle()
{
    return s_Style;
}

void SetStyle(const Style &style)
{
    s_Style = style;
    ImGui::GetStyle() = style;
}

} // namespace Lumen::LUI

namespace Lumen::LUI
{

const std::map<std::string, LUI::StyleFlags> Style::StyleMap = {
    {"Alpha", LUI::StyleFlags::Alpha},
    {"DisabledAlpha", LUI::StyleFlags::DisabledAlpha},
    {"WindowPadding", LUI::StyleFlags::WindowPadding},
    {"WindowRounding", LUI::StyleFlags::WindowRounding},
    {"WindowBorderSize", LUI::StyleFlags::WindowBorderSize},
    {"WindowMinSize", LUI::StyleFlags::WindowMinSize},
    {"WindowTitleAlign", LUI::StyleFlags::WindowTitleAlign},
    {"ChildRounding", LUI::StyleFlags::ChildRounding},
    {"ChildBorderSize", LUI::StyleFlags::ChildBorderSize},
    {"PopupRounding", LUI::StyleFlags::PopupRounding},
    {"PopupBorderSize", LUI::StyleFlags::PopupBorderSize},
    {"FramePadding", LUI::StyleFlags::FramePadding},
    {"FrameRounding", LUI::StyleFlags::FrameRounding},
    {"FrameBorderSize", LUI::StyleFlags::FrameBorderSize},
    {"ItemSpacing", LUI::StyleFlags::ItemSpacing},
    {"ItemInnerSpacing", LUI::StyleFlags::ItemInnerSpacing},
    {"IndentSpacing", LUI::StyleFlags::IndentSpacing},
    {"CellPadding", LUI::StyleFlags::CellPadding},
    {"ScrollbarSize", LUI::StyleFlags::ScrollbarSize},
    {"ScrollbarRounding", LUI::StyleFlags::ScrollbarRounding},
    {"GrabMinSize", LUI::StyleFlags::GrabMinSize},
    {"GrabRounding", LUI::StyleFlags::GrabRounding},
    {"TabRounding", LUI::StyleFlags::TabRounding},
    {"TabBorderSize", LUI::StyleFlags::TabBorderSize},
    {"TabBarBorderSize", LUI::StyleFlags::TabBarBorderSize},
    {"TabBarOverlineSize", LUI::StyleFlags::TabBarOverlineSize},
    {"TableAngledHeadersAngle", LUI::StyleFlags::TableAngledHeadersAngle},
    {"TableAngledHeadersTextAlign", LUI::StyleFlags::TableAngledHeadersTextAlign},
    {"ButtonTextAlign", LUI::StyleFlags::ButtonTextAlign},
    {"SelectableTextAlign", LUI::StyleFlags::SelectableTextAlign},
    {"SeparatorTextBorderSize", LUI::StyleFlags::SeparatorTextBorderSize},
    {"SeparatorTextAlign", LUI::StyleFlags::SeparatorTextAlign},
    {"SeparatorTextPadding", LUI::StyleFlags::SeparatorTextPadding},
    {"DockingSeparatorSize", LUI::StyleFlags::DockingSeparatorSize},
};

const std::map<std::string, LUI::ColorFlags> Style::ColorMap = {
    {"Text", LUI::ColorFlags::Text},
    {"TextDisabled", LUI::ColorFlags::TextDisabled},
    {"WindowBg", LUI::ColorFlags::WindowBg},
    {"ChildBg", LUI::ColorFlags::ChildBg},
    {"PopupBg", LUI::ColorFlags::PopupBg},
    {"Border", LUI::ColorFlags::Border},
    {"BorderShadow", LUI::ColorFlags::BorderShadow},
    {"FrameBg", LUI::ColorFlags::FrameBg},
    {"FrameBgHovered", LUI::ColorFlags::FrameBgHovered},
    {"FrameBgActive", LUI::ColorFlags::FrameBgActive},
    {"TitleBg", LUI::ColorFlags::TitleBg},
    {"TitleBgActive", LUI::ColorFlags::TitleBgActive},
    {"TitleBgCollapsed", LUI::ColorFlags::TitleBgCollapsed},
    {"MenuBarBg", LUI::ColorFlags::MenuBarBg},
    {"ScrollbarBg", LUI::ColorFlags::ScrollbarBg},
    {"ScrollbarGrab", LUI::ColorFlags::ScrollbarGrab},
    {"ScrollbarGrabHovered", LUI::ColorFlags::ScrollbarGrabHovered},
    {"ScrollbarGrabActive", LUI::ColorFlags::ScrollbarGrabActive},
    {"CheckMark", LUI::ColorFlags::CheckMark},
    {"SliderGrab", LUI::ColorFlags::SliderGrab},
    {"SliderGrabActive", LUI::ColorFlags::SliderGrabActive},
    {"Button", LUI::ColorFlags::Button},
    {"ButtonHovered", LUI::ColorFlags::ButtonHovered},
    {"ButtonActive", LUI::ColorFlags::ButtonActive},
    {"Header", LUI::ColorFlags::Header},
    {"HeaderHovered", LUI::ColorFlags::HeaderHovered},
    {"HeaderActive", LUI::ColorFlags::HeaderActive},
    {"Separator", LUI::ColorFlags::Separator},
    {"SeparatorHovered", LUI::ColorFlags::SeparatorHovered},
    {"SeparatorActive", LUI::ColorFlags::SeparatorActive},
    {"ResizeGrip", LUI::ColorFlags::ResizeGrip},
    {"ResizeGripHovered", LUI::ColorFlags::ResizeGripHovered},
    {"ResizeGripActive", LUI::ColorFlags::ResizeGripActive},
    {"TabHovered", LUI::ColorFlags::TabHovered},
    {"Tab", LUI::ColorFlags::Tab},
    {"TabSelected", LUI::ColorFlags::TabSelected},
    {"TabSelectedOverline", LUI::ColorFlags::TabSelectedOverline},
    {"TabDimmed", LUI::ColorFlags::TabDimmed},
    {"TabDimmedSelected", LUI::ColorFlags::TabDimmedSelected},
    {"TabDimmedSelectedOverline", LUI::ColorFlags::TabDimmedSelectedOverline},
    {"DockingPreview", LUI::ColorFlags::DockingPreview},
    {"DockingEmptyBg", LUI::ColorFlags::DockingEmptyBg},
    {"PlotLines", LUI::ColorFlags::PlotLines},
    {"PlotLinesHovered", LUI::ColorFlags::PlotLinesHovered},
    {"PlotHistogram", LUI::ColorFlags::PlotHistogram},
    {"PlotHistogramHovered", LUI::ColorFlags::PlotHistogramHovered},
    {"TableHeaderBg", LUI::ColorFlags::TableHeaderBg},
    {"TableBorderStrong", LUI::ColorFlags::TableBorderStrong},
    {"TableBorderLight", LUI::ColorFlags::TableBorderLight},
    {"TableRowBg", LUI::ColorFlags::TableRowBg},
    {"TableRowBgAlt", LUI::ColorFlags::TableRowBgAlt},
    {"TextLink", LUI::ColorFlags::TextLink},
    {"TextSelectedBg", LUI::ColorFlags::TextSelectedBg},
    {"DragDropTarget", LUI::ColorFlags::DragDropTarget},
    {"NavHighlight", LUI::ColorFlags::NavHighlight},
    {"NavWindowingHighlight", LUI::ColorFlags::NavWindowingHighlight},
    {"NavWindowingDimBg", LUI::ColorFlags::NavWindowingDimBg},
    {"ModalWindowDimBg", LUI::ColorFlags::ModalWindowDimBg},
};

Style::Style()
{
    Alpha = 1.0f;
    DisabledAlpha = 0.60f;
    WindowPadding = Vector2(8, 8);
    WindowRounding = 0.0f;
    WindowBorderSize = 1.0f;
    WindowMinSize = Vector2(32, 32);
    WindowTitleAlign = Vector2(0.0f, 0.5f);
    ChildRounding = 0.0f;
    ChildBorderSize = 1.0f;
    PopupRounding = 0.0f;
    PopupBorderSize = 1.0f;
    FramePadding = Vector2(4, 3);
    FrameRounding = 0.0f;
    FrameBorderSize = 0.0f;
    ItemSpacing = Vector2(8, 4);
    ItemInnerSpacing = Vector2(4, 4);
    CellPadding = Vector2(4, 2);
    TouchExtraPadding = Vector2(0, 0);
    IndentSpacing = 21.0f;
    ColumnsMinSpacing = 6.0f;
    ScrollbarSize = 14.0f;
    ScrollbarRounding = 9.0f;
    GrabMinSize = 12.0f;
    GrabRounding = 0.0f;
    LogSliderDeadzone = 4.0f;
    TabRounding = 4.0f;
    TabBorderSize = 0.0f;
    TabMinWidthForCloseButton = 0.0f;
    TabBarBorderSize = 1.0f;
    TabBarOverlineSize = 2.0f;
    TableAngledHeadersAngle = 35.0f * (Math::PI / 180.0f);
    TableAngledHeadersTextAlign = Vector2(0.5f, 0.0f);
    ButtonTextAlign = Vector2(0.5f, 0.5f);
    SelectableTextAlign = Vector2(0.0f, 0.0f);
    SeparatorTextBorderSize = 3.0f;
    SeparatorTextAlign = Vector2(0.0f, 0.5f);
    SeparatorTextPadding = Vector2(20.0f, 3.f);
    DisplayWindowPadding = Vector2(19, 19);
    DisplaySafeAreaPadding = Vector2(3, 3);
    DockingSeparatorSize = 2.0f;
    MouseCursorScale = 1.0f;
    AntiAliasedLines = true;
    AntiAliasedLinesUseTex = true;
    AntiAliasedFill = true;
    CurveTessellationTol = 1.25f;
    CircleTessellationMaxError = 0.30f;

    ImGuiStyle style;
    for (int i = 0; i < ImGuiCol_COUNT; i++)
    {
        ImVec4 color = style.Colors[i];
        Colors[i] = {static_cast<unsigned char>(color.x * 255),
                     static_cast<unsigned char>(color.y * 255),
                     static_cast<unsigned char>(color.z * 255),
                     static_cast<unsigned char>(color.w * 255)};
    }
}

Style::operator ImGuiStyle() const
{
    ImGuiStyle style;

    style.Alpha = Alpha;
    style.DisabledAlpha = DisabledAlpha;
    style.WindowPadding = {WindowPadding.x, WindowPadding.y};
    style.WindowRounding = WindowRounding;
    style.WindowBorderSize = WindowBorderSize;
    style.WindowMinSize = {WindowMinSize.x, WindowMinSize.y};
    style.WindowTitleAlign = {WindowTitleAlign.x, WindowTitleAlign.y};
    style.ChildRounding = ChildRounding;
    style.ChildBorderSize = ChildBorderSize;
    style.PopupRounding = PopupRounding;
    style.PopupBorderSize = PopupBorderSize;
    style.FramePadding = {FramePadding.x, FramePadding.y};
    style.FrameRounding = FrameRounding;
    style.FrameBorderSize = FrameBorderSize;
    style.ItemSpacing = {ItemSpacing.x, ItemSpacing.y};
    style.ItemInnerSpacing = {ItemInnerSpacing.x, ItemInnerSpacing.y};
    style.CellPadding = {CellPadding.x, CellPadding.y};
    style.TouchExtraPadding = {TouchExtraPadding.x, TouchExtraPadding.y};
    style.IndentSpacing = IndentSpacing;
    style.ColumnsMinSpacing = ColumnsMinSpacing;
    style.ScrollbarSize = ScrollbarSize;
    style.ScrollbarRounding = ScrollbarRounding;
    style.GrabMinSize = GrabMinSize;
    style.GrabRounding = GrabRounding;
    style.LogSliderDeadzone = LogSliderDeadzone;
    style.TabRounding = TabRounding;
    style.TabBorderSize = TabBorderSize;
    style.TabMinWidthForCloseButton = TabMinWidthForCloseButton;
    style.TabBarBorderSize = TabBarBorderSize;
    style.TabBarOverlineSize = TabBarOverlineSize;
    style.TableAngledHeadersAngle = TableAngledHeadersAngle;
    style.TableAngledHeadersTextAlign = {TableAngledHeadersTextAlign.x,
                                         TableAngledHeadersTextAlign.y};
    style.ButtonTextAlign = {ButtonTextAlign.x, ButtonTextAlign.y};
    style.SelectableTextAlign = {SelectableTextAlign.x, SelectableTextAlign.y};
    style.SeparatorTextBorderSize = SeparatorTextBorderSize;
    style.SeparatorTextAlign = {SeparatorTextAlign.x, SeparatorTextAlign.y};
    style.SeparatorTextPadding = {SeparatorTextPadding.x, SeparatorTextPadding.y};
    style.DisplayWindowPadding = {DisplayWindowPadding.x, DisplayWindowPadding.y};
    style.DisplaySafeAreaPadding = {DisplaySafeAreaPadding.x, DisplaySafeAreaPadding.y};
    style.DockingSeparatorSize = DockingSeparatorSize;
    style.MouseCursorScale = MouseCursorScale;
    style.AntiAliasedLines = AntiAliasedLines;
    style.AntiAliasedLinesUseTex = AntiAliasedLinesUseTex;
    style.AntiAliasedFill = AntiAliasedFill;
    style.CurveTessellationTol = CurveTessellationTol;
    style.CircleTessellationMaxError = CircleTessellationMaxError;

    for (int i = 0; i < static_cast<int>(LUI::ColorFlags::Count); i++)
    {
        Vector4 color = Colors[i].Normalize();
        style.Colors[i] = {color.x, color.y, color.z, color.w};
    }

    return style;
}

} // namespace Lumen::LUI