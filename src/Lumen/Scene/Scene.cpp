#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

void Scene::OnUpdate()
{
    m_World.Update();
}

} // namespace Lumen