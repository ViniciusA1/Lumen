#pragma once

#include <entt/entity/registry.hpp>

namespace Lumen
{

class Entity
{
public:
    Entity() = default;
    Entity(entt::entity handle);

    operator bool() const { return m_EntityHandle != entt::null; }
    operator entt::entity() const { return m_EntityHandle; }
    operator uint32_t() const { return (uint32_t)m_EntityHandle; }
    bool operator!=(const Entity &other) const { return !(*this == other); }
    bool operator==(const Entity &other) const
    {
        return m_EntityHandle == other.m_EntityHandle;
    }

private:
    entt::entity m_EntityHandle{entt::null};
};

} // namespace Lumen