#include "Lumen/World/System/System.hpp"
#include "Lumen/World/World.hpp"

namespace Lumen
{

System::System(World &world, std::string name)
    : m_Name(std::move(name)), m_ParentWorld(world)
{
}

bool System::IsEnabled() const
{
    return m_IsEnabled;
}

void System::SetEnable(bool enable)
{
    bool oldState = m_IsEnabled;
    m_IsEnabled = enable;

    if (!oldState && enable)
        OnEnable();
    else if (oldState && !enable)
        OnDisable();
}

entt::registry &System::GetRegistry()
{
    return m_ParentWorld.GetEntityManager().GetRegistry();
}

} // namespace Lumen