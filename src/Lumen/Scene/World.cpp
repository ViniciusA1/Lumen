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

void World::OnUpdate()
{
    for (auto &system : m_UpdateSystemList)
    {
        system->OnUpdate();
    }
}

void World::OnDraw()
{
    for (auto &system : m_DrawSystemList)
    {
        system->OnDraw();
    }
}

} // namespace Lumen