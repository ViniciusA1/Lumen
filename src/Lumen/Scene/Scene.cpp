#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

Scene::Scene(Path path, UUID uuid, std::string name)
    : m_Path(std::move(path)), m_ID(uuid), m_Name(std::move(name)),
      m_State(SceneState::Edit)
{
}

UUID Scene::GetID() const
{
    return m_ID;
}

CameraComponent &Scene::GetMainCamera()
{
    return m_World.GetEntityManager().GetComponent<CameraComponent>(m_MainCamera);
}

Entity Scene::GetMainCameraEntity() const
{
    return m_MainCamera;
}

std::string Scene::GetName() const
{
    return m_Name;
}

Path Scene::GetPath() const
{
    return m_Path;
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