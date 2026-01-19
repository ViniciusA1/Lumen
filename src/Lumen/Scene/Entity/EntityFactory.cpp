#include "Lumen/Scene/Entity/EntityFactory.hpp"

namespace Lumen
{

std::unordered_map<std::string, EntityFactory::Creator> EntityFactory::s_Registry;

void EntityFactory::Register(const std::string &name, const Creator &creator)
{
    s_Registry[name] = creator;
}

Entity EntityFactory::Create(const std::string &name, EntityManager &manager)
{
    auto it = s_Registry.find(name);
    if (it == s_Registry.end())
        return {};

    return it->second(manager)[0];
}

void EntityFactory::RegisterDefaultCreators()
{
    Register("Empty",
             [](EntityManager &manager) { return Entity(manager.CreateEntity()); });

    Register("Camera", [](EntityManager &manager) {
        Entity entity = manager.CreateEntity("Camera");
        manager.AddComponent<CameraComponent>(entity);
        return entity;
    });

    Register("Sprite", [](EntityManager &manager) {
        Entity entity = manager.CreateEntity("Sprite");
        manager.AddComponent<SpriteRendererComponent>(entity);
        return entity;
    });

    Register("Button", [](EntityManager &manager) {
        Entity entity = manager.CreateEntity("Button");
        manager.AddComponent<ButtonComponent>(entity);
        return entity;
    });

    Register("Label", [](EntityManager &manager) {
        Entity entity = manager.CreateEntity("Label");
        manager.AddComponent<LabelComponent>(entity);
        return entity;
    });

    Register("Audio Source", [](EntityManager &manager) {
        Entity entity = manager.CreateEntity("Audio Source");
        manager.AddComponent<AudioSourceComponent>(entity);
        return entity;
    });
}

} // namespace Lumen