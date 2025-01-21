#include "Lumen/UI/Style/Style.hpp"
#include "Lumen/Math/Math.hpp"
#include "Lumen/UI/UIStructures.hpp"

#include "imgui.h"

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

    for (int i = 0; i < static_cast<int>(UI::ColorFlags::Count); i++)
    {
        Vector4 color = Colors[i].Normalize();
        style.Colors[i] = {color.x, color.y, color.z, color.w};
    }

    return style;
}

} // namespace Lumen