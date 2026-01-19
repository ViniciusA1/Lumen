#include "Lumen/Application/EngineInitializer.hpp"
#include "Lumen/Application/ApplicationArgsSerializer.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Asset/AssetManagerSerializer.hpp"
#include "Lumen/Layer/GameLayer.hpp"
#include "Lumen/Log/Log.hpp"
#include "Lumen/Scene/Component/ComponentRegistry.hpp"
#include "Lumen/Scene/Entity/EntityFactory.hpp"
#include "Lumen/Scene/SceneManager.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

EngineInitializer::EngineInitializer(Application &app) : m_App(app)
{
}

void EngineInitializer::Run()
{
    InitArgs();
    InitLogging();
    InitWindow();
    InitAssets();
    InitScript();
    InitScenes();
    InitComponents();
    InitSystems();
    InitPrefabs();
    InitLayers();
}

void EngineInitializer::InitArgs()
{
    ApplicationArgsSerializer().Deserialize(m_App.m_Args, "config/ApplicationArgs.lproj");
}

void EngineInitializer::InitLogging()
{
    Log::Init();
}

void EngineInitializer::InitWindow()
{
    m_App.m_Window = Window(WindowArgs{
        .Title = m_App.m_Args.Title,
        .Resolution = m_App.m_Args.Resolution,
        .Icon = m_App.m_Args.Icon,
        .Flags = m_App.m_Args.Flags,
        .TargetFPS = m_App.m_Args.TargetFPS,
    });
}

void EngineInitializer::InitAssets()
{
    AssetManager::SetWorkingDirectory(m_App.m_Args.AssetDirectory);
    AssetManager::LoadDefaultAssets();
    AssetManagerSerializer().Deserialize("config/AssetRegistry.lproj");
}

void EngineInitializer::InitScript()
{
    ScriptEngine::Init(ScriptBackendType::Lua);
    RegisterAllAPI();
}

void EngineInitializer::InitScenes()
{
    SceneManager::SetWorkingDirectory(m_App.m_Args.SceneDirectory);
    Ref<Scene> startScene = SceneManager::LoadScene(m_App.m_Args.StartScene);
    SceneManager::SetActiveScene(startScene);
}

