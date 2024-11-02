#include "Lumen/Editor/Panel/SceneViewPanel.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "imgui.h"
#include "raylib.h"

namespace Lumen
{

void SceneViewPanel::Draw(Scene &activeScene)
{

    ImGui::Begin("Scene View");

    ImVec2 windowSize = ImGui::GetContentRegionAvail();
    RenderTexture &renderTexture = Renderer::GetRenderTexture();
    if (windowSize.x > 0 && windowSize.y > 0)
    {
        ImGui::Image(&Renderer::GetRenderTexture().texture, windowSize, ImVec2(0, 1),
                     ImVec2(1, 0));
    }

    ImGui::End();
}

} // namespace Lumen