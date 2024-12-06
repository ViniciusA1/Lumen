#pragma once

#include "Lumen/Scene/World.hpp"
#include <entt/entity/registry.hpp>

namespace Lumen
{

enum class SceneState
{
    Edit,
    Play,
    Pause
};

class Scene
{
public:
    Scene() = default;

    CameraComponent &GetMainCamera();
    [[nodiscard]] SceneState GetState() const;
    World &GetWorld();

    void SetMainCamera(Entity camera);
    void SetState(SceneState state);

    void OnUpdate();

private:
    SceneState m_State;
    World m_World;
    Entity m_MainCamera;
};

} // namespace Lumen