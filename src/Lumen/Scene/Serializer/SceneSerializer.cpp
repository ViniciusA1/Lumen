#include "Lumen/Scene/Serializer/SceneSerializer.hpp"
#include "Lumen/Scene/Serializer/ComponentSerializer.hpp"
#include "Lumen/Scene/Serializer/SerializerConversions.hpp"

#include <fstream>

namespace Lumen
{

static void DeserializeEntity(EntityManager &manager, const YAML::Node &node);
static void SerializeEntity(EntityManager &manager, Entity entity, YAML::Node &node);

bool SceneSerializer::Deserialize(const Ref<Scene> &scene, const Path &path)
{
    try
    {
        YAML::Node sceneNode = YAML::LoadFile(path.String());

        scene->m_Path = path;
        scene->m_Name = sceneNode["Name"].as<std::string>();
        scene->m_ID = sceneNode["UUID"].as<UUID>();
        scene->m_State = static_cast<SceneState>(sceneNode["State"].as<int>());

        auto worldNode = sceneNode["World"];

        auto &world = scene->GetWorld();
        auto &entityManager = world.GetEntityManager();

        for (const auto &entityNode : worldNode["Entities"])
        {
            DeserializeEntity(entityManager, entityNode);
        }

        if (sceneNode["MainCamera"])
        {
            UUID mainCameraID = sceneNode["MainCamera"].as<UUID>();
            Entity mainCamera = entityManager.GetEntity(mainCameraID);
            scene->m_MainCamera = mainCamera;
        }

        for (const auto &systemNode : worldNode["Systems"])
        {
        }
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

bool SceneSerializer::Serialize(const Ref<Scene> &scene, const Path &path)
{
    try
    {
        YAML::Node sceneNode;
        sceneNode["Name"] = scene->m_Name;
        sceneNode["UUID"] = scene->m_ID;
        sceneNode["State"] = static_cast<int>(scene->m_State);

        auto &world = scene->GetWorld();
        auto &entityManager = world.GetEntityManager();

        Entity mainCamera = scene->GetMainCameraEntity();
        if (mainCamera && entityManager.HasComponent<CameraComponent>(mainCamera))
        {
            sceneNode["MainCamera"] =
                entityManager.GetComponent<IDComponent>(mainCamera).ID;
        }

        YAML::Node worldNode;

        YAML::Node entitiesNode = YAML::Node(YAML::NodeType::Sequence);

        for (const auto &entt : entityManager.GetRegistry().view<entt::entity>())
        {
            const Entity &entity = entityManager.GetEntity(entt);
            YAML::Node entityNode;
            SerializeEntity(entityManager, entity, entityNode);
            entitiesNode.push_back(entityNode);
        }
        worldNode["Entities"] = entitiesNode;

        YAML::Node systemsNode = YAML::Node(YAML::NodeType::Sequence);
        worldNode["Systems"] = systemsNode;

        sceneNode["World"] = worldNode;

        std::ofstream file(path.String());
        file << YAML::Dump(sceneNode);
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

static void DeserializeEntity(EntityManager &manager, const YAML::Node &node)
{
    IDComponent id;
    DeserializeComponent<IDComponent>(id, node);
    Entity entity = manager.CreateEntity(id.ID);

    AllComponentGroup::ForEachComponent([&]<typename Component>() {
        Component component;
        if (DeserializeComponent<Component>(component, node))
        {
            manager.AddComponent<Component>(entity) = component;
        }
    });
}

static void SerializeEntity(EntityManager &manager, Entity entity, YAML::Node &node)
{
    AllComponentGroup::ForEachComponent([&]<typename Component>() {
        if (manager.HasComponent<Component>(entity))
        {
            Component component = manager.GetComponent<Component>(entity);
            SerializeComponent<Component>(component, node);
        }
    });
}

} // namespace Lumen