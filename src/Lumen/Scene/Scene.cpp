#include "Lumen/Scene/Scene.hpp"
#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

Scene::Scene()
{
    EventBus::Subscribe<ComponentRemoveEvent<CameraComponent>>(
        BIND_EVENT(OnComponentRemoved));
}

Scene::Scene(Path path, UUID uuid, std::string name)
    : m_Path(std::move(path)), m_ID(uuid), m_Name(std::move(name)),
      m_State(SceneState::Edit)
{
    EventBus::Subscribe<ComponentRemoveEvent<CameraComponent>>(
        BIND_EVENT(OnComponentRemoved));
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

void Scene::SetID(UUID uuid)
{
    m_ID = uuid;
}

void Scene::SetName(const std::string &name)
{
    m_Name = name;
}

void Scene::SetMainCamera(Entity camera)
{
    m_MainCamera = camera;
}

void Scene::SetPath(const Path &path)
{
    m_Path = path;
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

void Scene::OnComponentRemoved(const ComponentRemoveEvent<CameraComponent> &event)
{
    Entity eventEntity = event.GetEntity();

    if (eventEntity != m_MainCamera)
    {
        return;
    }

    m_MainCamera = {};
    auto view = m_World.GetEntityManager().GetRegistry().view<CameraComponent>();
    for (auto entity : view)
    {
        if (eventEntity != Entity(entity))
        {
            m_MainCamera = eventEntity;
        }
    }
}

} // namespace Lumen