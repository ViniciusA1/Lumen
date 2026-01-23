#pragma once

#include "Lumen/World/Entity/EntityQuery.hpp"

namespace Lumen
{

template <typename... Components>
EntityQuery<Components...>::EntityQuery(entt::registry &registry)
    : m_Registry(registry), m_View(registry.view<Components...>())
{
}

template <typename... Components>
template <typename Func>
void EntityQuery<Components...>::ForEach(Func &&func) const
{
    m_View.each([&](auto entity, Components &...comps) { func(entity, comps...); });
}

template <typename... Components>
template <typename... ExcludeComponents, typename Func>
void EntityQuery<Components...>::ForEachExcluding(Func &&func) const
{
    auto view = m_Registry.view<Components...>(entt::exclude<ExcludeComponents...>);
    view.each([&](auto entity, Components &...comps) { func(entity, comps...); });
}

template <typename... Components> auto EntityQuery<Components...>::Each() const
{
    return m_View.each();
}

template <typename... Components>
template <typename... ExcludeComponents>
auto EntityQuery<Components...>::EachExcluding() const
{
    auto view = m_Registry.view<Components...>(entt::exclude<ExcludeComponents...>);
    return view.each();
}

} // namespace Lumen
