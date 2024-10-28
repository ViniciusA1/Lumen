#include "Lumen/UI/UI.hpp"
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
}

void UI::End()
{
    rlImGuiEnd();
}

} // namespace Lumen