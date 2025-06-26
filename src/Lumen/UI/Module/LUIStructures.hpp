#pragma once

#include "Lumen/Core/Enum.hpp"

namespace Lumen::LUI
{

enum class ChildFlags
{
    None = 0,
    Borders = 1 << 0,
    AlwaysUseWindowPadding = 1 << 1,
    ResizeX = 1 << 2,
    ResizeY = 1 << 3,
    AutoResizeX = 1 << 4,
    AutoResizeY = 1 << 5,
    AlwaysAutoResize = 1 << 6,
    FrameStyle = 1 << 7,
    NavFlattened = 1 << 8
};

ENUM_ENABLE_BITMASK(ChildFlags)

enum class ColorEditFlags
{
    None = 0,
    NoAlpha = 1 << 1,
    NoPicker = 1 << 2,
    NoOptions = 1 << 3,
    NoSmallPreview = 1 << 4,
    NoInputs = 1 << 5,
    NoTooltip = 1 << 6,
    NoLabel = 1 << 7,
    NoSidePreview = 1 << 8,
    NoDragDrop = 1 << 9,
    NoBorder = 1 << 10,
    AlphaBar = 1 << 16,
    AlphaPreview = 1 << 17,
    AlphaPreviewHalf = 1 << 18,
    HDR = 1 << 19,
    DisplayRGB = 1 << 20,
    DisplayHSV = 1 << 21,
    DisplayHex = 1 << 22,
    Uint8 = 1 << 23,
    Float = 1 << 24,
    PickerHueBar = 1 << 25,
    PickerHueWheel = 1 << 26,
    InputRGB = 1 << 27,
    InputHSV = 1 << 28,
    DefaultOptions_ = Uint8 | DisplayRGB | InputRGB | PickerHueBar,
};

ENUM_ENABLE_BITMASK(ColorEditFlags)

enum class ColorFlags
{
    Text,
    TextDisabled,
    WindowBg,
    ChildBg,
    PopupBg,
    Border,
    BorderShadow,
    FrameBg,
    FrameBgHovered,
    FrameBgActive,
    TitleBg,
    TitleBgActive,
    TitleBgCollapsed,
    MenuBarBg,
    ScrollbarBg,
    ScrollbarGrab,
    ScrollbarGrabHovered,
    ScrollbarGrabActive,
    CheckMark,
    SliderGrab,
    SliderGrabActive,
    Button,
    ButtonHovered,
    ButtonActive,
    Header,
    HeaderHovered,
    HeaderActive,
    Separator,
    SeparatorHovered,
    SeparatorActive,
    ResizeGrip,
    ResizeGripHovered,
    ResizeGripActive,
    TabHovered,
    Tab,
    TabSelected,
    TabSelectedOverline,
    TabDimmed,
    TabDimmedSelected,
    TabDimmedSelectedOverline,
    DockingPreview,
    DockingEmptyBg,
    PlotLines,
    PlotLinesHovered,
    PlotHistogram,
    PlotHistogramHovered,
    TableHeaderBg,
    TableBorderStrong,
    TableBorderLight,
    TableRowBg,
    TableRowBgAlt,
    TextLink,
    TextSelectedBg,
    DragDropTarget,
    NavHighlight,
    NavWindowingHighlight,
    NavWindowingDimBg,
    ModalWindowDimBg,
    Count
};

ENUM_ENABLE_BITMASK(ColorFlags)

enum class CondFlags
{
    None = 0,
    Always = 1 << 0,
    Once = 1 << 1,
    FirstUseEver = 1 << 2,
    Appearing = 1 << 3
};

ENUM_ENABLE_BITMASK(CondFlags)

enum class ConfigFlags
{
    None = 0,
    NavEnableKeyboard = 1 << 0,
    NavEnableGamepad = 1 << 1,
    NavEnableSetMousePos = 1 << 2,
    NavNoCaptureKeyboard = 1 << 3,
    NoMouse = 1 << 4,
    NoMouseCursorChange = 1 << 5,
    NoKeyboard = 1 << 6,
    DockingEnable = 1 << 7,
    ViewportsEnable = 1 << 10,
    DpiEnableScaleViewports = 1 << 14,
    DpiEnableScaleFonts = 1 << 15,
    IsSRGB = 1 << 20,
    IsTouchScreen = 1 << 21
};

ENUM_ENABLE_BITMASK(ConfigFlags)

enum class DockNodeFlags
{
    None = 0,
    KeepAliveOnly = 1 << 0,
    // NoCentralNode              = 1 << 1,
    NoDockingOverCentralNode = 1 << 2,
    PassthruCentralNode = 1 << 3,
    NoDockingSplit = 1 << 4,
    NoResize = 1 << 5,
    AutoHideTabBar = 1 << 6,
    NoUndocking = 1 << 7,
};

ENUM_ENABLE_BITMASK(DockNodeFlags)

enum class DragDropFlags
{
    None = 0,
    SourceNoPreviewTooltip = 1 << 0,
    SourceNoDisableHover = 1 << 1,
    SourceNoHoldToOpenOthers = 1 << 2,
    SourceAllowNullID = 1 << 3,
    SourceExtern = 1 << 4,
    PayloadAutoExpire = 1 << 5,
    PayloadNoCrossContext = 1 << 6,
    PayloadNoCrossProcess = 1 << 7,

