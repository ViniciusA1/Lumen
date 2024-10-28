#include "Lumen/Scene/Entity/EntityManager.hpp"

namespace Lumen
{

EntityManager::EntityManager(World &world) : m_ParentWorld(world)
{
}

Entity EntityManager::CreateEntity()
{
    return CreateEntity(UUID());
}

Entity EntityManager::CreateEntity(UUID uuid)
{
    Entity entity = {m_Registry.create()};
    AddComponent<IDComponent>(entity, uuid);
    AddComponent<TagComponent>(entity, "NewEntity");
    AddComponent<TransformComponent>(entity);
    m_EntityMap[uuid] = entity;
    return entity;
}

Entity EntityManager::CopyEntity(Entity &entity)
{
    Entity newEntity = m_Registry.create();
    AddComponent<IDComponent>(newEntity, UUID());
    AddComponent<TagComponent>(newEntity, GetComponent<TagComponent>(entity).Tag);
    CopyComponent(CopyableComponents{}, newEntity, entity);
    return newEntity;
}

void EntityManager::RemoveEntity(const UUID &uuid)
{
    if (m_EntityMap.find(uuid) != m_EntityMap.end())
    {
        m_Registry.destroy(m_EntityMap[uuid]);
        m_EntityMap.erase(uuid);
    }
}

void EntityManager::RemoveEntity(Entity &entity)
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

} // namespace Lumen