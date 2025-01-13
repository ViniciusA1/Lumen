#pragma once

#include "Lumen/Scene/Entity/Entity.hpp"

namespace Lumen
{

template <typename T> class ComponentAddEvent
{
public:
    ComponentAddEvent(Entity entity, T &component)
        : m_Entity(entity), m_Component(component)
    {
    }

    [[nodiscard]] T &GetComponent() const { return m_Component; }
    [[nodiscard]] Entity GetEntity() const { return m_Entity; }

private:
    Entity m_Entity;
    T &m_Component;
};

template <typename T> class ComponentRemoveEvent
{
public:
    ComponentRemoveEvent(Entity entity, T &component)
        : m_Entity(entity), m_Component(component)
    {
    }

    [[nodiscard]] T &GetComponent() const { return m_Component; }
    [[nodiscard]] Entity GetEntity() const { return m_Entity; }

private:
    Entity m_Entity;
    T &m_Component;
};

} // namespace Lumen