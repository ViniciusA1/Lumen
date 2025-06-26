#pragma once

#include "Lumen/Scene/Entity/EntityManager.hpp"

namespace Lumen
{

class EntityFactory
{
public:
    EntityFactory() = delete;

public:
    static Entity CreateEmpty(EntityManager &manager);

    static Entity CreateCamera(EntityManager &manager);

    static Entity CreateSprite(EntityManager &manager);

    static Entity CreateButton(EntityManager &manager);
    static Entity CreateLabel(EntityManager &manager);

    static Entity CreateAudioSource(EntityManager &manager);
};

} // namespace Lumen