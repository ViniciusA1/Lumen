#include "Lumen/Scene/Entity/System/System.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

System::System(World &world) : m_ParentWorld(world)
{
}

entt::registry &System::GetRegistry()
{
    return m_ParentWorld.GetEntityManager().GetRegistry();
}

} // namespace Lumen