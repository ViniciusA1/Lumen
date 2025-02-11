#include "Lumen/Scene/Entity/EntityManager.hpp"

#include "entt/entity/entity.hpp"

namespace Lumen
{

EntityManager::EntityManager(World &world) : m_ParentWorld(world)
{
}

const entt::registry &EntityManager::GetRegistry() const
{
    return m_Registry;
}

entt::registry &EntityManager::GetRegistry()
{
    return m_Registry;
}

World &EntityManager::GetWorld()
{
    return m_ParentWorld;
}

std::unordered_map<UUID, Entity> &EntityManager::GetEntityMap()
{
    return m_EntityMap;
}

Entity EntityManager::CreateEntity()
{
    return CreateEntity(UUID());
}

Entity EntityManager::CreateEntity(UUID uuid, const std::string &name)
{
    Entity entity = {m_Registry.create()};
    AddComponent<IDComponent>(entity, uuid);
    AddComponent<NameComponent>(entity, name.empty() ? "NewEntity" : name);
    AddComponent<UntaggedComponent>(entity);
    AddComponent<TransformComponent>(entity);
    m_EntityMap[uuid] = entity;
    return entity;
}

Entity EntityManager::CopyEntity(Entity entity)
{
    Entity newEntity = m_Registry.create();
    AddComponent<IDComponent>(newEntity, UUID());
    AddComponent<TagComponent>(newEntity, GetComponent<TagComponent>(entity).Name);
    CopyComponent(CopyableComponentGroup{}, newEntity, entity);
    return newEntity;
}

void EntityManager::DestroyEntity(UUID uuid)
{
    if (m_EntityMap.find(uuid) != m_EntityMap.end())
    {
        m_Registry.destroy(m_EntityMap[uuid]);
        m_EntityMap.erase(uuid);
    }
}

void EntityManager::DestroyEntity(Entity entity)
{
    m_EntityMap.erase(GetComponent<IDComponent>(entity).ID);
    m_Registry.destroy(entity);
}

Entity EntityManager::GetEntity(UUID uuid) const
{
    if (m_EntityMap.find(uuid) != m_EntityMap.end())
    {
        return m_EntityMap.at(uuid);
    }
    return {};
}

Entity EntityManager::GetEntity(entt::entity entity) const
{
    if (entity != entt::null)
    {
        UUID uuid = m_Registry.get<IDComponent>(entity).ID;
        if (m_EntityMap.find(uuid) != m_EntityMap.end())
        {
            return m_EntityMap.at(uuid);
        }
    }
    return {};
}

} // namespace Lumen