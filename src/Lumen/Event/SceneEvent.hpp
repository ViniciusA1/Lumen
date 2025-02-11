#pragma once

#include "Lumen/Scene/Entity/Entity.hpp"

namespace Lumen
{

template <typename T> class ComponentAddEvent
{
public:
    Entity Entity;
    T &Component;

public:
    ComponentAddEvent(class Entity entity, T &component)
        : Entity(entity), Component(component)
    {
    }
};

template <typename T> class ComponentRemoveEvent
{
public:
    Entity Entity;
    T &Component;

public:
    ComponentRemoveEvent(class Entity entity, T &component)
        : Entity(entity), Component(component)
    {
    }
};

} // namespace Lumen