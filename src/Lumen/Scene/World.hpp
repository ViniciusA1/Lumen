#pragma once

#include "Lumen/Scene/Entity/EntityManager.hpp"
#include "Lumen/Scene/Entity/System/System.hpp"
#include <typeindex>

namespace Lumen
{

class World
{
public:
    World();
    ~World() = default;

    inline EntityManager &GetEntityManager();

    template <typename T, typename... Args> T &AddSystem(Args &&...args);
    template <typename T> T &GetSystem();
    template <typename T> void RemoveSystem();
    template <typename T> [[nodiscard]] bool HasSystem() const;

    void Update();

private:
    EntityManager m_EntityManager;
    std::unordered_map<std::type_index, Scope<System>> m_SystemMap;
};

EntityManager &World::GetEntityManager()
{
    return m_EntityManager;
}

template <typename T, typename... Args> T &World::AddSystem(Args &&...args)
{
    auto system = CreateScope<T>(*this, std::forward<Args>(args)...);
    system->OnCreate();
    m_SystemMap[std::type_index(typeid(T))] = std::move(system);
    return *system;
}

template <typename T> T &World::GetSystem()
{
    auto it = m_SystemMap.find(std::type_index(typeid(T)));
    if (it != m_SystemMap.end())
    {
        return static_cast<T *>(it->second.get());
    }
    return nullptr;
}

template <typename T> void World::RemoveSystem()
{
    auto it = m_SystemMap.find(std::type_index(typeid(T)));
    if (it != m_SystemMap.end())
    {
        m_SystemMap.erase(it);
    }
}

template <typename T> bool World::HasSystem() const
{
    return m_SystemMap.find(std::type_index(typeid(T))) != m_SystemMap.end();
}

} // namespace Lumen