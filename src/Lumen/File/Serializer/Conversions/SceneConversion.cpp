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
    sceneNode["Type"] << static_cast<int>(scene->GetType());

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
    {
        std::string name;
        UUID uuid;
        int state, type;
        yaml["Name"] >> name;
        yaml["UUID"] >> uuid;
        yaml["State"] >> state;
        yaml["Type"] >> type;
        scene->SetName(name);
        scene->SetID(uuid);
        scene->SetState(static_cast<SceneState>(state));
    }

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
            catch (YAML::Exception e)
            {
            }
        });
    }
}

template <> Yaml Serialize(const SceneType &type)
{
    Yaml yaml;
    yaml << static_cast<int>(type);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, SceneType &type)
{
    int typeInt;
    yaml >> typeInt;
    type = static_cast<SceneType>(typeInt);
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

template <> Yaml Serialize(const UntaggedComponent &tag)
{
    Yaml yaml;
    yaml["Untagged"] << tag.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, UntaggedComponent &tag)
{
    yaml["Untagged"] >> tag.Name;
}

template <> Yaml Serialize(const EnemyTagComponent &tag)
{
    Yaml yaml;
    yaml["EnemyTag"] << tag.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, EnemyTagComponent &tag)
{
    yaml["EnemyTag"] >> tag.Name;
}

template <> Yaml Serialize(const MainCameraTagComponent &tag)
{
    Yaml yaml;
    yaml["MainCameraTag"] << tag.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, MainCameraTagComponent &tag)
{
    yaml["MainCameraTag"] >> tag.Name;
}

template <> Yaml Serialize(const PlayerTagComponent &tag)
{
    Yaml yaml;
    yaml["PlayerTag"] << tag.Name;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, PlayerTagComponent &tag)
{
    yaml["PlayerTag"] >> tag.Name;
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

template <> Yaml Serialize(const AudioListenerComponent &audioListener)
{
    Yaml yaml, audioListenerYaml;
    yaml["AudioListener"] = audioListenerYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, AudioListenerComponent &audioListener)
{
    const Yaml &audioListenerYaml = yaml["AudioListener"];
    audioListenerYaml >> audioListener;
}

template <> Yaml Serialize(const AudioSourceComponent &audioSource)
{
    Yaml yaml, audioSourceYaml;
    audioSourceYaml["Audio"] << audioSource.Audio;
    yaml["AudioSource"] = audioSourceYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, AudioSourceComponent &audioSource)
{
    const Yaml &audioSourceYaml = yaml["AudioSource"];
    audioSourceYaml["Audio"] >> audioSource.Audio;
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

template <> Yaml Serialize(const MeshRendererComponent &mesh)
{
    Yaml yaml, meshYaml;
    meshYaml["Mesh"] << mesh.Mesh;
    yaml["MeshRenderer"] = meshYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, MeshRendererComponent &mesh)
{
    const Yaml &meshYaml = yaml["MeshRenderer"];
    meshYaml["Mesh"] >> mesh.Mesh;
}

template <> Yaml Serialize(const ModelRendererComponent &model)
{
    Yaml yaml, modelYaml;
    modelYaml["Model"] << model.Model;
    yaml["ModelRenderer"] = modelYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ModelRendererComponent &model)
{
    const Yaml &modelYaml = yaml["ModelRenderer"];
    modelYaml["Model"] >> model.Model;
}

template <> Yaml Serialize(const SpriteRendererComponent &sprite)
{
    Yaml yaml, spriteYaml;
    spriteYaml["Color"] << sprite.Color;
    spriteYaml["Texture"] << sprite.Texture;
    yaml["Sprite"] = spriteYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, SpriteRendererComponent &sprite)
{
    const Yaml &spriteYaml = yaml["Sprite"];
    spriteYaml["Color"] >> sprite.Color;
    spriteYaml["Texture"] >> sprite.Texture;
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

template <> Yaml Serialize(const UIComponentState &state)
{
    Yaml yaml;
    yaml << static_cast<int>(state);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, UIComponentState &state)
{
    int stateInt;
    yaml >> stateInt;
    state = static_cast<UIComponentState>(stateInt);
}

template <> Yaml Serialize(const std::array<Lumen::Color, 4> &colors)
{
    Yaml yaml, colorsYaml;

    colorsYaml["Idle"] << colors[0];
    colorsYaml["Hovered"] << colors[1];
    colorsYaml["Pressed"] << colors[2];
    colorsYaml["Disabled"] << colors[3];

    yaml["Colors"] = colorsYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, std::array<Lumen::Color, 4> &colors)
{
    const Yaml &colorsYaml = yaml["Colors"];
    colorsYaml["Idle"] >> colors[0];
    colorsYaml["Hovered"] >> colors[1];
    colorsYaml["Pressed"] >> colors[2];
    colorsYaml["Disabled"] >> colors[3];
}

template <> Yaml Serialize(const ButtonComponent &button)
{
    Yaml yaml, buttonYaml;
    buttonYaml["State"] << button.State;
    buttonYaml << button.Colors;
    buttonYaml << button.Label;
    buttonYaml["Texture"] << button.Texture;
    yaml["Button"] = buttonYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ButtonComponent &button)
{
    const Yaml &buttonYaml = yaml["Button"];
    buttonYaml["State"] >> button.State;
    buttonYaml >> button.Colors;
    buttonYaml >> button.Label;
    buttonYaml["Texture"] >> button.Texture;
}

template <> Yaml Serialize(const LabelComponent &label)
{
    Yaml yaml, labelYaml;
    labelYaml["State"] << label.State;
    labelYaml << label.Colors;
    labelYaml["Text"] << label.Text;
    labelYaml["Font"] << label.Font;
    labelYaml["FontSize"] << label.FontSize;
    yaml["Label"] = labelYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, LabelComponent &label)
{
    const Yaml &labelYaml = yaml["Label"];
    labelYaml["State"] >> label.State;
    labelYaml >> label.Colors;
    labelYaml["Text"] >> label.Text;
    labelYaml["Font"] >> label.Font;
    labelYaml["FontSize"] >> label.FontSize;
}

} // namespace Lumen::YamlSerializer