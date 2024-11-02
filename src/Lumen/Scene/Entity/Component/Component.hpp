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
};

using CoreComponents = ComponentGroup<IDComponent, TagComponent, TransformComponent>;

using GraphicsComponents = ComponentGroup<CameraComponent, SpriteRendererComponent>;

using PhysicsComponents = ComponentGroup<VelocityComponent>;

using UIComponents = ComponentGroup<>;

using AllComponents =
    ComponentGroup<IDComponent, TagComponent, TransformComponent, CameraComponent,
                   SpriteRendererComponent, VelocityComponent>;

using CopyableComponents =
    ComponentGroup<TagComponent, TransformComponent, CameraComponent,
                   SpriteRendererComponent, VelocityComponent>;

} // namespace Lumen