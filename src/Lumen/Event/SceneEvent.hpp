#pragma once

#include "Lumen/System/UUID.hpp"
#include "Lumen/World/Entity/Entity.hpp"

namespace Lumen
{

template <typename T> struct ComponentAddEvent
{
    Entity Entity;
    T &Component;
};

template <typename T> struct ComponentRemoveEvent
{
    Entity Entity;
    T &Component;
};

struct AddChildEvent
{
    UUID ParentID;
    UUID ChildID;
};

struct RemoveChildEvent
{
    UUID ParentID;
    UUID ChildID;
};

struct ReparentEvent
{
    UUID NewParentID;
    UUID ChildID;
};

struct FocusEntityEvent
{
    UUID EntityID;
};

} // namespace Lumen