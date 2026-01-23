#pragma once

#include "Lumen/Script/ScriptObject.hpp"
#include "Lumen/World/System/UpdateSystem.hpp"


namespace Lumen
{

class ScriptUpdateSystem : public UpdateSystem
{
public:
    ScriptUpdateSystem(World &world, ScriptObject object, std::string name);

    void OnCreate() final;
    void OnDestroy() final;

    void OnEnable() final;
    void OnDisable() final;

    void OnUpdate() final;

private:
    ScriptObject m_SystemObject;
};

} // namespace Lumen