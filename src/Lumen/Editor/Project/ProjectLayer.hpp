#pragma once

#include "Lumen/Editor/Project/ProjectListPanel.hpp"
#include "Lumen/Editor/Project/ProjectTopBarPanel.hpp"
#include "Lumen/UI/ImGuiLayer.hpp"

namespace Lumen
{

class ProjectLayer : public ImGuiLayer
{
public:
    ProjectLayer(std::string name = "Project Layer", bool visible = true);
    ~ProjectLayer() override = default;

    void OnDraw() override;

private:
    std::string DrawFileDialog();

private:
    ProjectListPanel m_ProjectListPanel;
    ProjectTopBarPanel m_TopBarPanel;
};

} // namespace Lumen