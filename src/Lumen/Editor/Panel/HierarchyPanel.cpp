#include "Lumen/Editor/Panel/HierarchyPanel.hpp"
#include "imgui.h"

namespace Lumen
{

void HierarchyPanel::Draw(Scene &activeScene)
{
    ImGui::Begin("Hierarchy Panel");

    EntityManager &manager = activeScene.GetWorld().GetEntityManager();

    for (auto &[uuid, entity] : manager.GetEntityMap())
    {
        DrawEntityNode(manager, entity);
    }

    if (ImGui::BeginPopupContextWindow("HierarchyContextMenu"))
    {
        if (ImGui::MenuItem("Create Empty Entity"))
        {
            manager.CreateEntity();
        }
        if (m_SelectedEntity && ImGui::MenuItem("Delete Entity"))
        {
            manager.DestroyEntity(m_SelectedEntity);
            m_SelectedEntity = {};
        }
        ImGui::EndPopup();
    }

    ImGui::End();
}

void HierarchyPanel::DrawEntityNode(EntityManager &manager, Entity &entity)
{
    std::string entityName = manager.GetComponent<TagComponent>(entity).Tag;

    ImGuiTreeNodeFlags flags =
        (m_SelectedEntity == entity) ? ImGuiTreeNodeFlags_Selected : 0;
    flags |= ImGuiTreeNodeFlags_OpenOnArrow;

    bool opened = ImGui::TreeNodeEx(&entity, flags, "%s", entityName.c_str());
    if (ImGui::IsItemClicked())
    {
        m_SelectedEntity = entity;
    }

    if (opened)
    {
        ImGui::TreePop();
    }
}

} // namespace Lumen