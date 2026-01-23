#include "Lumen/World/System/Script/ScriptUpdateSystem.hpp"
#include "Lumen/World/World.hpp"

namespace Lumen
{

ScriptUpdateSystem::ScriptUpdateSystem(World &world, ScriptObject object,
                                       std::string name)
    : UpdateSystem(world, std::move(name)), m_SystemObject(std::move(object))
{
    object.Set("world", &world);
}

void ScriptUpdateSystem::OnCreate()
{
    if (m_SystemObject.IsValid())
        m_SystemObject.Call("on_create");
}

void ScriptUpdateSystem::OnDestroy()
{
    if (m_SystemObject.IsValid())
        m_SystemObject.Call("on_destroy");

    m_SystemObject.Clear();
}

void ScriptUpdateSystem::OnEnable()
{
    if (m_SystemObject.IsValid())
        m_SystemObject.Call("on_enable");
}

void ScriptUpdateSystem::OnDisable()
{
    if (m_SystemObject.IsValid())
        m_SystemObject.Call("on_disable");
}

void ScriptUpdateSystem::OnUpdate()
{
    if (m_SystemObject.IsValid())
        m_SystemObject.Call("on_update");
}

} // namespace Lumen