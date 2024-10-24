#pragma once

namespace Lumen
{

class World;

class System
{
public:
    System(World &world) : m_ParentWorld(world) {}

    virtual void OnCreate() {};
    virtual void OnDestroy() {};
    virtual void OnUpdate() {};

protected:
    World &m_ParentWorld;
};

} // namespace Lumen