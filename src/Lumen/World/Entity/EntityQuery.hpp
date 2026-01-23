#pragma once

#include <entt/entity/registry.hpp>

namespace Lumen
{

template <typename... Components> class EntityQuery
{
public:
    using ViewType = decltype(std::declval<entt::registry>().view<Components...>());

public:
    explicit EntityQuery(entt::registry &registry);

    template <typename Func> void ForEach(Func &&func) const;

    template <typename... ExcludeComponents, typename Func>
    void ForEachExcluding(Func &&func) const;

    auto Each() const;

    template <typename... ExcludeComponents> auto EachExcluding() const;

private:
    entt::registry &m_Registry;
    ViewType m_View;
};

} // namespace Lumen

#include "Lumen/World/Entity/EntityQuery.inl"