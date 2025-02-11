#include "Lumen/Scene/Scene2D.hpp"

namespace Lumen
{

Scene2D::Scene2D() : Scene(SceneType::Type2D)
{
}

Scene2D::Scene2D(UUID uuid, std::string name, Path path)
    : Scene(uuid, std::move(name), std::move(path), SceneType::Type2D)
{
}

const World2D &Scene2D::GetPhysicsWorld() const
{
    return m_PhysicsWorld;
}

World2D &Scene2D::GetPhysicsWorld()
{
    return m_PhysicsWorld;
}

void Scene2D::OnUpdate()
{
    if (m_State != SceneState::Play)
    {
        return;
    }

    m_World.Update();
    m_PhysicsWorld.Update(1.0f / 60.0f, 4);
}

} // namespace Lumen