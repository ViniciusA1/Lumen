#pragma once

#include "Lumen/Event/SceneEvent.hpp"
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
    Scene();
    Scene(Path path, UUID uuid, std::string name);

    [[nodiscard]] UUID GetID() const;
    CameraComponent &GetMainCamera();
    [[nodiscard]] Entity GetMainCameraEntity() const;
    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] Path GetPath() const;
    [[nodiscard]] SceneState GetState() const;
    World &GetWorld();

    void SetID(UUID uuid);
    void SetName(const std::string &name);
    void SetMainCamera(Entity camera);
    void SetPath(const Path &path);
    void SetState(SceneState state);

    void OnUpdate();

private:
    void OnComponentRemoved(const ComponentRemoveEvent<CameraComponent> &event);

private:
    Path m_Path;
    UUID m_ID;
    std::string m_Name;
    SceneState m_State;
    Entity m_MainCamera;

    World m_World;
};

} // namespace Lumen