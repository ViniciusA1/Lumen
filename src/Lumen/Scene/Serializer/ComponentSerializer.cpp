#include "Lumen/Scene/Serializer/ComponentSerializer.hpp"
#include "Lumen/Scene/Serializer/SerializerConversions.hpp"

namespace Lumen
{

template <> void DeserializeComponent(const YAML::Node &node, IDComponent &id)
{
    id.ID = node["ID"].as<UUID>();
}

template <> void DeserializeComponent(const YAML::Node &node, TagComponent &tag)
{
    tag.Tag = node["Tag"].as<std::string>();
}

template <>
void DeserializeComponent(const YAML::Node &node, TransformComponent &transform)
{
    const YAML::Node &transformNode = node["Transform"];
    transform.Position = transformNode["Position"].as<Vector3>();
    transform.Rotation = transformNode["Rotation"].as<Vector3>();
    transform.Scale = transformNode["Scale"].as<Vector3>();
}

template <> void SerializeComponent(YAML::Node &node, const IDComponent &id)
{
    node["ID"] = id.ID;
}

template <> void SerializeComponent(YAML::Node &node, const TagComponent &tag)
{
    node["Tag"] = tag.Tag;
}

template <> void SerializeComponent(YAML::Node &node, const TransformComponent &transform)
{
    YAML::Node transformNode;
    transformNode["Position"] = transform.Position;
    transformNode["Rotation"] = transform.Rotation;
    transformNode["Scale"] = transform.Scale;
    node["Transform"] = transformNode;
}

template <> void DeserializeComponent(const YAML::Node &node, CameraComponent &camera)
{
}

template <>
void DeserializeComponent(const YAML::Node &node, SpriteRendererComponent &spriteRender)
{
}

template <> void SerializeComponent(YAML::Node &node, const CameraComponent &camera)
{
}

template <>
void SerializeComponent(YAML::Node &node, const SpriteRendererComponent &spriteRender)
{
}

template <> void DeserializeComponent(const YAML::Node &node, VelocityComponent &velocity)
{
}

template <> void SerializeComponent(YAML::Node &node, const VelocityComponent &velocity)
{
}

} // namespace Lumen