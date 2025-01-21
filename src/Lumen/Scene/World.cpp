#include "Lumen/Scene/World.hpp"

namespace Lumen
{

World::World() : m_EntityManager(*this)
{
}

const EntityManager &World::GetEntityManager() const
{
    return m_EntityManager;
}

EntityManager &World::GetEntityManager()
{
    return m_EntityManager;
}

void World::Update()
{
    for (auto &[type, system] : m_SystemMap)
    {
        system->OnUpdate();
    }
}

} // namespace Lumen