#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

CameraComponent &Scene::GetMainCamera()
{
    return m_World.GetEntityManager().GetComponent<CameraComponent>(m_MainCamera);
}

World &Scene::GetWorld()
{
    return m_World;
}

void Scene::SetMainCamera(Entity camera)
{
    m_MainCamera = camera;
}

SceneState Scene::GetState() const
{
    return m_State;
}

void Scene::SetState(SceneState state)
{
    m_State = state;
}

void Scene::OnUpdate()
{
    m_World.Update();
}

} // namespace Lumen