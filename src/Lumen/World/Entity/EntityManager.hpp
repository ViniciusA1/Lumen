#pragma once

#include "Lumen/System/UUID.hpp"
#include "Lumen/World/Component/ComponentGroup.hpp"
#include "Lumen/World/Entity/Entity.hpp"

#include "entt/entity/registry.hpp"
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
    Entity CreateEntity(const std::string &name);
    Entity CreateEntity(UUID uuid, const std::string &name = "");
    Entity CopyEntity(Entity entity);
    void DestroyEntity(UUID uuid);
    void DestroyEntity(Entity entity);
    [[nodiscard]] Entity GetEntity(UUID uuid) const;
    [[nodiscard]] Entity GetEntity(entt::entity entity) const;
    template <typename... Components> auto GetAllEntitiesWith();
    template <typename... Components> [[nodiscard]] Entity GetEntityWith() const;
    template <typename Component, typename... Components>
    Component &GetEntityComponentWith();

    template <typename T, typename... Args>
    T &AddComponent(Entity entity, Args &&...args);
    template <typename T> const T &GetComponent(Entity entity) const;
    template <typename T> T &GetComponent(Entity entity);
    template <typename... T> [[nodiscard]] bool HasComponent(Entity entity) const;
    template <typename T> void RemoveComponent(Entity entity);
    template <typename Component> void ToggleComponent(Entity entity, bool enable);

private:
    template <typename... Component> void CopyComponent(Entity dst, Entity src);
    template <typename... Component>
    void CopyComponent(ComponentGroup<Component...>, Entity dst, Entity src);

private:
    entt::registry m_Registry;
    std::unordered_map<UUID, Entity> m_EntityMap;
    World &m_ParentWorld;
};

} // namespace Lumen

#include "Lumen/World/Entity/EntityManager.inl"