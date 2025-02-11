#include "Lumen/Scene/Scene.hpp"
#include "Entity/Component/Core/TagComponent.hpp"
#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

template <>
void Scene::OnComponentAdded(const ComponentAddEvent<UntaggedComponent> &event);
template <>
void Scene::OnComponentAdded(const ComponentAddEvent<EnemyTagComponent> &event);
template <>
void Scene::OnComponentAdded(const ComponentAddEvent<MainCameraTagComponent> &event);
template <>
void Scene::OnComponentAdded(const ComponentAddEvent<PlayerTagComponent> &event);

template <>
void Scene::OnComponentRemoved(const ComponentRemoveEvent<CameraComponent> &event);

Scene::Scene(SceneType type) : m_Type(type)
{
    BindEvents();
}

Scene::Scene(UUID uuid, std::string name, Path path, SceneType type)
    : m_ID(uuid), m_Path(std::move(path)), m_Name(std::move(name)),
      m_State(SceneState::Edit), m_Type(type)
{
    BindEvents();
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

SceneType Scene::GetType() const
{
    return m_Type;
}

void Scene::SetState(SceneState state)
{
    m_State = state;
}

void Scene::BindEvents()
{
    BindComponentEvent<UntaggedComponent>();
    BindComponentEvent<EnemyTagComponent>();
    BindComponentEvent<MainCameraTagComponent>();
    BindComponentEvent<PlayerTagComponent>();
    BindComponentEvent<CameraComponent>();
}

template <typename T> void Scene::BindComponentEvent()
{
    EventBus::Subscribe<ComponentAddEvent<T>>(BIND_EVENT(OnComponentAdded));
    EventBus::Subscribe<ComponentRemoveEvent<T>>(BIND_EVENT(OnComponentRemoved));
}

template <typename T> void Scene::OnComponentAdded(const ComponentAddEvent<T> &event)
{
}

template <typename T> void Scene::OnComponentRemoved(const ComponentRemoveEvent<T> &event)
{
}

template <>
void Scene::OnComponentAdded(const ComponentAddEvent<UntaggedComponent> &event)
{
    auto &manager = m_World.GetEntityManager();
    TagComponentGroup::ForEachComponent([&]<typename Component>() {
        if (typeid(UntaggedComponent) != typeid(Component))
            manager.RemoveComponent<Component>(event.Entity);
    });
}

template <>
void Scene::OnComponentAdded(const ComponentAddEvent<EnemyTagComponent> &event)
{
    auto &manager = m_World.GetEntityManager();
    TagComponentGroup::ForEachComponent([&]<typename Component>() {
        if (typeid(EnemyTagComponent) != typeid(Component))
            manager.RemoveComponent<Component>(event.Entity);
    });
}

template <>
void Scene::OnComponentAdded(const ComponentAddEvent<MainCameraTagComponent> &event)
{
    auto &manager = m_World.GetEntityManager();
    TagComponentGroup::ForEachComponent([&]<typename Component>() {
        if (typeid(MainCameraTagComponent) != typeid(Component))
            manager.RemoveComponent<Component>(event.Entity);
    });
}

template <>
void Scene::OnComponentAdded(const ComponentAddEvent<PlayerTagComponent> &event)
{
    auto &manager = m_World.GetEntityManager();
    TagComponentGroup::ForEachComponent([&]<typename Component>() {
        if (typeid(PlayerTagComponent) != typeid(Component))
            manager.RemoveComponent<Component>(event.Entity);
    });
}

template <>
void Scene::OnComponentRemoved(const ComponentRemoveEvent<CameraComponent> &event)
{
    Entity eventEntity = event.Entity;

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