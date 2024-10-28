#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Scene/Entity/Component/Component.hpp"
#include "Lumen/Scene/Entity/Entity.hpp"
#include <entt/entity/registry.hpp>
#include <unordered_map>

namespace Lumen
{

class World;

class EntityManager
{
public:
    EntityManager(World &world);

    inline entt::registry &GetRegistry();
    inline World &GetWorld();

    Entity CreateEntity();
    Entity CreateEntity(UUID uuid);
    Entity CopyEntity(Entity &entity);
    void RemoveEntity(const UUID &uuid);
    void RemoveEntity(Entity &entity);
    [[nodiscard]] Entity GetEntity(const UUID &uuid);
    template <typename... Components> auto GetAllEntitiesWith();

    template <typename T, typename... Args>
    T &AddComponent(Entity &entity, Args &&...args);
    template <typename T> T &GetComponent(const Entity &entity);
    template <typename... T> [[nodiscard]] bool HasComponent(const Entity &entity) const;
    template <typename T> void RemoveComponent(Entity &entity);
    template <typename Component> void ToggleComponent(const Entity &entity, bool enable);

private:
    template <typename... Component> void CopyComponent(Entity dst, Entity src);
    template <typename... Component>
    void CopyComponent(ComponentGroup<Component...>, Entity dst, Entity src);

private:
    entt::registry m_Registry;
    std::unordered_map<UUID, Entity> m_EntityMap;
    World &m_ParentWorld;
};

entt::registry &EntityManager::GetRegistry()
{
    return m_Registry;
}

World &EntityManager::GetWorld()
{
    return m_ParentWorld;
}

template <typename... Components> auto EntityManager::GetAllEntitiesWith()
{
    return m_Registry.view<Components...>();
}

template <typename T, typename... Args>
T &EntityManager::AddComponent(Entity &entity, Args &&...args)
{
    return m_Registry.emplace<T>(entity, std::forward<Args>(args)...);
}

template <typename T> T &EntityManager::GetComponent(const Entity &entity)
{
    return m_Registry.get<T>(entity);
}

template <typename... T> bool EntityManager::HasComponent(const Entity &entity) const
{
    return m_Registry.all_of<T...>(entity);
}

template <typename T> void EntityManager::RemoveComponent(Entity &entity)
{
    m_Registry.remove<T>(entity);
}

template <typename Component>
void EntityManager::ToggleComponent(const Entity &entity, bool enable)
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