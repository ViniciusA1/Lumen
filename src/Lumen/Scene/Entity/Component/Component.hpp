#pragma once

#include "Lumen/Scene/Entity/Component/Core/IDComponent.hpp"
#include "Lumen/Scene/Entity/Component/Core/TagComponent.hpp"
#include "Lumen/Scene/Entity/Component/Core/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/Camera2DComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/Camera3DComponent.hpp"
#include "Lumen/Scene/Entity/Component/Graphics/SpriteRendererComponent.hpp"
#include "Lumen/Scene/Entity/Component/Physics/VelocityComponent.hpp"

namespace Lumen
{

template <typename... Component> struct ComponentGroup
{
};

using CoreComponents = ComponentGroup<IDComponent, TagComponent, TransformComponent>;

using GraphicsComponents =
    ComponentGroup<Camera2DComponent, Camera3DComponent, SpriteRendererComponent>;

using PhysicsComponents = ComponentGroup<VelocityComponent>;

using UIComponents = ComponentGroup<>;

using AllComponents =
    ComponentGroup<IDComponent, TagComponent, TransformComponent, Camera2DComponent,
                   Camera3DComponent, SpriteRendererComponent, VelocityComponent>;

using CopyableComponents =
    ComponentGroup<TagComponent, TransformComponent, Camera2DComponent, Camera3DComponent,
                   SpriteRendererComponent, VelocityComponent>;

} // namespace Lumen