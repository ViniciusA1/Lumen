#include "Lumen/UI/UI.hpp"
#include "ImGuizmo.h"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/UI/Style/StyleSerializer.hpp"
#include "imgui.h"
#include "rlImGui.h"

namespace ImGui
{

static Lumen::Style s_Style;

void Init()
{
    rlImGuiSetup(true);
    Lumen::StyleSerializer serializer;
    if (serializer.Deserialize({"assets/UI/Style/Dark.json"}, s_Style))
    {
        SetStyle(s_Style);
    }
}

void Shutdown()
{
    rlImGuiShutdown();
}

void BeginUI()
{
    rlImGuiBegin();
    ImGuizmo::BeginFrame();
    Lumen::Renderer::BeginTextureMode();
}

void EndUI()
{
    Lumen::Renderer::EndTextureMode();
    rlImGuiEnd();
}

void SetStyle(const Lumen::Style &style)
{
    ImGui::GetStyle() = style.GetImGuiStyle();
    s_Style = style;
}

void SearchBar(char *buffer, std::size_t size)
{
    ImGui::InputTextWithHint("##Search", ICON_FA_MAGNIFYING_GLASS " Search...", buffer,
                             size);
}

} // namespace ImGui