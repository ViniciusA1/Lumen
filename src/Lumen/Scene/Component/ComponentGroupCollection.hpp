#pragma once

#include "Lumen/Scene/Component/ComponentGroup.hpp"

namespace Lumen
{

template <typename... Group> struct ComponentGroupCollection
{
    template <typename Callback> static void ForEachGroupAndComponent(Callback callback)
    {
        ([&]() { Group::ForEachComponent(callback); }(), ...);
    }

    template <typename GroupCallback>
    static void ForEachGroup(GroupCallback groupCallback)
    {
        ([&]() { groupCallback.template operator()<Group>(); }(), ...);
    }
};

using AllGroupCollection =
    ComponentGroupCollection<CoreComponentGroup, AudioComponentGroup,
                             GraphicsComponentGroup, PhysicsComponentGroup,
                             UIComponentGroup>;

using IterableGroupCollection =
    ComponentGroupCollection<AudioComponentGroup, GraphicsComponentGroup,
                             PhysicsComponentGroup, UIComponentGroup>;

} // namespace Lumen