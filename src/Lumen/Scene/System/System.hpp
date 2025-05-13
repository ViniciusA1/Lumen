#pragma once

#include "Lumen/Scene/Entity/EntityQuery.hpp"

#include <entt/entity/registry.hpp>

namespace Lumen
{

class World;

class System
{
public:
    System(World &world);

    [[nodiscard]] bool IsEnabled() const;

    void SetEnable(bool enable);

    virtual void OnEnable() {};
    virtual void OnDisable() {};

    virtual void OnCreate() {};
    virtual void OnDestroy() {};

    [[nodiscard]] entt::registry &GetRegistry();
    template <typename... Components> [[nodiscard]] EntityQuery<Components...> Query();

protected:
    World &m_ParentWorld;
    bool m_IsEnabled;
};

template <typename... Components> [[nodiscard]] EntityQuery<Components...> System::Query()
{
    return EntityQuery<Components...>(GetRegistry());
}

} // namespace Lumen