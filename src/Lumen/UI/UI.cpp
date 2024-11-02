#include "Lumen/UI/UI.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "rlImGui.h"

namespace Lumen
{

void UI::Init()
{
    rlImGuiSetup(true);
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

} // namespace Lumen