#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Editor/Panel/ConsolePanel.hpp"
#include "Lumen/Editor/Panel/HierarchyPanel.hpp"
#include "Lumen/Editor/Panel/InspectorPanel.hpp"
#include "Lumen/Editor/Panel/ProjectPanel.hpp"
#include "Lumen/Editor/Panel/SceneViewPanel.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class EditorLayer : public Layer
{
public:
    EditorLayer(std::string name = "Editor Layer", bool visible = true);
    ~EditorLayer() override = default;

    void OnUpdate() override;
    void OnDraw() override;

    void DrawUIToolbar();

private:
    Ref<Scene> m_ActiveScene;

    HierarchyPanel m_HierarchyPanel;
    InspectorPanel m_InspectorPanel;
    SceneViewPanel m_SceneViewPanel;
    ProjectPanel m_ProjectPanel;
    ConsolePanel m_ConsolePanel;
};

} // namespace Lumen