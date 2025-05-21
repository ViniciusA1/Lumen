#pragma once

#include "Lumen/Scene/Component/Component.hpp"

namespace Lumen
{

template <typename... Component> struct ComponentGroup
{
    template <typename Callback> static void ForEachComponent(Callback callback)
    {
        ([&]() { callback.template operator()<Component>(); }(), ...);
    }
};

using AudioComponentGroup = ComponentGroup<AUDIO_COMPONENTS>;

using TagComponentGroup = ComponentGroup<TAG_COMPONENTS>;

using CoreComponentGroup = ComponentGroup<CORE_COMPONENTS>;

using GraphicsComponentGroup = ComponentGroup<GRAPHICS_COMPONENTS>;

using PhysicsComponentGroup = ComponentGroup<PHYSICS_COMPONENTS>;

using UIComponentGroup = ComponentGroup<UI_COMPONENTS>;

using AllComponentGroup = ComponentGroup<ALL_COMPONENTS>;

using CopyableComponentGroup = ComponentGroup<COPYABLE_COMPONENTS>;

using DrawableComponentGroup = ComponentGroup<DRAWABLE_COMPONENTS>;

} // namespace Lumen