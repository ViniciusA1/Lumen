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

enum class SceneType
{
    Type2D,
    Type3D
};

class Scene
{
public:
    Scene();
    Scene(UUID uuid, std::string name, Path path, SceneType type);

    [[nodiscard]] UUID GetID() const;
    CameraComponent &GetMainCamera();
    [[nodiscard]] Entity GetMainCameraEntity() const;
    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] Path GetPath() const;
    [[nodiscard]] SceneState GetState() const;
    [[nodiscard]] SceneType GetType() const;
    World &GetWorld();

    void SetID(UUID uuid);
    void SetName(const std::string &name);
    void SetMainCamera(Entity camera);
    void SetPath(const Path &path);
    void SetState(SceneState state);

    virtual void OnUpdate() = 0;

protected:
    void BindEvents();
    template <typename T> void BindComponentEvent();
    template <typename T> void OnComponentAdded(const ComponentAddEvent<T> &event);
    template <typename T> void OnComponentRemoved(const ComponentRemoveEvent<T> &event);

protected:
    Path m_Path;
    UUID m_ID;
    std::string m_Name;
    SceneState m_State;
    SceneType m_Type;
    Entity m_MainCamera;
    World m_World;
};

} // namespace Lumen