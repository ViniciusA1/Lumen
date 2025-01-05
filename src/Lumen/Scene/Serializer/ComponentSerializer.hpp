#pragma once

#include "Lumen/Scene/Entity/Component/Component.hpp"

#include "yaml-cpp/yaml.h"

namespace Lumen
{

template <typename Component>
void DeserializeComponent(const YAML::Node &node, Component &component);
template <typename Component>
void SerializeComponent(YAML::Node &node, const Component &component);

// Core
template <> void DeserializeComponent(const YAML::Node &node, IDComponent &id);
template <> void DeserializeComponent(const YAML::Node &node, TagComponent &tag);
template <>
void DeserializeComponent(const YAML::Node &node, TransformComponent &transform);
template <> void SerializeComponent(YAML::Node &node, const IDComponent &id);
template <> void SerializeComponent(YAML::Node &node, const TagComponent &tag);
template <>
void SerializeComponent(YAML::Node &node, const TransformComponent &transform);

// Graphics
template <> void DeserializeComponent(const YAML::Node &node, CameraComponent &camera);
template <>
void DeserializeComponent(const YAML::Node &node, SpriteRendererComponent &spriteRender);
template <> void SerializeComponent(YAML::Node &node, const CameraComponent &camera);
template <>
void SerializeComponent(YAML::Node &node, const SpriteRendererComponent &spriteRender);

// Physics
template <>
void DeserializeComponent(const YAML::Node &node, VelocityComponent &velocity);
template <> void SerializeComponent(YAML::Node &node, const VelocityComponent &velocity);

} // namespace Lumen