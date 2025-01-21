#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/UIStructures.hpp"

#include <map>
#include <string>

struct ImGuiStyle;

namespace Lumen
{

class Style
{
public:
    static const std::map<std::string, UI::StyleFlags> StyleMap;
    static const std::map<std::string, UI::ColorFlags> ColorMap;

public:
    std::string Name;

    float Alpha;
    float DisabledAlpha;
    Vector2 WindowPadding;
    float WindowRounding;
    float WindowBorderSize;
    Vector2 WindowMinSize;
    Vector2 WindowTitleAlign;
    float ChildRounding;
    float ChildBorderSize;
    float PopupRounding;
    float PopupBorderSize;
    Vector2 FramePadding;
    float FrameRounding;
    float FrameBorderSize;
    Vector2 ItemSpacing;
    Vector2 ItemInnerSpacing;
    Vector2 CellPadding;
    Vector2 TouchExtraPadding;
    float IndentSpacing;
    float ColumnsMinSpacing;
    float ScrollbarSize;
    float ScrollbarRounding;
    float GrabMinSize;
    float GrabRounding;
    float LogSliderDeadzone;
    float TabRounding;
    float TabBorderSize;
    float TabMinWidthForCloseButton;
    float TabBarBorderSize;
    float TabBarOverlineSize;
    float TableAngledHeadersAngle;
    Vector2 TableAngledHeadersTextAlign;
    Vector2 ButtonTextAlign;
    Vector2 SelectableTextAlign;
    float SeparatorTextBorderSize;
    Vector2 SeparatorTextAlign;
    Vector2 SeparatorTextPadding;
    Vector2 DisplayWindowPadding;
    Vector2 DisplaySafeAreaPadding;
    float DockingSeparatorSize;
    float MouseCursorScale;
    bool AntiAliasedLines;
    bool AntiAliasedLinesUseTex;
    bool AntiAliasedFill;
    float CurveTessellationTol;
    float CircleTessellationMaxError;
    Color Colors[static_cast<int>(UI::ColorFlags::Count)];

public:
    Style();

    operator ImGuiStyle() const;
};

} // namespace Lumen