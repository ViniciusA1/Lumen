#pragma once

#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/Scene/Scene.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Ref<Scene> &scene);
template <> void Deserialize(const Yaml &yaml, Ref<Scene> &scene);

template <> Yaml Serialize(const World &world);
template <> void Deserialize(const Yaml &yaml, World &world);

template <> Yaml Serialize(const EntityManager &manager);
template <> void Deserialize(const Yaml &yaml, EntityManager &manager);

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

template <> Yaml Serialize(const TransformComponent &transform);
template <> void Deserialize(const Yaml &yaml, TransformComponent &transform);

template <> Yaml Serialize(const CameraComponent &camera);
template <> void Deserialize(const Yaml &yaml, CameraComponent &camera);

template <> Yaml Serialize(const SpriteRendererComponent &spriteRenderer);
template <> void Deserialize(const Yaml &yaml, SpriteRendererComponent &spriteRenderer);

template <> Yaml Serialize(const VelocityComponent &velocity);
template <> void Deserialize(const Yaml &yaml, VelocityComponent &velocity);

} // namespace Lumen::YamlSerializer