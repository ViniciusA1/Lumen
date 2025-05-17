#include "Lumen/UI/LUIDockPanel.hpp"

#include "Lumen/UI/LUI.hpp"
#include "imgui.h"
#include "imgui_internal.h"

namespace Lumen
{

LUIDockPanel::LUIDockPanel(std::string label, LUI::WindowFlags flags, bool isOpen)
    : m_Label(std::move(label)), m_Flags(flags), m_IsOpen(isOpen)
{
}

bool LUIDockPanel::IsOpen() const
{
    return m_IsOpen;
}

void LUIDockPanel::Close()
{
    m_IsOpen = false;
}

void LUIDockPanel::Open()
{
    m_IsOpen = true;
}

void LUIDockPanel::Draw()
{
    ImGuiWindowClass windowClass;
    windowClass.DockNodeFlagsOverrideSet =
        ImGuiDockNodeFlags_NoWindowMenuButton | ImGuiDockNodeFlags_NoCloseButton;

    ImGui::SetNextWindowClass(&windowClass);

    if (!m_IsOpen)
        return;

    if (LUI::Begin(m_Label, &m_IsOpen, m_Flags))
        OnDraw();

    LUI::End();
}

} // namespace Lumen