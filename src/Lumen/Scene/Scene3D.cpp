#include "Lumen/Scene/Scene3D.hpp"

namespace Lumen
{

Scene3D::Scene3D() : Scene()
{
}

Scene3D::Scene3D(UUID uuid, std::string name, Path path)
    : Scene(uuid, std::move(name), std::move(path), SceneType::Type3D)
{
}

void Scene3D::OnUpdate()
{
    if (m_State != SceneState::Play)
    {
        return;
    }

    m_World.Update();
}

} // namespace Lumen