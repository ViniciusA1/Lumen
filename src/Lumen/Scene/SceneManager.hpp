#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class SceneManager
{
public:
    static void CreateScene(const Path &path, const std::string &name);
    static void LoadScene(const Path &path);
    static void SaveScene(const Ref<Scene> &scene = s_ActiveScene);
    static void UnloadScene(UUID uuid);
    static void UnloadScene(const std::string &name);

    static void SetActiveScene(UUID uuid);
    static void SetActiveScene(const std::string &name);

    static Ref<Scene> GetActiveScene();
    static Ref<Scene> GetScene(UUID uuid);
    static Ref<Scene> GetScene(const std::string &name);
    static Ref<Scene> GetSceneAt(int index);

private:
    static Ref<Scene> s_ActiveScene;
    static std::unordered_map<UUID, Ref<Scene>> s_LoadedScene;
};

} // namespace Lumen