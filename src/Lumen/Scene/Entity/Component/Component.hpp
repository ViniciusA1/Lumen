#pragma once

#include "Lumen/Scene/Entity/Component/CameraComponent.hpp"
#include "Lumen/Scene/Entity/Component/IDComponent.hpp"
#include "Lumen/Scene/Entity/Component/SpriteRendererComponent.hpp"
#include "Lumen/Scene/Entity/Component/TagComponent.hpp"
#include "Lumen/Scene/Entity/Component/TransformComponent.hpp"
#include "Lumen/Scene/Entity/Component/VelocityComponent.hpp"

namespace Lumen
{

template <typename... Component> struct ComponentGroup
{
};

using AllComponents =
    ComponentGroup<TransformComponent, VelocityComponent, SpriteRendererComponent>;

} // namespace Lumen