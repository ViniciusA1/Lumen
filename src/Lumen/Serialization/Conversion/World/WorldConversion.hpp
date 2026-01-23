#pragma once

#include "Lumen/Serialization/Json.hpp"

#include "Lumen/World/Component/Component.hpp"
#include "Lumen/World/Scene.hpp"
#include "Lumen/World/SceneType.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const SceneType &type);
template <> void Deserialize(const Json &json, SceneType &type);

template <> Json Serialize(const Ref<Scene> &scene);
template <> void Deserialize(const Json &json, Ref<Scene> &scene);

template <> Json Serialize(const IDComponent &id);
template <> void Deserialize(const Json &json, IDComponent &id);

template <> Json Serialize(const NameComponent &name);
template <> void Deserialize(const Json &json, NameComponent &name);

template <> Json Serialize(const UntaggedComponent &tag);
template <> void Deserialize(const Json &json, UntaggedComponent &tag);

template <> Json Serialize(const EnemyTagComponent &tag);
template <> void Deserialize(const Json &json, EnemyTagComponent &tag);

template <> Json Serialize(const MainCameraTagComponent &tag);
template <> void Deserialize(const Json &json, MainCameraTagComponent &tag);

template <> Json Serialize(const PlayerTagComponent &tag);
template <> void Deserialize(const Json &json, PlayerTagComponent &tag);

template <> Json Serialize(const ParentComponent &parent);
template <> void Deserialize(const Json &json, ParentComponent &parent);

template <> Json Serialize(const ChildrenComponent &children);
template <> void Deserialize(const Json &json, ChildrenComponent &children);

template <> Json Serialize(const TransformComponent &transform);
template <> void Deserialize(const Json &json, TransformComponent &transform);

template <> Json Serialize(const AudioListenerComponent &audioListener);
template <> void Deserialize(const Json &json, AudioListenerComponent &audioListener);

template <> Json Serialize(const AudioSourceComponent &audioSource);
template <> void Deserialize(const Json &json, AudioSourceComponent &audioSource);

template <> Json Serialize(const CameraComponent &camera);
template <> void Deserialize(const Json &json, CameraComponent &camera);

template <> Json Serialize(const MeshRendererComponent &mesh);
template <> void Deserialize(const Json &json, MeshRendererComponent &mesh);

template <> Json Serialize(const SpriteRendererComponent &sprite);
template <> void Deserialize(const Json &json, SpriteRendererComponent &sprite);

template <> Json Serialize(const UIComponentBase &base);
template <> void Deserialize(const Json &json, UIComponentBase &base);

template <> Json Serialize(const ButtonComponent &button);
template <> void Deserialize(const Json &json, ButtonComponent &button);

template <> Json Serialize(const CanvasComponent &canvas);
template <> void Deserialize(const Json &json, CanvasComponent &canvas);

template <> Json Serialize(const CheckboxComponent &checkbox);
template <> void Deserialize(const Json &json, CheckboxComponent &checkbox);

template <> Json Serialize(const DropdownComponent &dropdown);
template <> void Deserialize(const Json &json, DropdownComponent &dropdown);

template <> Json Serialize(const ImageComponent &image);
template <> void Deserialize(const Json &json, ImageComponent &image);

template <> Json Serialize(const InputFieldComponent &inputField);
template <> void Deserialize(const Json &json, InputFieldComponent &inputField);

template <> Json Serialize(const LabelComponent &label);
template <> void Deserialize(const Json &json, LabelComponent &label);

template <> Json Serialize(const ProgressBarComponent &progressBar);
template <> void Deserialize(const Json &json, ProgressBarComponent &progressBar);

template <> Json Serialize(const SliderComponent &slider);
template <> void Deserialize(const Json &json, SliderComponent &slider);

template <> Json Serialize(const ScriptComponent &script);
template <> void Deserialize(const Json &json, ScriptComponent &script);

} // namespace Lumen::JsonSerializer