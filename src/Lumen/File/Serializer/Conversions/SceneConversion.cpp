#include "Lumen/File/Serializer/Conversions/SceneConversion.hpp"

#include "Lumen/File/Serializer/Conversions/CoreConversion.hpp"
#include "Lumen/File/Serializer/Conversions/GraphicsConversion.hpp"
#include "Lumen/File/Serializer/Conversions/MathConversion.hpp"
#include "yaml-cpp/exceptions.h"

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

template <> Yaml Serialize(const ParentComponent &parent)
{
    Yaml yaml;
    yaml["Parent"] << parent.ParentID;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ParentComponent &parent)
{
    yaml["Parent"] >> parent.ParentID;
}

template <> Yaml Serialize(const ChildrenComponent &children)
{
    Yaml yaml, childrenYaml;

    for (const auto &childrenID : children.ChildrenID)
        childrenYaml.PushBack((uint64_t)childrenID);

    yaml["Children"] = childrenYaml;

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ChildrenComponent &children)
{
    const Yaml &childrenYaml = yaml["Children"];

    if (childrenYaml.IsNull())
        throw YAML::Exception({}, "");

    for (const auto &childrenIDYaml : childrenYaml)
    {
        UUID id;
        childrenIDYaml >> id;
        children.ChildrenID.push_back(id);
    }
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
    cameraYaml["Fov"] << camera.Fov;
    cameraYaml["Projection"] << static_cast<int>(camera.Projection);
    yaml["Camera"] = cameraYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, CameraComponent &camera)
{
    const Yaml &cameraYaml = yaml["Camera"];
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

template <> Yaml Serialize(const UIComponentBase &base)
{
    Yaml yaml, colorsYaml;
    yaml["State"] << static_cast<int>(base.State);
    colorsYaml["Idle"] << base.Colors[0];
    colorsYaml["Hovered"] << base.Colors[1];
    colorsYaml["Pressed"] << base.Colors[2];
    colorsYaml["Disabled"] << base.Colors[3];
    yaml["Colors"] = colorsYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, UIComponentBase &base)
{
    const Yaml &colorsYaml = yaml["Colors"];
    int stateInt;
    yaml["State"] >> stateInt;
    base.State = static_cast<UIComponentState>(stateInt);
    colorsYaml["Idle"] >> base.Colors[0];
    colorsYaml["Hovered"] >> base.Colors[1];
    colorsYaml["Pressed"] >> base.Colors[2];
    colorsYaml["Disabled"] >> base.Colors[3];
}

template <> Yaml Serialize(const ButtonComponent &button)
{
    Yaml yaml, buttonYaml;
    buttonYaml = Serialize(static_cast<const UIComponentBase &>(button));
    buttonYaml << button.Label;
    buttonYaml["Texture"] << button.Texture;
    yaml["Button"] = buttonYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ButtonComponent &button)
{
    const Yaml &buttonYaml = yaml["Button"];
    Deserialize(buttonYaml, static_cast<UIComponentBase &>(button));
    buttonYaml >> button.Label;
    buttonYaml["Texture"] >> button.Texture;
}

template <> Yaml Serialize(const CanvasComponent &canvas)
{
    Yaml yaml, canvasYaml;
    canvasYaml["Mode"] << static_cast<int>(canvas.Mode);
    canvasYaml["Camera"] << canvas.CameraID;
    canvasYaml["ScaleFactor"] << canvas.ScaleFactor;
    canvasYaml["SortOrder"] << canvas.SortingOrder;
    yaml["Canvas"] = canvasYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, CanvasComponent &canvas)
{
    const Yaml &canvasYaml = yaml["Canvas"];
    int modeInt;
    canvasYaml["Mode"] >> modeInt;
    canvas.Mode = static_cast<CanvasRenderMode>(modeInt);
    canvasYaml["Camera"] >> canvas.CameraID;
    canvasYaml["ScaleFactor"] >> canvas.ScaleFactor;
    canvasYaml["SortOrder"] >> canvas.SortingOrder;
}

template <> Yaml Serialize(const CheckboxComponent &checkbox)
{
    Yaml yaml, checkboxYaml;
    checkboxYaml = Serialize(static_cast<const UIComponentBase &>(checkbox));
    checkboxYaml["Value"] << checkbox.Value;
    yaml["Checkbox"] = checkboxYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, CheckboxComponent &checkbox)
{
    const Yaml &checkboxYaml = yaml["Checkbox"];
    Deserialize(checkboxYaml, static_cast<UIComponentBase &>(checkbox));
    checkboxYaml["Value"] >> checkbox.Value;
}

template <> Yaml Serialize(const DropdownComponent &dropdown)
{
    Yaml yaml, dropdownYaml;
    dropdownYaml = Serialize(static_cast<const UIComponentBase &>(dropdown));
    dropdownYaml << dropdown.Options;
    dropdownYaml["SelectedIndex"] << dropdown.SelectedIndex;
    dropdownYaml["IsExpanded"] << dropdown.IsExpanded;
    dropdownYaml["MaxVisibleItems"] << dropdown.MaxVisibleItems;
    yaml["Dropdown"] = dropdownYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, DropdownComponent &dropdown)
{
    const Yaml &dropdownYaml = yaml["Dropdown"];
    Deserialize(dropdownYaml, static_cast<UIComponentBase &>(dropdown));
    dropdownYaml >> dropdown.Options;
    dropdownYaml["SelectedIndex"] >> dropdown.SelectedIndex;
    dropdownYaml["IsExpanded"] >> dropdown.IsExpanded;
    dropdownYaml["MaxVisibleItems"] >> dropdown.MaxVisibleItems;
}

template <> Yaml Serialize(const ImageComponent &image)
{
    Yaml yaml, imageYaml;
    imageYaml = Serialize(static_cast<const UIComponentBase &>(image));
    imageYaml["Texture"] << image.Texture;
    yaml["Image"] = imageYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ImageComponent &image)
{
    const Yaml &imageYaml = yaml["Image"];
    Deserialize(imageYaml, static_cast<UIComponentBase &>(image));
    imageYaml["Texture"] >> image.Texture;
}

template <> Yaml Serialize(const InputFieldComponent &inputField)
{
    Yaml yaml, inputFieldYaml;
    inputFieldYaml = Serialize(static_cast<const UIComponentBase &>(inputField));
    inputFieldYaml << inputField.Text;
    yaml["InputField"] = inputFieldYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, InputFieldComponent &inputField)
{
    const Yaml &inputFieldYaml = yaml["InputField"];
    Deserialize(inputFieldYaml, static_cast<UIComponentBase &>(inputField));
    inputFieldYaml >> inputField.Text;
}

template <> Yaml Serialize(const LabelComponent &label)
{
    Yaml yaml, labelYaml;
    labelYaml = Serialize(static_cast<const UIComponentBase &>(label));
    labelYaml["Text"] << label.Text;
    labelYaml["Font"] << label.Font;
    labelYaml["FontSize"] << label.FontSize;
    yaml["Label"] = labelYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, LabelComponent &label)
{
    const Yaml &labelYaml = yaml["Label"];
    Deserialize(labelYaml, static_cast<UIComponentBase &>(label));
    labelYaml["Text"] >> label.Text;
    labelYaml["Font"] >> label.Font;
    labelYaml["FontSize"] >> label.FontSize;
}

template <> Yaml Serialize(const ProgressBarComponent &progressBar)
{
    Yaml yaml, progressBarYaml;
    progressBarYaml = Serialize(static_cast<const UIComponentBase &>(progressBar));
    progressBarYaml["MaxValue"] << progressBar.MaxValue;
    progressBarYaml["Value"] << progressBar.Value;
    progressBarYaml["BackgroundColor"] << progressBar.BackgroundColor;
    yaml["ProgressBar"] = progressBarYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ProgressBarComponent &progressBar)
{
    const Yaml &progressBarYaml = yaml["ProgressBar"];
    Deserialize(progressBarYaml, static_cast<UIComponentBase &>(progressBar));
    progressBarYaml["MaxValue"] >> progressBar.MaxValue;
    progressBarYaml["Value"] >> progressBar.Value;
    progressBarYaml["BackgroundColor"] >> progressBar.BackgroundColor;
}

template <> Yaml Serialize(const SliderComponent &slider)
{
    Yaml yaml, sliderYaml;
    sliderYaml = Serialize(static_cast<const UIComponentBase &>(slider));
    sliderYaml["MinValue"] << slider.MinValue;
    sliderYaml["MaxValue"] << slider.MaxValue;
    sliderYaml["Value"] << slider.Value;
    yaml["Slider"] = sliderYaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, SliderComponent &slider)
{
    const Yaml &sliderYaml = yaml["Slider"];
    Deserialize(sliderYaml, static_cast<UIComponentBase &>(slider));
    sliderYaml["MinValue"] >> slider.MinValue;
    sliderYaml["MaxValue"] >> slider.MaxValue;
    sliderYaml["Value"] >> slider.Value;
}

} // namespace Lumen::YamlSerializer