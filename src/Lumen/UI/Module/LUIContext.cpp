#include "Lumen/UI/Module/LUIContext.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/UI/Module/LUIFont.hpp"
#include "Lumen/UI/Module/LUIStyle.hpp"

#include "imgui.h"

#include "ImGuizmo.h"
#include "rlImGui.h"

namespace Lumen::LUI
{

static std::vector<Function<void()>> s_OverlayList;

void Init()
{
    rlImGuiSetup(true);
    InitFont();
    InitStyle();
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
    for (const auto &overlay : s_OverlayList)
    {
        overlay();
    }

    Lumen::Renderer::EndTextureMode();
    rlImGuiEnd();
}

void SetConfigFlags(ConfigFlags flags)
{
    ImGui::GetIO().ConfigFlags |= static_cast<int>(flags);
}

void PushOverlay(const Function<void()> &overlay)
{
    s_OverlayList.push_back(overlay);
}

void PopOverlay()
{
    s_OverlayList.pop_back();
}

} // namespace Lumen::LUI