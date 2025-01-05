#include "Lumen/Scene/Serializer/SceneSerializer.hpp"
#include "Lumen/Scene/Serializer/SerializerConversions.hpp"

#include <fstream>

namespace Lumen
{

static void DeserializeEntity(EntityManager &manager, const YAML::Node &node);
static void SerializeEntity(EntityManager &manager, Entity entity, YAML::Node &node);

SceneSerializer::SceneSerializer(const Ref<Scene> &scene) : m_Scene(scene)
{
}

bool SceneSerializer::Deserialize(const Path &path)
{
    try
    {
        YAML::Node data = YAML::LoadFile(path.String());
        auto sceneNode = data["Scene"];

        m_Scene->m_Name = sceneNode["Name"].as<std::string>();
        m_Scene->m_ID = sceneNode["UUID"].as<UUID>();
        m_Scene->m_State = static_cast<SceneState>(sceneNode["State"].as<int>());

        auto worldNode = sceneNode["World"];

        auto &world = m_Scene->GetWorld();
        auto &entityManager = world.GetEntityManager();

        for (const auto &entityNode : worldNode["Entities"])
        {
            DeserializeEntity(entityManager, entityNode);
        }

        UUID mainCameraID = sceneNode["MainCamera"].as<UUID>();
        Entity mainCamera = entityManager.GetEntity(mainCameraID);
        m_Scene->m_MainCamera = mainCamera;

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

bool SceneSerializer::Serialize(const Path &path)
{
    try
    {
        YAML::Node sceneNode;
        sceneNode["Name"] = m_Scene->m_Name;
        sceneNode["UUID"] = (uint64_t)m_Scene->m_ID;
        sceneNode["State"] = static_cast<int>(m_Scene->m_State);

        sceneNode["MainCamera"] =
            (uint64_t)m_Scene->m_World.GetEntityManager()
                .GetComponent<IDComponent>(m_Scene->GetMainCameraEntity())
                .ID;

        YAML::Node worldNode;
        auto &world = m_Scene->GetWorld();

        YAML::Node entitiesNode = YAML::Node(YAML::NodeType::Sequence);
        auto &entityManager = world.GetEntityManager();

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

        YAML::Node rootNode;
        rootNode["Scene"] = sceneNode;

        std::ofstream file(path.String());
        file << YAML::Dump(rootNode);
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

static void DeserializeEntity(EntityManager &manager, const YAML::Node &node)
{
}

static void SerializeEntity(EntityManager &manager, Entity entity, YAML::Node &node)
{
}

} // namespace Lumen