void EngineInitializer::InitComponents()
{
    ComponentRegistry::Register<AudioListenerComponent>("AudioListener", "Audio")
        .Data<&AudioListenerComponent::IsEnabled>("IsEnabled");

    ComponentRegistry::Register<AudioSourceComponent>("AudioSource", "Audio")
        .Data<&AudioSourceComponent::Type>("Type")
        .Data<&AudioSourceComponent::Audio>("Audio");

    ComponentRegistry::Register<UntaggedComponent>("Untagged", "Tag")
        .Data<&UntaggedComponent::Name>("Name");

    ComponentRegistry::Register<EnemyTagComponent>("Enemy", "Tag")
        .Data<&EnemyTagComponent::Name>("Name");

    ComponentRegistry::Register<MainCameraTagComponent>("MainCamera", "Tag")
        .Data<&MainCameraTagComponent::Name>("Name");

    ComponentRegistry::Register<PlayerTagComponent>("Player", "Tag")
        .Data<&PlayerTagComponent::Name>("Name");

    ComponentRegistry::Register<IDComponent>("ID", "Core").Data<&IDComponent::ID>("ID");

    ComponentRegistry::Register<NameComponent>("Name", "Core")
        .Data<&NameComponent::Name>("Name");

    ComponentRegistry::Register<ParentComponent>("Parent", "Core")
        .Data<&ParentComponent::ParentID>("ID");

    ComponentRegistry::Register<ChildrenComponent>("Children", "Core")
        .Data<&ChildrenComponent::ChildrenID>("ID");

    ComponentRegistry::Register<TransformComponent>("Transform", "Core")
        .Data<&TransformComponent::Position>("Position")
        .Data<&TransformComponent::Rotation>("Rotation")
        .Data<&TransformComponent::Scale>("Scale");

    ComponentRegistry::Register<CameraComponent>("Camera", "Graphics")
        .Data<&CameraComponent::Position>("Position")
        .Data<&CameraComponent::Target>("Target")
        .Data<&CameraComponent::Up>("Up")
        .Data<&CameraComponent::Fov>("Fov")
        .Data<&CameraComponent::OrthographicSize>("OrthographicSize")
        .Data<&CameraComponent::Near>("Near")
        .Data<&CameraComponent::Far>("Far")
        .Data<&CameraComponent::AspectRatio>("AspectRatio")
        .Data<&CameraComponent::Projection>("Projection");

    ComponentRegistry::Register<MeshRendererComponent>("MeshRenderer", "Graphics")
        .Data<&MeshRendererComponent::Mesh>("Mesh")
        .Data<&MeshRendererComponent::Material>("Material");

    ComponentRegistry::Register<ModelRendererComponent>("ModelRenderer", "Graphics")
        .Data<&ModelRendererComponent::Model>("Model");

    ComponentRegistry::Register<SpriteRendererComponent>("SpriteRenderer", "Graphics")
        .Data<&SpriteRendererComponent::Color>("Color")
        .Data<&SpriteRendererComponent::Texture>("Texture");

    ComponentRegistry::Register<VelocityComponent>("Velocity", "Physics")
        .Data<&VelocityComponent::Velocity>("Velocity");

    ComponentRegistry::Register<ButtonComponent>("Button", "UI")
        .Data<&ButtonComponent::State>("State")
        .Data<&ButtonComponent::Colors>("Colors");

    ComponentRegistry::Register<CanvasComponent>("Canvas", "UI")
        .Data<&CanvasComponent::Mode>("Mode")
        .Data<&CanvasComponent::CameraID>("Camera")
        .Data<&CanvasComponent::ScaleFactor>("ScaleFactor")
        .Data<&CanvasComponent::SortingOrder>("SortingOrder");

    ComponentRegistry::Register<CheckboxComponent>("Checkbox", "UI")
        .Data<&CheckboxComponent::State>("State")
        .Data<&CheckboxComponent::Colors>("Colors")
        .Data<&CheckboxComponent::Value>("Value");

    ComponentRegistry::Register<DropdownComponent>("Dropdown", "UI")
        .Data<&DropdownComponent::State>("State")
        .Data<&DropdownComponent::Colors>("Colors");

    ComponentRegistry::Register<ImageComponent>("Image", "UI")
        .Data<&ImageComponent::State>("State")
        .Data<&ImageComponent::Colors>("Colors")
        .Data<&ImageComponent::Texture>("Texture")
        .Data<&ImageComponent::UV>("UV");

    ComponentRegistry::Register<InputFieldComponent>("InputField", "UI")
        .Data<&InputFieldComponent::State>("State")
        .Data<&InputFieldComponent::Colors>("Colors")
        .Data<&InputFieldComponent::Text>("Text");

    ComponentRegistry::Register<LabelComponent>("Label", "UI")
        .Data<&LabelComponent::State>("State")
        .Data<&LabelComponent::Colors>("Colors")
        .Data<&LabelComponent::Text>("Text")
        .Data<&LabelComponent::Font>("Font")
        .Data<&LabelComponent::FontSize>("FontSize");

    ComponentRegistry::Register<ProgressBarComponent>("ProgressBar", "UI")
        .Data<&ProgressBarComponent::State>("State")
        .Data<&ProgressBarComponent::Colors>("Colors")
        .Data<&ProgressBarComponent::MaxValue>("MaxValue")
        .Data<&ProgressBarComponent::Value>("Value")
        .Data<&ProgressBarComponent::BackgroundColor>("BackgroundColor");

    ComponentRegistry::Register<SliderComponent>("Slider", "UI")
        .Data<&SliderComponent::State>("State")
        .Data<&SliderComponent::Colors>("Colors")
        .Data<&SliderComponent::MinValue>("MinValue")
        .Data<&SliderComponent::MaxValue>("MaxValue")
        .Data<&SliderComponent::Value>("Value");
}

void EngineInitializer::InitSystems()
{
}

void EngineInitializer::InitPrefabs()
{
    EntityFactory::RegisterDefaultCreators();
}

void EngineInitializer::InitLayers()
{
    m_App.m_LayerStack.PushLayer(CreateRef<GameLayer>());
}

} // namespace Lumen