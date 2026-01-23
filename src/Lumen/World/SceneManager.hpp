#pragma once

#include "Lumen/Memory/Memory.hpp"
#include "Lumen/World/Scene.hpp"

namespace Lumen
{

class SceneManager
{
public:
    static Ref<Scene> CreateScene(const Path &path, const std::string &name,
                                  SceneType type);
    static Ref<Scene> LoadScene(const Path &path);
    static void SaveScene(const Ref<Scene> &scene = s_ActiveScene);
    static void UnloadScene(UUID uuid);
    static void UnloadScene(const std::string &name);

    static void SetActiveScene(UUID uuid);
    static void SetActiveScene(const std::string &name);
    static void SetActiveScene(const Ref<Scene> &scene);

    [[nodiscard]] static Ref<Scene> GetActiveScene();
    [[nodiscard]] static Ref<Scene> &GetActiveSceneRef();

    [[nodiscard]] static Ref<Scene> GetScene(UUID uuid);
    [[nodiscard]] static Ref<Scene> GetScene(const std::string &name);
    [[nodiscard]] static Ref<Scene> GetSceneAt(int index);

private:
    static void AddDefaultEntities(const Ref<Scene> &scene);
    static void AddDefaultSystems(const Ref<Scene> &scene);

private:
    static Ref<Scene> s_ActiveScene;
    static std::unordered_map<UUID, Ref<Scene>> s_LoadedScene;
};

} // namespace Lumen