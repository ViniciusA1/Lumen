#pragma once

#include "Lumen/Scene/Entity/Entity.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class HierarchyPanel
{
public:
    HierarchyPanel() = default;

    [[nodiscard]] Entity GetSelectedEntity() const { return m_SelectedEntity; }

    void Draw(Scene &activeScene);

private:
    void DrawEntityNode(EntityManager &manager, Entity &entity);

private:
    Entity m_SelectedEntity;
};

} // namespace Lumen