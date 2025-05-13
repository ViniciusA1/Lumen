#pragma once

#include "Lumen/Scene/Component/Core/IDComponent.hpp"
#include "Lumen/Scene/Component/Core/NameComponent.hpp"
#include "Lumen/Scene/Component/Core/TagComponent.hpp"
#include "Lumen/Scene/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Component/Graphics/CameraComponent.hpp"
#include "Lumen/Scene/Component/Graphics/SpriteRendererComponent.hpp"
#include "Lumen/Scene/Component/Physics/VelocityComponent.hpp"

namespace Lumen
{

template <typename... Component> struct ComponentGroup
{
    template <typename Callback> static void ForEachComponent(Callback callback)
    {
        ([&]() { callback.template operator()<Component>(); }(), ...);
    }
};

using CoreComponentGroup =
    ComponentGroup<IDComponent, NameComponent, UntaggedComponent, EnemyTagComponent,
                   MainCameraTagComponent, PlayerTagComponent, TransformComponent>;

using TagComponentGroup = ComponentGroup<UntaggedComponent, EnemyTagComponent,
                                         MainCameraTagComponent, PlayerTagComponent>;

using GraphicsComponentGroup = ComponentGroup<CameraComponent, SpriteRendererComponent>;

using PhysicsComponentGroup = ComponentGroup<VelocityComponent>;

using UIComponentGroup = ComponentGroup<>;

using AllComponentGroup =
    ComponentGroup<IDComponent, NameComponent, UntaggedComponent, EnemyTagComponent,
                   MainCameraTagComponent, PlayerTagComponent, TransformComponent,
                   CameraComponent, SpriteRendererComponent, VelocityComponent>;

using CopyableComponentGroup =
    ComponentGroup<NameComponent, UntaggedComponent, EnemyTagComponent,
                   MainCameraTagComponent, PlayerTagComponent, TransformComponent,
                   CameraComponent, SpriteRendererComponent, VelocityComponent>;

using DrawableComponentGroup = ComponentGroup<TransformComponent, CameraComponent,
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