#include "Lumen/UI/Module/LUIFont.hpp"

#include "extras/FA6FreeSolidFontData.h"
#include "imgui.h"
#include "rlImGui.h"

#include <array>
#include <limits>
#include <unordered_map>

namespace Lumen::LUI
{

static std::unordered_map<float, ImFont *> s_FontMap;

void InitFont()
{
    ImGuiIO &io = ImGui::GetIO();
    io.Fonts->Clear();

    constexpr float baseSize = 17.0f;

    constexpr std::array<FontScale, 6> scales = {
        FontScale::x100, FontScale::x125, FontScale::x150,
        FontScale::x175, FontScale::x200, FontScale::x500,
    };

    ImFont *defaultFont = nullptr;

    for (FontScale scale : scales)
    {
        float scaleFactor = GetFontScaleFactor(scale);
        float scaledSize = baseSize * scaleFactor;
        ImFont *font = io.Fonts->AddFontFromFileTTF("assets/UI/Font/OpenSans-Regular.ttf",
                                                    scaledSize);
        s_FontMap[scaleFactor] = font;

        InitIconFont(scaledSize);

        if (scale == FontScale::x100)
            defaultFont = font;
    }

    rlImGuiReloadFonts();
    io.FontDefault = defaultFont;
}

void InitIconFont(float size)
{
    static const std::array<ImWchar, 3> icons_ranges{ICON_MIN_FA, ICON_MAX_FA, 0};
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.FontDataOwnedByAtlas = false;

    icons_config.GlyphMinAdvanceX = size;
    icons_config.GlyphMaxAdvanceX = std::numeric_limits<float>::max();
    icons_config.RasterizerMultiply = 1.0f;
    icons_config.OversampleH = 2;
    icons_config.OversampleV = 1;
    icons_config.GlyphOffset.y -= 1;

    icons_config.GlyphRanges = icons_ranges.data();

    ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(
        (void *)fa_solid_900_compressed_data, fa_solid_900_compressed_size,
        size * 2.0f / 3.0f, &icons_config, icons_ranges.data());
}

float GetFontScaleFactor(FontScale scale)
{
    switch (scale)
    {
    case FontScale::x100:
        return 1.0f;
    case FontScale::x125:
        return 1.25f;
    case FontScale::x150:
        return 1.5f;
    case FontScale::x175:
        return 1.75f;
    case FontScale::x200:
        return 2.0f;
    case FontScale::x500:
        return 5.0f;
    default:
        return 1.0f;
    }
}

void PushFont(FontScale scale)
{
    auto it = s_FontMap.find(GetFontScaleFactor(scale));
    if (it != s_FontMap.end())
        ImGui::PushFont(it->second);
}

void PopFont()
{
    ImGui::PopFont();
}

} // namespace Lumen::LUI