#include "Lumen/Editor/EditorLayer.hpp"
#include "imgui.h"

namespace Lumen
{

EditorLayer::EditorLayer(std::string name, bool visible) : Layer(std::move(name), visible)
{
}

void EditorLayer::OnUpdate()
{
}

void EditorLayer::OnDraw()
{
    ImGui::ShowDemoWindow();
}

} // namespace Lumen