#include "Lumen/UI/UI.hpp"
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
    Lumen::Renderer::BeginRenderTexture();
}

void EndUI()
{
    Lumen::Renderer::EndRenderTexture();
    rlImGuiEnd();
}

void SetStyle(const Lumen::Style &style)
{
    ImGui::GetStyle() = style.GetImGuiStyle();
    s_Style = style;
}

} // namespace ImGui