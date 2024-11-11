#include "Lumen/Editor/EditorLayer.hpp"
#include "Lumen/Scene/Entity/System/MovementSystem.hpp"
#include "Lumen/Scene/Entity/System/SpriteRendererSystem.hpp"
#include "Lumen/Scene/SceneManager.hpp"
#include "imgui.h"

namespace Lumen
{

EditorLayer::EditorLayer(std::string name, bool visible)
    : Layer(std::move(name), visible), m_ProjectPanel({std::filesystem::path{"."}})
{
    m_ActiveScene = SceneManager::CreateScene("Scene");
    World &world = m_ActiveScene->GetWorld();
    world.AddSystem<MovementSystem>();
    world.AddSystem<SpriteRendererSystem>();
    EntityManager &entityManager = world.GetEntityManager();
    Entity entity = entityManager.CreateEntity();
    entityManager.AddComponent<SpriteRendererComponent>(entity);
    entityManager.AddComponent<VelocityComponent>(
        entity, VelocityComponent({15.0f, 15.0f, 0.0f}));
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void EditorLayer::OnUpdate()
{
    m_ActiveScene->OnUpdate();
}

void EditorLayer::OnDraw()
{
    DrawUIToolbar();
    ImGui::DockSpaceOverViewport();
    m_HierarchyPanel.Draw(*m_ActiveScene);
    m_SceneViewPanel.Draw(*m_ActiveScene);
    m_InspectorPanel.Draw(*m_ActiveScene, m_HierarchyPanel.GetSelectedEntity());
    m_ProjectPanel.Draw();
    m_ConsolePanel.Draw();
}

void EditorLayer::DrawUIToolbar()
{
    if (ImGui::BeginMainMenuBar())
    {
        // File menu
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New"))
            { /* Handle New action */
            }
            if (ImGui::MenuItem("Open...", "Ctrl+O"))
            { /* Handle Open action */
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))
            { /* Handle Save action */
            }
            if (ImGui::MenuItem("Save As.."))
            { /* Handle Save As action */
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Exit"))
            { /* Handle Exit action */
            }
            ImGui::EndMenu();
        }

        // Edit menu
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "Ctrl+Z"))
            { /* Handle Undo action */
            }
            if (ImGui::MenuItem("Redo", "Ctrl+Y"))
            { /* Handle Redo action */
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "Ctrl+X"))
            { /* Handle Cut action */
            }
            if (ImGui::MenuItem("Copy", "Ctrl+C"))
            { /* Handle Copy action */
            }
            if (ImGui::MenuItem("Paste", "Ctrl+V"))
            { /* Handle Paste action */
            }
            ImGui::EndMenu();
        }

        // View menu
        if (ImGui::BeginMenu("View"))
        {
            if (ImGui::MenuItem("Scene"))
            { /* Handle Scene View toggle */
            }
            if (ImGui::MenuItem("Game"))
            { /* Handle Game View toggle */
            }
            if (ImGui::MenuItem("Inspector"))
            { /* Handle Inspector toggle */
            }
            ImGui::EndMenu();
        }

        // Any other menus like Window, Help, etc., can go here

        ImGui::EndMainMenuBar(); // End the main menu bar
    }
}

} // namespace Lumen