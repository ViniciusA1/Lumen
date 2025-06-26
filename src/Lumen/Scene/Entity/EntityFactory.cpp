#include "Lumen/Scene/Entity/EntityFactory.hpp"

namespace Lumen
{

Entity EntityFactory::CreateEmpty(EntityManager &manager)
{
    Entity entity = manager.CreateEntity();
    return entity;
}

Entity EntityFactory::CreateCamera(EntityManager &manager)
{
    Entity entity = manager.CreateEntity("Camera");
    manager.AddComponent<CameraComponent>(entity);
    return entity;
}

Entity EntityFactory::CreateSprite(EntityManager &manager)
{
    Entity entity = manager.CreateEntity("Sprite");
    manager.AddComponent<SpriteRendererComponent>(entity);
    return entity;
}

Entity EntityFactory::CreateButton(EntityManager &manager)
{
    Entity entity = manager.CreateEntity("Button");
    manager.AddComponent<ButtonComponent>(entity);
    return entity;
}

Entity EntityFactory::CreateLabel(EntityManager &manager)
{
    Entity entity = manager.CreateEntity("Label");
    manager.AddComponent<LabelComponent>(entity);
    return entity;
}

Entity EntityFactory::CreateAudioSource(EntityManager &manager)
{
    Entity entity = manager.CreateEntity("Audio Source");
    manager.AddComponent<AudioSourceComponent>(entity);
    return entity;
}

} // namespace Lumen