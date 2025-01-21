#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Event/SceneEvent.hpp"
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

    [[nodiscard]] const entt::registry &GetRegistry() const;
    entt::registry &GetRegistry();
    World &GetWorld();
    std::unordered_map<UUID, Entity> &GetEntityMap();

    Entity CreateEntity();
    Entity CreateEntity(UUID uuid, const std::string &name = "");
    Entity CopyEntity(Entity &entity);
    void DestroyEntity(const UUID &uuid);
    void DestroyEntity(Entity &entity);
    [[nodiscard]] Entity GetEntity(const UUID &uuid) const;
    [[nodiscard]] Entity GetEntity(entt::entity entity) const;
    template <typename... Components> auto GetAllEntitiesWith();

    template <typename T, typename... Args>
    T &AddComponent(Entity &entity, Args &&...args);
    template <typename T> const T &GetComponent(const Entity &entity) const;
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

template <typename... Components> auto EntityManager::GetAllEntitiesWith()
{
    return m_Registry.view<Components...>();
}

template <typename T, typename... Args>
T &EntityManager::AddComponent(Entity &entity, Args &&...args)
{
    return m_Registry.emplace<T>(entity, std::forward<Args>(args)...);
}

template <typename T> const T &EntityManager::GetComponent(const Entity &entity) const
{
    return m_Registry.get<T>(entity);
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
    T component = GetComponent<T>(entity);
    EventBus::Publish(ComponentRemoveEvent<T>{entity, component});
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