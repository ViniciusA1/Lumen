#include "Lumen/Scene/SceneManager.hpp"
#include "Lumen/Scene/SceneFactory.hpp"
#include "Lumen/Scene/Serializer/SceneSerializer.hpp"

namespace Lumen
{

Ref<Scene> SceneManager::s_ActiveScene;
std::unordered_map<UUID, Ref<Scene>> SceneManager::s_LoadedScene;

void SceneManager::CreateScene(const Path &path, const std::string &name, SceneType type)
{
    Ref<Scene> newScene = SceneFactory::CreateScene(type, UUID(), path, name);
    SaveScene(newScene);
}

void SceneManager::LoadScene(const Path &path, SceneType type)
{
    Ref<Scene> loadedScene = SceneFactory::CreateScene(type);
    SceneSerializer serializer;
    if (serializer.Deserialize(loadedScene, path))
    {
        s_LoadedScene[loadedScene->GetID()] = std::move(loadedScene);
    }
}

void SceneManager::SaveScene(const Ref<Scene> &scene)
{
    if (scene == nullptr)
        return;

    SceneSerializer serializer;
    if (serializer.Serialize(scene, scene->GetPath()))
    {
    }
}

void SceneManager::UnloadScene(UUID uuid)
{
    auto it = s_LoadedScene.find(uuid);
    if (it != s_LoadedScene.end())
    {
        SaveScene(it->second);
        s_LoadedScene.erase(it);
    }
}

void SceneManager::UnloadScene(const std::string &name)
{
    for (const auto &[uuid, scene] : s_LoadedScene)
    {
        if (scene->GetName() == name)
        {
            SaveScene(scene);
            s_LoadedScene.erase(uuid);
            break;
        }
    }
}

void SceneManager::SetActiveScene(UUID uuid)
{
    auto it = s_LoadedScene.find(uuid);
    if (it != s_LoadedScene.end())
    {
        s_ActiveScene = it->second;
    }
}

void SceneManager::SetActiveScene(const std::string &name)
{
    for (const auto &[uuid, scene] : s_LoadedScene)
    {
        if (scene->GetName() == name)
        {
            SetActiveScene(uuid);
            break;
        }
    }
}

Ref<Scene> SceneManager::GetActiveScene()
{
    return s_ActiveScene;
}

Ref<Scene> SceneManager::GetScene(UUID uuid)
{
    auto it = s_LoadedScene.find(uuid);

    if (it != s_LoadedScene.end())
    {
        return it->second;
    }

    return nullptr;
}

Ref<Scene> SceneManager::GetScene(const std::string &name)
{
    for (const auto &[uuid, scene] : s_LoadedScene)
    {
        if (scene->GetName() == name)
        {
            return scene;
        }
    }

    return nullptr;
}

Ref<Scene> SceneManager::GetSceneAt(int index)
{
    if (index >= s_LoadedScene.size())
    {
        return nullptr;
    }

    auto it = s_LoadedScene.begin();
    std::advance(it, index);
    return it->second;
}

} // namespace Lumen