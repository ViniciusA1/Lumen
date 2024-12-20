#pragma once

#include "Lumen/Scene/Entity/Component/Core/IDComponent.hpp"
#include "Lumen/Scene/Entity/Component/Core/TagComponent.hpp"
#include "Lumen/Scene/Entity/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/CameraComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/SpriteRendererComponent.hpp"
#include "Lumen/Scene/Entity/Component/Physics/VelocityComponent.hpp"

namespace Lumen
{

template <typename... Component> struct ComponentGroup
{
    template <typename Callback> static void ForEachComponent(Callback callback)
    {
        ([&]() { callback.template operator()<Component>(); }(), ...);
    }
};

using CoreComponentGroup = ComponentGroup<IDComponent, TagComponent, TransformComponent>;

using GraphicsComponentGroup = ComponentGroup<CameraComponent, SpriteRendererComponent>;

using PhysicsComponentGroup = ComponentGroup<VelocityComponent>;

using UIComponentGroup = ComponentGroup<>;

using AllComponentGroup =
    ComponentGroup<IDComponent, TagComponent, TransformComponent, CameraComponent,
                   SpriteRendererComponent, VelocityComponent>;

using CopyableComponentGroup =
    ComponentGroup<TagComponent, TransformComponent, CameraComponent,
                   SpriteRendererComponent, VelocityComponent>;

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
    ComponentGroupCollection<CoreComponentGroup, GraphicsComponentGroup,
                             PhysicsComponentGroup, UIComponentGroup>;

using IterableGroupCollection =
    ComponentGroupCollection<GraphicsComponentGroup, PhysicsComponentGroup,
                             UIComponentGroup>;

} // namespace Lumen