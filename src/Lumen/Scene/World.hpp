#pragma once

#include "Lumen/Memory/Memory.hpp"
#include "Lumen/Scene/Entity/EntityManager.hpp"
#include "Lumen/Scene/System/DrawSystem.hpp"
#include "Lumen/Scene/System/System.hpp"
#include "Lumen/Scene/System/UpdateSystem.hpp"

#include <typeindex>

namespace Lumen
{

class World
{
public:
    World();
    ~World() = default;

    World(World &&other) noexcept;
    World &operator=(World &&other) noexcept;

    [[nodiscard]] const EntityManager &GetEntityManager() const;
    EntityManager &GetEntityManager();

    template <typename T> [[nodiscard]] bool HasSystem() const;

    template <typename T, typename... Args> Ref<T> AddSystem(Args &&...args);
    template <typename T> Ref<T> GetSystem() const;
    template <typename T> void RemoveSystem();
    template <typename T> void SetSystemEnable(bool enable) const;

    void OnUpdate();
    void OnDraw();

private:
    EntityManager m_EntityManager;

    std::unordered_map<std::type_index, Ref<System>> m_SystemLookupMap;
    std::vector<Ref<UpdateSystem>> m_UpdateSystemList;
    std::vector<Ref<DrawSystem>> m_DrawSystemList;
};

template <typename T> bool World::HasSystem() const
{
    return m_SystemLookupMap.contains(typeid(T));
}

template <typename T, typename... Args> Ref<T> World::AddSystem(Args &&...args)
{
    auto it = m_SystemLookupMap.find(typeid(T));
    if (it != m_SystemLookupMap.end())
        return std::dynamic_pointer_cast<T>(it->second);

    auto system = CreateRef<T>(*this, std::forward<Args>(args)...);
    system->OnCreate();

    if constexpr (std::is_base_of_v<DrawSystem, T>)
        m_DrawSystemList.push_back(std::static_pointer_cast<DrawSystem>(system));
    else if constexpr (std::is_base_of_v<UpdateSystem, T>)
        m_UpdateSystemList.push_back(std::static_pointer_cast<UpdateSystem>(system));

    m_SystemLookupMap[typeid(T)] = std::static_pointer_cast<System>(system);
    return system;
}

template <typename T> Ref<T> World::GetSystem() const
{
    auto it = m_SystemLookupMap.find(typeid(T));
    if (it != m_SystemLookupMap.end())
        return nullptr;

    return std::static_pointer_cast<T>(it->second);
}

template <typename T> void World::RemoveSystem()
{
    auto it = m_SystemLookupMap.find(typeid(T));
    if (it == m_SystemLookupMap.end())
        return;

    auto system = std::dynamic_pointer_cast<T>(it->second);
    if constexpr (std::is_base_of_v<DrawSystem, T>)
    {
        auto vecIt = std::find_if(
            m_DrawSystemList.begin(), m_DrawSystemList.end(),
            [&system](const Ref<System> &ptr) { return ptr.get() == system.get(); });

        if (vecIt != m_DrawSystemList.end())
            m_DrawSystemList.erase(vecIt);
    }
    else if constexpr (std::is_base_of_v<UpdateSystem, T>)
    {
        auto vecIt = std::find_if(
            m_UpdateSystemList.begin(), m_UpdateSystemList.end(),
            [&system](const Ref<System> &ptr) { return ptr.get() == system.get(); });

        if (vecIt != m_UpdateSystemList.end())
            m_UpdateSystemList.erase(vecIt);
    }

    system->OnDestroy();
    m_SystemLookupMap.erase(it);
}

template <typename T> void World::SetSystemEnable(bool enable) const
{
    auto it = m_SystemLookupMap.find(typeid(T));
    if (it == m_SystemLookupMap.end())
        return;

    it->second->SetEnable(enable);
}

} // namespace Lumen