    AcceptBeforeDelivery = 1 << 10,
    AcceptNoDrawDefaultRect = 1 << 11,
    AcceptNoPreviewTooltip = 1 << 12,
    AcceptPeekOnly = AcceptBeforeDelivery | AcceptNoDrawDefaultRect,
};

ENUM_ENABLE_BITMASK(DragDropFlags)

enum class PopupFlags
{
    None = 0,
    MouseButtonLeft = 0,
    MouseButtonRight = 1,
    MouseButtonMiddle = 2,
    NoReopen = 1 << 5,
    NoOpenOverExistingPopup = 1 << 7,
    NoOpenOverItems = 1 << 8,
    AnyPopupId = 1 << 10,
    AnyPopupLevel = 1 << 11,
    AnyPopup = AnyPopupId | AnyPopupLevel
};

ENUM_ENABLE_BITMASK(PopupFlags)

enum class SelectableFlags
{
    None = 0,
    NoAutoClosePopups = 1 << 0,
    SpanAllColumns = 1 << 1,
    AllowDoubleClick = 1 << 2,
    Disabled = 1 << 3,
    AllowOverlap = 1 << 4,
    Highlight = 1 << 5
};

ENUM_ENABLE_BITMASK(SelectableFlags)

enum class SliderFlags
{
    None = 0,
    Logarithmic = 1 << 5,
    NoRoundToFormat = 1 << 6,
    NoInput = 1 << 7,
    WrapAround = 1 << 8,
    ClampOnInput = 1 << 9,
    ClampZeroRange = 1 << 10,
    AlwaysClamp = ClampOnInput | ClampZeroRange,
    InvalidMask = 0x7000000F
};

ENUM_ENABLE_BITMASK(SliderFlags)

enum class StyleFlags
{
    Alpha,
    DisabledAlpha,
    WindowPadding,
    WindowRounding,
    WindowBorderSize,
    WindowMinSize,
    WindowTitleAlign,
    ChildRounding,
    ChildBorderSize,
    PopupRounding,
    PopupBorderSize,
    FramePadding,
    FrameRounding,
    FrameBorderSize,
    ItemSpacing,
    ItemInnerSpacing,
    IndentSpacing,
    CellPadding,
    ScrollbarSize,
    ScrollbarRounding,
    GrabMinSize,
    GrabRounding,
    TabRounding,
    TabBorderSize,
    TabBarBorderSize,
    TabBarOverlineSize,
    TableAngledHeadersAngle,
    TableAngledHeadersTextAlign,
    ButtonTextAlign,
    SelectableTextAlign,
    SeparatorTextBorderSize,
    SeparatorTextAlign,
    SeparatorTextPadding,
    DockingSeparatorSize,
    COUNT
};

ENUM_ENABLE_BITMASK(StyleFlags)

enum class TableFlags
{
    None = 0,
    Resizable = 1 << 0,
    Reorderable = 1 << 1,
    Hideable = 1 << 2,
    Sortable = 1 << 3,
    NoSavedSettings = 1 << 4,
    ContextMenuInBody = 1 << 5,
    RowBg = 1 << 6,
    BordersInnerH = 1 << 7,
    BordersOuterH = 1 << 8,
    BordersInnerV = 1 << 9,
    BordersOuterV = 1 << 10,
    BordersH = BordersInnerH | BordersOuterH,
    BordersV = BordersInnerV | BordersOuterV,
    BordersInner = BordersInnerV | BordersInnerH,
    BordersOuter = BordersOuterV | BordersOuterH,
    Borders = BordersInner | BordersOuter,
    NoBordersInBody = 1 << 11,
    NoBordersInBodyUntilResize = 1 << 12,
    SizingFixedFit = 1 << 13,
    SizingFixedSame = 2 << 13,
    SizingStretchProp = 3 << 13,
    SizingStretchSame = 4 << 13,
    NoHostExtendX = 1 << 16,
    NoHostExtendY = 1 << 17,
    NoKeepColumnsVisible = 1 << 18,
    PreciseWidths = 1 << 19,
    NoClip = 1 << 20,
    PadOuterX = 1 << 21,
    NoPadOuterX = 1 << 22,
    NoPadInnerX = 1 << 23,
    ScrollX = 1 << 24,
    ScrollY = 1 << 25,
    SortMulti = 1 << 26,
    SortTristate = 1 << 27,
    HighlightHoveredColumn = 1 << 28
};

ENUM_ENABLE_BITMASK(TableFlags)

enum class TableColumnFlags
{
    None = 0,
    Disabled = 1 << 0,
    DefaultHide = 1 << 1,
    DefaultSort = 1 << 2,
    WidthStretch = 1 << 3,
    WidthFixed = 1 << 4,
    NoResize = 1 << 5,
    NoReorder = 1 << 6,
    NoHide = 1 << 7,
    NoClip = 1 << 8,
    NoSort = 1 << 9,
    NoSortAscending = 1 << 10,
    NoSortDescending = 1 << 11,
    NoHeaderLabel = 1 << 12,
    NoHeaderWidth = 1 << 13,
    PreferSortAscending = 1 << 14,
    PreferSortDescending = 1 << 15,
    IndentEnable = 1 << 16,
    IndentDisable = 1 << 17,
    AngledHeader = 1 << 18,
    IsEnabled = 1 << 24,
    IsVisible = 1 << 25,
    IsSorted = 1 << 26,
    IsHovered = 1 << 27
};

ENUM_ENABLE_BITMASK(TableColumnFlags)

enum class TableRowFlags
{
    None = 0,
    Headers = 1 << 0
};

ENUM_ENABLE_BITMASK(TableRowFlags)

enum class TreeNodeFlags
{
    None = 0,
    Selected = 1 << 0,
    Framed = 1 << 1,
    AllowOverlap = 1 << 2,
    NoTreePushOnOpen = 1 << 3,
    NoAutoOpenOnLog = 1 << 4,
    DefaultOpen = 1 << 5,
    OpenOnDoubleClick = 1 << 6,
    OpenOnArrow = 1 << 7,
    Leaf = 1 << 8,
    Bullet = 1 << 9,
    FramePadding = 1 << 10,
    SpanAvailWidth = 1 << 11,
    SpanFullWidth = 1 << 12,
    SpanTextWidth = 1 << 13,
    SpanAllColumns = 1 << 14,
    NavLeftJumpsBackHere = 1 << 15,
    CollapsingHeader = Framed | NoTreePushOnOpen | NoAutoOpenOnLog
};

ENUM_ENABLE_BITMASK(TreeNodeFlags)

enum class WindowFlags
{
    None = 0,
    NoTitleBar = 1 << 0,
    NoResize = 1 << 1,
    NoMove = 1 << 2,
    NoScrollbar = 1 << 3,

    NoScrollWithMouse = 1 << 4,
    NoCollapse = 1 << 5,
    AlwaysAutoResize = 1 << 6,
    NoBackground = 1 << 7,
    NoSavedSettings = 1 << 8,
    NoMouseInputs = 1 << 9,
    MenuBar = 1 << 10,
    HorizontalScrollbar = 1 << 11,
    NoFocusOnAppearing = 1 << 12,
    NoBringToFrontOnFocus = 1 << 13,
    AlwaysVerticalScrollbar = 1 << 14,
    AlwaysHorizontalScrollbar = 1 << 15,
    NoNavInputs = 1 << 16,
    NoNavFocus = 1 << 17,
    UnsavedDocument = 1 << 18,
    NoDocking = 1 << 19,
    NoNav = NoNavInputs | NoNavFocus,
    NoDecoration = NoTitleBar | NoResize | NoScrollbar | NoCollapse,
    NoInputs = NoMouseInputs | NoNavInputs | NoNavFocus
};

ENUM_ENABLE_BITMASK(WindowFlags)

} // namespace Lumen::LUI