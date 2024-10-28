#pragma once

#include <entt/entity/registry.hpp>

namespace Lumen
{

template <typename... Components> class EntityQuery
{
public:
    explicit EntityQuery(entt::registry &registry)
        : m_Registry(registry), m_View(registry.view<Components...>())
    {
    }

    auto Each() const { return m_View.each(); }

    template <typename... ExcludeComponents> auto WithNone() const
    {
        return m_Registry.view<Components...>(entt::exclude<ExcludeComponents...>);
    }

private:
    entt::registry &m_Registry;
    decltype(std::declval<entt::registry>().view<Components...>()) m_View;
};

} // namespace Lumen