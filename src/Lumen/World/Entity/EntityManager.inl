#pragma once

#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Event/SceneEvent.hpp"
#include "Lumen/World/Entity/EntityManager.hpp"

#include <entt/meta/meta.hpp>

namespace Lumen
{

template <typename... Components> auto EntityManager::GetAllEntitiesWith()
{
    return m_Registry.view<Components...>();
}

template <typename... Components> Entity EntityManager::GetEntityWith() const
{
    auto view = m_Registry.view<Components...>();
    if (view.begin() != view.end())
        return *view.begin();

    return {};
}

template <typename Component, typename... Components>
Component &EntityManager::GetEntityComponentWith()
{
    return m_Registry.get<Component>(GetEntityWith<Components...>());
}

template <typename T, typename... Args>
T &EntityManager::AddComponent(Entity entity, Args &&...args)
{
    T &component = m_Registry.emplace<T>(entity, std::forward<Args>(args)...);
    EventBus::Publish(ComponentAddEvent<T>{entity, component}, PublishMode::Immediate);
    return component;
}

template <typename T> const T &EntityManager::GetComponent(Entity entity) const
{
    return m_Registry.get<T>(entity);
}

template <typename T> T &EntityManager::GetComponent(Entity entity)
{
    return m_Registry.get<T>(entity);
}

template <typename... T> bool EntityManager::HasComponent(Entity entity) const
{
    return m_Registry.all_of<T...>(entity);
}

template <typename T> void EntityManager::RemoveComponent(Entity entity)
{
    if (HasComponent<T>(entity))
    {
        T &component = GetComponent<T>(entity);
        EventBus::Publish(ComponentRemoveEvent<T>{entity, component});
        m_Registry.remove<T>(entity);
    }
}

template <typename Component>
void EntityManager::ToggleComponent(Entity entity, bool enable)
{
    if (auto *component = m_Registry.try_get<Component>(entity))
    {
        component->IsEnabled = enable;
    }
}

template <typename... Component> void EntityManager::CopyComponent(Entity dst, Entity src)
{
    (
        [&]() {
            if (HasComponent<Component>(src))
                AddComponent<Component>(dst, GetComponent<Component>(src));
        }(),
        ...);
}

template <typename... Component>
void EntityManager::CopyComponent(ComponentGroup<Component...>, Entity dst, Entity src)
{
    CopyComponent<Component...>(dst, src);
}

} // namespace Lumen