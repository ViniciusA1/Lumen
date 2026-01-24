#include "Lumen/UI/Module/LUIContext.hpp"
#include "Lumen/UI/Module/LUIFont.hpp"
#include "Lumen/UI/Module/LUIStyle.hpp"

#include "imgui.h"

#include "ImGuizmo.h"
#include "rlImGui.h"

namespace Lumen::LUI
{

static bool s_IsInitialized = false;
static std::vector<Function<void()>> s_OverlayList;

void Init()
{
    if (s_IsInitialized)
        return;

    rlImGuiSetup(true);
    InitFont();
    s_IsInitialized = true;
}

void Shutdown()
{
    if (!s_IsInitialized)
        return;

    rlImGuiShutdown();
}

void BeginUI()
{
    rlImGuiBegin();
    ImGuizmo::BeginFrame();
}

void EndUI()
{
    for (const auto &overlay : s_OverlayList)
        overlay();

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