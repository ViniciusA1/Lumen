#pragma once

#include "Lumen/Scene/Component/Audio/AudioListenerComponent.hpp"
#include "Lumen/Scene/Component/Audio/AudioSourceComponent.hpp"

#include "Lumen/Scene/Component/Core/ChildrenComponent.hpp"
#include "Lumen/Scene/Component/Core/IDComponent.hpp"
#include "Lumen/Scene/Component/Core/NameComponent.hpp"
#include "Lumen/Scene/Component/Core/ParentComponent.hpp"
#include "Lumen/Scene/Component/Core/TagComponent.hpp"
#include "Lumen/Scene/Component/Core/TransformComponent.hpp"

#include "Lumen/Scene/Component/Graphics/CameraComponent.hpp"
#include "Lumen/Scene/Component/Graphics/MeshRendererComponent.hpp"
#include "Lumen/Scene/Component/Graphics/ModelRendererComponent.hpp"
#include "Lumen/Scene/Component/Graphics/SpriteRendererComponent.hpp"

#include "Lumen/Scene/Component/Physics/VelocityComponent.hpp"

#include "Lumen/Scene/Component/UI/ButtonComponent.hpp"
#include "Lumen/Scene/Component/UI/LabelComponent.hpp"

#define AUDIO_COMPONENTS AudioListenerComponent, AudioSourceComponent

#define TAG_COMPONENTS                                                                   \
    UntaggedComponent, EnemyTagComponent, MainCameraTagComponent, PlayerTagComponent

#define CORE_COMPONENTS                                                                  \
    IDComponent, NameComponent, TAG_COMPONENTS, ParentComponent, ChildrenComponent,      \
        TransformComponent

#define GRAPHICS_COMPONENTS                                                              \
    CameraComponent, MeshRendererComponent, ModelRendererComponent,                      \
        SpriteRendererComponent

#define PHYSICS_COMPONENTS VelocityComponent

#define UI_COMPONENTS ButtonComponent, LabelComponent

#define ALL_COMPONENTS                                                                   \
    CORE_COMPONENTS, AUDIO_COMPONENTS, GRAPHICS_COMPONENTS, PHYSICS_COMPONENTS,          \
        UI_COMPONENTS

#define COPYABLE_COMPONENTS                                                              \
    NameComponent, TAG_COMPONENTS, TransformComponent, AUDIO_COMPONENTS,                 \
        GRAPHICS_COMPONENTS, PHYSICS_COMPONENTS, UI_COMPONENTS

#define DRAWABLE_COMPONENTS                                                              \
    TransformComponent, AUDIO_COMPONENTS, GRAPHICS_COMPONENTS, PHYSICS_COMPONENTS,       \
        UI_COMPONENTS
