#include "Lumen/UI/UI.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/UI/Style/StyleSerializer.hpp"
#include "imgui.h"
#include "rlImGui.h"

namespace Lumen
{

Style UI::m_Style;

void UI::Init()
{
    rlImGuiSetup(true);
    StyleSerializer serializer;
    if (serializer.Deserialize({"assets/UI/Style/Dark.json"}, m_Style))
    {
        SetStyle(m_Style);
    }
}

void UI::Shutdown()
{
    rlImGuiShutdown();
}

void UI::Begin()
{
    rlImGuiBegin();
    Renderer::BeginRenderTexture();
}

void UI::End()
{
    Renderer::EndRenderTexture();
    rlImGuiEnd();
}

void UI::SetStyle(const Style &style)
{
    ImGui::GetStyle() = style.GetImGuiStyle();
    m_Style = style;
}

} // namespace Lumen