#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class SceneManager
{
public:
    static Ref<Scene> CreateScene(const std::string &name);
    static void LoadScene(const std::string &name);
    static void UnloadScene(const std::string &name);

    static void SetActiveScene(const std::string &name);

    static Ref<Scene> GetActiveScene();
    static Ref<Scene> GetScene(const std::string &name);
    static Ref<Scene> GetSceneAt(int index);

private:
    static Ref<Scene> m_ActiveScene;
    static std::unordered_map<std::string, Ref<Scene>> m_LoadedScene;
};

} // namespace Lumen