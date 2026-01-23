#pragma once

#include "Lumen/World/Component/Audio/AudioListenerComponent.hpp"
#include "Lumen/World/Component/Audio/AudioSourceComponent.hpp"

#include "Lumen/World/Component/Core/ChildrenComponent.hpp"
#include "Lumen/World/Component/Core/IDComponent.hpp"
#include "Lumen/World/Component/Core/NameComponent.hpp"
#include "Lumen/World/Component/Core/ParentComponent.hpp"
#include "Lumen/World/Component/Core/TagComponent.hpp"
#include "Lumen/World/Component/Core/TransformComponent.hpp"

#include "Lumen/World/Component/Graphics/CameraComponent.hpp"
#include "Lumen/World/Component/Graphics/MeshRendererComponent.hpp"
#include "Lumen/World/Component/Graphics/ModelRendererComponent.hpp"
#include "Lumen/World/Component/Graphics/SpriteRendererComponent.hpp"

#include "Lumen/World/Component/Script/ScriptComponent.hpp"

#include "Lumen/World/Component/UI/ButtonComponent.hpp"
#include "Lumen/World/Component/UI/CanvasComponent.hpp"
#include "Lumen/World/Component/UI/CheckboxComponent.hpp"
#include "Lumen/World/Component/UI/DropdownComponent.hpp"
#include "Lumen/World/Component/UI/ImageComponent.hpp"
#include "Lumen/World/Component/UI/InputFieldComponent.hpp"
#include "Lumen/World/Component/UI/LabelComponent.hpp"
#include "Lumen/World/Component/UI/ProgressBarComponent.hpp"
#include "Lumen/World/Component/UI/SliderComponent.hpp"

#define AUDIO_COMPONENTS AudioListenerComponent, AudioSourceComponent

#define TAG_COMPONENTS                                                                   \
    UntaggedComponent, EnemyTagComponent, MainCameraTagComponent, PlayerTagComponent

#define CORE_COMPONENTS                                                                  \
    IDComponent, NameComponent, TAG_COMPONENTS, ParentComponent, ChildrenComponent,      \
        TransformComponent

#define GRAPHICS_COMPONENTS                                                              \
    CameraComponent, MeshRendererComponent, ModelRendererComponent,                      \
        SpriteRendererComponent

#define SCRIPT_COMPONENTS ScriptComponent

#define UI_COMPONENTS                                                                    \
    ButtonComponent, CanvasComponent, CheckboxComponent, DropdownComponent,              \
        ImageComponent, InputFieldComponent, LabelComponent, ProgressBarComponent,       \
        SliderComponent

#define ALL_COMPONENTS                                                                   \
    CORE_COMPONENTS, AUDIO_COMPONENTS, GRAPHICS_COMPONENTS, SCRIPT_COMPONENTS,           \
        UI_COMPONENTS

#define COPYABLE_COMPONENTS                                                              \
    NameComponent, TAG_COMPONENTS, TransformComponent, AUDIO_COMPONENTS,                 \
        GRAPHICS_COMPONENTS, SCRIPT_COMPONENTS, UI_COMPONENTS

#define DRAWABLE_COMPONENTS                                                              \
    TransformComponent, AUDIO_COMPONENTS, GRAPHICS_COMPONENTS, SCRIPT_COMPONENTS,        \
        UI_COMPONENTS
