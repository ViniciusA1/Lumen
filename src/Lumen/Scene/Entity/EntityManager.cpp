#include "Lumen/Scene/Entity/EntityManager.hpp"
#include "entt/entity/entity.hpp"

namespace Lumen
{

EntityManager::EntityManager(World &world) : m_ParentWorld(world)
{
}

Entity EntityManager::CreateEntity()
{
    return CreateEntity(UUID());
}

Entity EntityManager::CreateEntity(UUID uuid, const std::string &name)
{
    Entity entity = {m_Registry.create()};
    AddComponent<IDComponent>(entity, uuid);
    AddComponent<TagComponent>(entity, name.empty() ? "NewEntity" : name);
    AddComponent<TransformComponent>(entity);
    m_EntityMap[uuid] = entity;
    return entity;
}

Entity EntityManager::CopyEntity(Entity &entity)
{
    Entity newEntity = m_Registry.create();
    AddComponent<IDComponent>(newEntity, UUID());
    AddComponent<TagComponent>(newEntity, GetComponent<TagComponent>(entity).Tag);
    CopyComponent(CopyableComponentGroup{}, newEntity, entity);
    return newEntity;
}

void EntityManager::DestroyEntity(const UUID &uuid)
{
    if (m_EntityMap.find(uuid) != m_EntityMap.end())
    {
        m_Registry.destroy(m_EntityMap[uuid]);
        m_EntityMap.erase(uuid);
    }
}

void EntityManager::DestroyEntity(Entity &entity)
{
    m_EntityMap.erase(GetComponent<IDComponent>(entity).ID);
    m_Registry.destroy(entity);
}

Entity EntityManager::GetEntity(const UUID &uuid)
{
    if (m_EntityMap.find(uuid) != m_EntityMap.end())
    {
        return m_EntityMap[uuid];
    }
    return {};
}

Entity EntityManager::GetEntity(entt::entity entity)
{
    if (entity != entt::null)
    {
        UUID uuid = m_Registry.get<IDComponent>(entity).ID;
        if (m_EntityMap.find(uuid) != m_EntityMap.end())
        {
            return m_EntityMap[uuid];
        }
    }
    return {};
}

} // namespace Lumen