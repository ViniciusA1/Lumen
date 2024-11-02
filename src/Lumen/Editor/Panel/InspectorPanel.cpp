#include "Lumen/Editor/Panel/InspectorPanel.hpp"
#include "imgui.h"

namespace Lumen
{

void InspectorPanel::Draw(Scene &activeScene, Entity selectedEntity)
{
    ImGui::Begin("Inspector");

    if (selectedEntity)
    {
        DrawComponents(activeScene.GetWorld().GetEntityManager(), selectedEntity);
    }
    else
    {
        ImGui::Text("No entity selected");
    }

    ImGui::End();
}

void InspectorPanel::DrawComponents(EntityManager &manager, Entity entity)
{
    if (manager.HasComponent<TransformComponent>(entity))
    {
        if (ImGui::CollapsingHeader("Transform"))
        {
            auto &transform = manager.GetComponent<TransformComponent>(entity);
            ImGui::DragFloat3("Position", &transform.Position.x, 0.1f);
            ImGui::DragFloat3("Rotation", &transform.Rotation.x, 0.1f);
            ImGui::DragFloat3("Scale", &transform.Scale.x, 0.1f);
        }
    }

    // Additional components...

    if (manager.HasComponent<VelocityComponent>(entity))
    {
        if (ImGui::CollapsingHeader("Velocity"))
        {
            auto &velocity = manager.GetComponent<VelocityComponent>(entity);
            ImGui::DragFloat3("Velocity", &velocity.Velocity.x, 0.1f);
        }
    }
}
} // namespace Lumen