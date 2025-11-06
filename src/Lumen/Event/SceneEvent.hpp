#pragma once

#include "Lumen/Scene/Entity/Entity.hpp"
#include "Lumen/System/UUID.hpp"


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