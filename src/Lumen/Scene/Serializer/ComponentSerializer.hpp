#pragma once

#include "Lumen/Scene/Entity/Component/Component.hpp"

#include "yaml-cpp/yaml.h"

namespace Lumen
{

template <typename Component>
bool DeserializeComponent(Component &component, const YAML::Node &node);
template <typename Component>
void SerializeComponent(const Component &component, YAML::Node &node);

// Core
template <> bool DeserializeComponent(IDComponent &id, const YAML::Node &node);
template <> bool DeserializeComponent(TagComponent &tag, const YAML::Node &node);
template <>
bool DeserializeComponent(TransformComponent &transform, const YAML::Node &node);
template <> void SerializeComponent(const IDComponent &id, YAML::Node &node);
template <> void SerializeComponent(const TagComponent &tag, YAML::Node &node);
template <>
void SerializeComponent(const TransformComponent &transform, YAML::Node &node);

// Graphics
template <> bool DeserializeComponent(CameraComponent &camera, const YAML::Node &node);
template <>
bool DeserializeComponent(SpriteRendererComponent &spriteRender, const YAML::Node &node);
template <> void SerializeComponent(const CameraComponent &camera, YAML::Node &node);
template <>
void SerializeComponent(const SpriteRendererComponent &spriteRender, YAML::Node &node);

// Physics
template <>
bool DeserializeComponent(VelocityComponent &velocity, const YAML::Node &node);
template <> void SerializeComponent(const VelocityComponent &velocity, YAML::Node &node);

} // namespace Lumen