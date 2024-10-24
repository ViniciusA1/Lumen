#pragma once

#include "Lumen/Scene/World.hpp"
#include <entt/entity/registry.hpp>

namespace Lumen
{

class Scene
{
public:
    Scene() = default;

    inline World &GetWorld();
    [[nodiscard]] inline bool IsRunning() const;
    inline void SetRunning(bool running);

    void OnUpdate();

private:
    World m_World;
    bool m_IsRunning = false;
};

World &Scene::GetWorld()
{
    return m_World;
}

bool Scene::IsRunning() const
{
    return m_IsRunning;
}

void Scene::SetRunning(bool running)
{
    m_IsRunning = running;
}

} // namespace Lumen