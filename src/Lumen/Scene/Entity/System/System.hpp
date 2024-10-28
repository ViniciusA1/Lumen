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

    virtual void OnCreate() {};
    virtual void OnDestroy() {};
    virtual void OnUpdate() {};

    [[nodiscard]] entt::registry &GetRegistry();
    template <typename... Components> [[nodiscard]] EntityQuery<Components...> Query();

protected:
    World &m_ParentWorld;
};

template <typename... Components> [[nodiscard]] EntityQuery<Components...> System::Query()
{
    return EntityQuery<Components...>(GetRegistry());
}

} // namespace Lumen