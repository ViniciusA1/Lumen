#include "Lumen/File/Serializer/Conversions/SceneConversion.hpp"

#include "Lumen/File/Serializer/Conversions/CoreConversion.hpp"
#include "Lumen/File/Serializer/Conversions/GraphicsConversion.hpp"
#include "Lumen/File/Serializer/Conversions/MathConversion.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Ref<Scene> &scene)
{
    Yaml sceneNode;

    sceneNode["Name"] << scene->GetName();
    sceneNode["UUID"] << scene->GetID();
    sceneNode["State"] << static_cast<int>(scene->GetState());

    auto &world = scene->GetWorld();
    auto &entityManager = world.GetEntityManager();

    Entity mainCamera = scene->GetMainCameraEntity();
    if (mainCamera && entityManager.HasComponent<CameraComponent>(mainCamera))
    {
        sceneNode["MainCamera"] << entityManager.GetComponent<IDComponent>(mainCamera);
    }

    sceneNode["World"] << world;

    return sceneNode;
}

template <> void Deserialize(const Yaml &yaml, Ref<Scene> &scene)
{
    std::string name = scene->GetName();
    UUID uuid = scene->GetID();
    int state = static_cast<int>(scene->GetState());
    yaml["Name"] >> name;
    yaml["UUID"] >> uuid;
    yaml["State"] >> state;
    scene->SetName(name);
    scene->SetID(uuid);
    scene->SetState(static_cast<SceneState>(state));

    auto &world = scene->GetWorld();
    auto &entityManager = world.GetEntityManager();

    yaml["World"] >> world;

    if (yaml.Contains("MainCamera"))
    {
        UUID mainCameraID;
        yaml["MainCamera"] >> mainCameraID;
        Entity mainCamera = entityManager.GetEntity(mainCameraID);
        scene->SetMainCamera(mainCamera);
    }
}

template <> Yaml Serialize(const World &world)
{
    Yaml worldNode;

    worldNode["Entities"] << world.GetEntityManager();

    YAML::Node systemsNode = YAML::Node(YAML::NodeType::Sequence);
    worldNode["Systems"] = systemsNode;

    return worldNode;
}

template <> void Deserialize(const Yaml &yaml, World &world)
{
    yaml["Entities"] >> world.GetEntityManager();
}

template <> Yaml Serialize(const EntityManager &manager)
{
    Yaml entitiesNode = YAML::Node(YAML::NodeType::Sequence);

    for (const auto &entt : manager.GetRegistry().view<entt::entity>())
    {
        Entity entity = manager.GetEntity(entt);
        Yaml entityNode;
        AllComponentGroup::ForEachComponent([&]<typename Component>() {
            if (manager.HasComponent<Component>(entity))
            {
                Component component = manager.GetComponent<Component>(entity);
                entityNode << component;
            }
        });
        entitiesNode.PushBack(entityNode);
    }

    return entitiesNode;
}

template <> void Deserialize(const Yaml &yaml, EntityManager &manager)
{
    for (const Yaml node : yaml)
    {
        IDComponent id;
        node >> id;
        Entity entity = manager.CreateEntity(id.ID);

        AllComponentGroup::ForEachComponent([&]<typename Component>() {
            Component component;
            try
            {
                node >> component;
                manager.AddComponent<Component>(entity) = component;
            }
            catch (std::exception e)
            {
            }
        });
    }
}

template <> Yaml Serialize(const IDComponent &id)
{
    Yaml yaml;
    yaml["ID"] << id.ID;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, IDComponent &id)
{
    yaml["ID"] >> id.ID;
}

template <> Yaml Serialize(const NameComponent &name)
{
    Yaml yaml;
    yaml["Name"] << name.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, NameComponent &name)
{
    yaml["Name"] >> name.Name;
}

template <> Yaml Serialize(const TagComponent &tag)
{
    Yaml yaml;
    yaml["Tag"] << tag.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, TagComponent &tag)
{
    yaml["Tag"] >> tag.Name;
}

template <> Yaml Serialize(const TransformComponent &transform)
{
    Yaml yaml, transformYaml;
    transformYaml["Position"] << transform.Position;
    transformYaml["Rotation"] << transform.Rotation;
    transformYaml["Scale"] << transform.Scale;
    yaml["Transform"] = transformYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, TransformComponent &transform)
{
    const Yaml &transformYaml = yaml["Transform"];
    transformYaml["Position"] >> transform.Position;
    transformYaml["Rotation"] >> transform.Rotation;
    transformYaml["Scale"] >> transform.Scale;
}

template <> Yaml Serialize(const CameraComponent &camera)
{
    Yaml yaml, cameraYaml;
    cameraYaml["Position"] << camera.Position;
    cameraYaml["Target"] << camera.Target;
    cameraYaml["Up"] << camera.Up;
    cameraYaml["Fov"] << camera.Fov;
    cameraYaml["Projection"] << static_cast<int>(camera.Projection);
    yaml["Camera"] = cameraYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, CameraComponent &camera)
{
    const Yaml &cameraYaml = yaml["Camera"];
    cameraYaml["Position"] >> camera.Position;
    cameraYaml["Target"] >> camera.Target;
    cameraYaml["Up"] >> camera.Up;
    cameraYaml["Fov"] >> camera.Fov;
    int projection;
    cameraYaml["Projection"] >> projection;
    camera.Projection = static_cast<ProjectionType>(projection);
}

template <> Yaml Serialize(const SpriteRendererComponent &spriteRenderer)
{
    Yaml yaml, spriteYaml;
    spriteYaml["Color"] << spriteRenderer.Color;
    // yaml["Texture"] << spriteRenderer.Texture;
    yaml["SpriteRenderer"] = spriteYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, SpriteRendererComponent &spriteRenderer)
{
    const Yaml &spriteYaml = yaml["SpriteRenderer"];
    spriteYaml["Color"] >> spriteRenderer.Color;
}

template <> Yaml Serialize(const VelocityComponent &velocity)
{
    Yaml yaml;
    yaml["Velocity"] << velocity.Velocity;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, VelocityComponent &velocity)
{
    yaml["Velocity"] >> velocity.Velocity;
}

} // namespace Lumen::YamlSerializer