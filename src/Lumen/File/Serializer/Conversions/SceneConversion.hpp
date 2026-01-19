#pragma once

#include "Lumen/File/Serializer/YamlSerializer.hpp"
#include "Lumen/Memory/Memory.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Ref<Scene> &scene);
template <> void Deserialize(const Yaml &yaml, Ref<Scene> &scene);

template <> Yaml Serialize(const World &world);
template <> void Deserialize(const Yaml &yaml, World &world);

template <> Yaml Serialize(const EntityManager &manager);
template <> void Deserialize(const Yaml &yaml, EntityManager &manager);

template <> Yaml Serialize(const SceneType &type);
template <> void Deserialize(const Yaml &yaml, SceneType &type);

template <> Yaml Serialize(const IDComponent &id);
template <> void Deserialize(const Yaml &yaml, IDComponent &id);

template <> Yaml Serialize(const NameComponent &name);
template <> void Deserialize(const Yaml &yaml, NameComponent &name);

template <> Yaml Serialize(const UntaggedComponent &tag);
template <> void Deserialize(const Yaml &yaml, UntaggedComponent &tag);
template <> Yaml Serialize(const EnemyTagComponent &tag);
template <> void Deserialize(const Yaml &yaml, EnemyTagComponent &tag);
template <> Yaml Serialize(const MainCameraTagComponent &tag);
template <> void Deserialize(const Yaml &yaml, MainCameraTagComponent &tag);
template <> Yaml Serialize(const PlayerTagComponent &tag);
template <> void Deserialize(const Yaml &yaml, PlayerTagComponent &tag);

template <> Yaml Serialize(const ParentComponent &parent);
template <> void Deserialize(const Yaml &yaml, ParentComponent &parent);

template <> Yaml Serialize(const ChildrenComponent &children);
template <> void Deserialize(const Yaml &yaml, ChildrenComponent &children);

template <> Yaml Serialize(const TransformComponent &transform);
template <> void Deserialize(const Yaml &yaml, TransformComponent &transform);

template <> Yaml Serialize(const AudioListenerComponent &audioListener);
template <> void Deserialize(const Yaml &yaml, AudioListenerComponent &audioListener);

template <> Yaml Serialize(const AudioSourceComponent &audioSource);
template <> void Deserialize(const Yaml &yaml, AudioSourceComponent &audioSource);

template <> Yaml Serialize(const CameraComponent &camera);
template <> void Deserialize(const Yaml &yaml, CameraComponent &camera);

template <> Yaml Serialize(const MeshRendererComponent &mesh);
template <> void Deserialize(const Yaml &yaml, MeshRendererComponent &mesh);

template <> Yaml Serialize(const ModelRendererComponent &model);
template <> void Deserialize(const Yaml &yaml, ModelRendererComponent &model);

template <> Yaml Serialize(const SpriteRendererComponent &sprite);
template <> void Deserialize(const Yaml &yaml, SpriteRendererComponent &sprite);

template <> Yaml Serialize(const VelocityComponent &velocity);
template <> void Deserialize(const Yaml &yaml, VelocityComponent &velocity);

template <> Yaml Serialize(const UIComponentBase &base);
template <> void Deserialize(const Yaml &yaml, UIComponentBase &base);

template <> Yaml Serialize(const ButtonComponent &button);
template <> void Deserialize(const Yaml &yaml, ButtonComponent &button);

template <> Yaml Serialize(const CanvasComponent &canvas);
template <> void Deserialize(const Yaml &yaml, CanvasComponent &canvas);

template <> Yaml Serialize(const CheckboxComponent &checkbox);
template <> void Deserialize(const Yaml &yaml, CheckboxComponent &checkbox);

template <> Yaml Serialize(const DropdownComponent &dropdown);
template <> void Deserialize(const Yaml &yaml, DropdownComponent &dropdown);

template <> Yaml Serialize(const ImageComponent &image);
template <> void Deserialize(const Yaml &yaml, ImageComponent &image);

template <> Yaml Serialize(const InputFieldComponent &inputField);
template <> void Deserialize(const Yaml &yaml, InputFieldComponent &inputField);

template <> Yaml Serialize(const LabelComponent &label);
template <> void Deserialize(const Yaml &yaml, LabelComponent &label);

template <> Yaml Serialize(const ProgressBarComponent &progressBar);
template <> void Deserialize(const Yaml &yaml, ProgressBarComponent &progressBar);

template <> Yaml Serialize(const SliderComponent &slider);
template <> void Deserialize(const Yaml &yaml, SliderComponent &slider);

} // namespace Lumen::YamlSerializer