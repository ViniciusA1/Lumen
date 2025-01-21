#include "Lumen/Scene/Serializer/ComponentSerializer.hpp"
#include "Lumen/Scene/Serializer/SerializerConversions.hpp"

namespace Lumen
{

template <> bool DeserializeComponent(IDComponent &id, const YAML::Node &node)
{
    if (!node["ID"])
        return false;

    id.ID = node["ID"].as<UUID>();
    return true;
}

template <> bool DeserializeComponent(NameComponent &name, const YAML::Node &node)
{
    if (!node["Name"])
        return false;

    name.Name = node["Name"].as<std::string>();
    return true;
}

template <> bool DeserializeComponent(TagComponent &tag, const YAML::Node &node)
{
    if (!node["Tag"])
        return false;

    tag.Name = node["Tag"].as<std::string>();
    return true;
}

template <>
bool DeserializeComponent(TransformComponent &transform, const YAML::Node &node)
{
    if (!node["Transform"])
        return false;

    const YAML::Node &transformNode = node["Transform"];
    transform.Position = transformNode["Position"].as<Vector3>();
    transform.Rotation = transformNode["Rotation"].as<Vector3>();
    transform.Scale = transformNode["Scale"].as<Vector3>();
    return true;
}

template <> void SerializeComponent(const IDComponent &id, YAML::Node &node)
{
    node["ID"] = id.ID;
}

template <> void SerializeComponent(const NameComponent &name, YAML::Node &node)
{
    node["Name"] = name.Name;
}

template <> void SerializeComponent(const TagComponent &tag, YAML::Node &node)
{
    node["Tag"] = tag.Name;
}

template <> void SerializeComponent(const TransformComponent &transform, YAML::Node &node)
{
    YAML::Node transformNode;
    transformNode["Position"] = transform.Position;
    transformNode["Rotation"] = transform.Rotation;
    transformNode["Scale"] = transform.Scale;
    node["Transform"] = transformNode;
}

template <> bool DeserializeComponent(CameraComponent &camera, const YAML::Node &node)
{
    if (!node["Camera"])
        return false;

    const YAML::Node &cameraNode = node["Camera"];
    camera.Position = cameraNode["Position"].as<Vector3>();
    camera.Target = cameraNode["Target"].as<Vector3>();
    camera.Up = cameraNode["Up"].as<Vector3>();
    camera.Fov = cameraNode["Fov"].as<float>();
    camera.Projection = static_cast<ProjectionType>(cameraNode["Projection"].as<int>());
    return true;
}

template <>
bool DeserializeComponent(SpriteRendererComponent &spriteRender, const YAML::Node &node)
{
    if (!node["SpriteRenderer"])
        return false;

    const YAML::Node &spriteNode = node["SpriteRenderer"];
    spriteRender.Color = spriteNode["Color"].as<Color>();
    //  spriteRender.Texture = spriteNode["Texture"].as<Texture2D>();
    return true;
}

template <> void SerializeComponent(const CameraComponent &camera, YAML::Node &node)
{
    YAML::Node cameraNode;
    cameraNode["Position"] = camera.Position;
    cameraNode["Target"] = camera.Target;
    cameraNode["Up"] = camera.Up;
    cameraNode["Fov"] = camera.Fov;
    cameraNode["Projection"] = static_cast<int>(camera.Projection);
    node["Camera"] = cameraNode;
}

template <>
void SerializeComponent(const SpriteRendererComponent &spriteRender, YAML::Node &node)
{
    YAML::Node spriteNode;
    spriteNode["Color"] = spriteRender.Color;
    // spriteNode["Texture"] = spriteRender.Texture;
    node["SpriteRenderer"] = spriteNode;
}

template <> bool DeserializeComponent(VelocityComponent &velocity, const YAML::Node &node)
{
    if (!node["Velocity"])
        return false;

    velocity.Velocity = node["Velocity"].as<Vector3>();
    return true;
}

template <> void SerializeComponent(const VelocityComponent &velocity, YAML::Node &node)
{
    node["Velocity"] = velocity.Velocity;
}

} // namespace Lumen
