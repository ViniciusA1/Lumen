#include "Lumen/World/Entity/EntityManager.hpp"

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

Entity EntityManager::CreateEntity(const std::string &name)
{
    return CreateEntity(UUID(), name);
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
    auto it = m_EntityMap.find(uuid);
    if (it != m_EntityMap.end())
        DestroyEntity(it->second);
}

void EntityManager::DestroyEntity(Entity entity)
{
    UUID myID = GetComponent<IDComponent>(entity).ID;

    if (HasComponent<ChildrenComponent>(entity))
    {
        auto &children = GetComponent<ChildrenComponent>(entity).ChildrenID;
        auto childrenCopy = children;
        for (UUID childID : childrenCopy)
        {
            DestroyEntity(GetEntity(childID));
        }
    }

    if (HasComponent<ParentComponent>(entity))
    {
        UUID parentID = GetComponent<ParentComponent>(entity).ParentID;
        EventBus::Publish(RemoveChildEvent{parentID, myID}, PublishMode::Immediate);
    }

    if (HasComponent<ParentComponent>(entity))
        RemoveComponent<ParentComponent>(entity);

    if (HasComponent<ChildrenComponent>(entity))
        RemoveComponent<ChildrenComponent>(entity);

    m_EntityMap.erase(myID);
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