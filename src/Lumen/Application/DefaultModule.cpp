#include "Lumen/Application/DefaultModule.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Log/Log.hpp"
#include "Lumen/Script/ScriptEngine.hpp"
#include "Lumen/Serialization/Json.hpp"
#include "Lumen/UI/Module/LUIContext.hpp"
#include "Lumen/World/Component/ComponentRegistry.hpp"

#define COMPONENT_TYPE(TYPE, CATEGORY)                                                   \
    {                                                                                    \
        using __Comp = TYPE;                                                             \
        ComponentRegistry::Register<TYPE>(#TYPE, CATEGORY)

#define COMPONENT_DATA(FIELD) .Data<&__Comp::FIELD>(#FIELD)

#define COMPONENT_END                                                                    \
    ;                                                                                    \
    }

namespace Lumen
{

DefaultModule::DefaultModule(Application &app, ApplicationArgs args)
    : EngineModule(app), m_ExternalArgs(std::move(args))
{
}

void DefaultModule::Build()
{
    InitArgs();
    InitLogging();
    InitWindow();
    InitAssets();
    InitScript();
    InitScenes();
    InitComponents();
    InitSystems();
}

void DefaultModule::InitArgs()
{
    if (m_ExternalArgs.IsValid())
        m_App.GetArgs() = m_ExternalArgs;
    else
        Json::FromFile("config/ApplicationArgs.json", m_App.GetArgs());
}

void DefaultModule::InitLogging()
{
    Log::Init();
}

void DefaultModule::InitWindow()
{
    const ApplicationArgs &args = m_App.GetArgs();
    m_App.GetWindow() = Window(WindowArgs{
        .Title = args.Title,
        .Resolution = args.Resolution,
        .Icon = args.Icon,
        .Flags = args.Flags,
        .TargetFPS = args.TargetFPS,
    });
}

void DefaultModule::InitAssets()
{
    AssetManager::Init(m_App.GetArgs().RootDirectory / m_App.GetArgs().AssetDirectory);
}

void DefaultModule::InitScript()
{
    ScriptEngine::Init(ScriptBackendType::Lua);
}

void DefaultModule::InitScenes()
{
}

void DefaultModule::InitComponents()
{
    COMPONENT_TYPE(AudioListenerComponent, "Audio")
    COMPONENT_DATA(IsEnabled)
    COMPONENT_END

    COMPONENT_TYPE(AudioSourceComponent, "Audio")
    COMPONENT_DATA(Type)
    COMPONENT_DATA(Audio)
    COMPONENT_END

    COMPONENT_TYPE(UntaggedComponent, "Tag")
    COMPONENT_DATA(Name)
    COMPONENT_END

    COMPONENT_TYPE(EnemyTagComponent, "Tag")
    COMPONENT_DATA(Name)
    COMPONENT_END

    COMPONENT_TYPE(MainCameraTagComponent, "Tag")
    COMPONENT_DATA(Name)
    COMPONENT_END

    COMPONENT_TYPE(PlayerTagComponent, "Tag")
    COMPONENT_DATA(Name)
    COMPONENT_END

    COMPONENT_TYPE(IDComponent, "Core")
    COMPONENT_DATA(ID)
    COMPONENT_END

    COMPONENT_TYPE(NameComponent, "Core")
    COMPONENT_DATA(Name)
    COMPONENT_END

    COMPONENT_TYPE(ParentComponent, "Core")
    COMPONENT_DATA(ParentID)
    COMPONENT_END

    COMPONENT_TYPE(ChildrenComponent, "Core")
    COMPONENT_DATA(ChildrenID)
    COMPONENT_END

    COMPONENT_TYPE(TransformComponent, "Core")
    COMPONENT_DATA(Position)
    COMPONENT_DATA(Rotation)
    COMPONENT_DATA(Scale)
    COMPONENT_END

    COMPONENT_TYPE(CameraComponent, "Graphics")
    COMPONENT_DATA(Fov)
    COMPONENT_DATA(OrthographicSize)
    COMPONENT_DATA(Near)
    COMPONENT_DATA(Far)
    COMPONENT_DATA(Projection)
    COMPONENT_END

    COMPONENT_TYPE(MeshRendererComponent, "Graphics")
    COMPONENT_DATA(Mesh)
    COMPONENT_DATA(Material)
    COMPONENT_END

    COMPONENT_TYPE(SpriteRendererComponent, "Graphics")
    COMPONENT_DATA(Color)
    COMPONENT_DATA(Texture)
    COMPONENT_END
}

void DefaultModule::InitSystems()
{
}

void DefaultModule::InitLUI()
{
    LUI::Init();
    LUI::SetConfigFlags(LUI::ConfigFlags::DockingEnable);
}

} // namespace Lumen