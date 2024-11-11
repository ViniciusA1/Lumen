#include "Lumen/UI/ImGuiLayer.hpp"

namespace Lumen
{

ImGuiLayer::ImGuiLayer(std::string name, bool isVisible)
    : Layer(std::move(name), isVisible)
{
}

void ImGuiLayer::PushOverlay(const std::function<void()> &overlay)
{
    m_OverlayList.push_back(overlay);
}

void ImGuiLayer::PopOverlay()
{
    m_OverlayList.pop_back();
}

void ImGuiLayer::DrawOverlay()
{
    for (const auto &overlay : m_OverlayList)
    {
        overlay();
    }
}

} // namespace Lumen