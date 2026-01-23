#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"
#include "Lumen/World/Entity/Entity.hpp"
#include "Lumen/World/Scene.hpp"


namespace Lumen
{

static void RegisterChildrenComponent();
static void RegisterIDComponent();
static void RegisterNameComponent();
static void RegisterParentComponent();
static void RegisterTagComponent();
static void RegisterTransformComponent();

static void RegisterCameraComponent();
static void RegisterLightComponent();
static void RegisterMeshRendererComponent();
static void RegisterModelRendererComponent();
static void RegisterSpriteRendererComponent();

static void RegisterEntity();
static void RegisterEntityManager();
static void RegisterEntityQuery();

static void RegisterDrawSystem();
static void RegisterUpdateSystem();
static void RegisterSystem();

static void RegisterScene();
static void RegisterSceneManager();
static void RegisterWorld();

void RegisterSceneAPI()
{
    RegisterTransformComponent();

    RegisterEntity();
    RegisterEntityManager();
    RegisterEntityQuery();

    RegisterDrawSystem();
    RegisterUpdateSystem();
    RegisterSystem();

    RegisterScene();
    RegisterSceneManager();
    RegisterWorld();
}

static void RegisterTransformComponent()
{
    ScriptEngine::GetInstance()
        ->RegisterType<TransformComponent>("TransformComponent")
        .Constructors<TransformComponent()>()
        .Property("position", &TransformComponent::Position)
        .Property("rotation", &TransformComponent::Rotation)
        .Property("scale", &TransformComponent::Scale);
}

static void RegisterEntity()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Entity>("Entity")
        .Constructors<Entity()>()
        .Method("is_valid", &Entity::operator bool)
        .OperatorEq([](const Entity &a, const Entity &b) { return a == b; });
}

static void RegisterEntityManager()
{
}

static void RegisterEntityQuery()
{
}

static void RegisterDrawSystem()
{
}

static void RegisterUpdateSystem()
{
}

static void RegisterSystem()
{
}

static void RegisterScene()
{
}

static void RegisterSceneManager()
{
}

static void RegisterWorld()
{
    ScriptEngine::GetInstance()->RegisterType<World>("World");
}

} // namespace Lumen