#pragma once

#include "Lumen/Core/Layer.hpp"
#include <functional>
#include <vector>

namespace Lumen
{

class ImGuiLayer : public Layer
{
public:
    ImGuiLayer(std::string = "ImGuiLayer", bool isVisible = true);

    void PushOverlay(const std::function<void()> &overlay);
    void PopOverlay();
    void DrawOverlay();

private:
    std::vector<std::function<void()>> m_OverlayList;
};

} // namespace Lumen