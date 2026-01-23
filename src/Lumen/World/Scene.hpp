#pragma once

#include "Lumen/Event/SceneEvent.hpp"
#include "Lumen/File/Path.hpp"
#include "Lumen/World/SceneState.hpp"
#include "Lumen/World/SceneType.hpp"
#include "Lumen/World/World.hpp"

#include <entt/entity/registry.hpp>

namespace Lumen
{

class Scene
{
public:
    Scene(SceneType type);
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
    void SetPath(const Path &path);
    void SetState(SceneState state);

    void OnUpdate();
    void OnDraw(bool withCamera = true);

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
    World m_World;
};

} // namespace Lumen