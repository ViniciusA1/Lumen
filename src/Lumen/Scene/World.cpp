#include "Lumen/Scene/World.hpp"

namespace Lumen
{

World::World() : m_EntityManager(*this)
{
}

void World::Update()
{
    for (auto &[type, system] : m_SystemMap)
    {
        system->OnUpdate();
    }
}

} // namespace Lumen