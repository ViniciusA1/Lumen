#pragma once

#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class InspectorPanel
{
public:
    InspectorPanel() = default;

    void Draw(Scene &activeScene, Entity selectedEntity);

private:
    void DrawComponents(EntityManager &manager, Entity entity);
};

} // namespace Lumen