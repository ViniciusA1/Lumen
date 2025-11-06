#include "Lumen/Scene/SceneManager.hpp"
#include "Lumen/Scene/SceneSerializer.hpp"
#include "Lumen/Scene/System/Core/TransformUpdateSystem.hpp"
#include "Lumen/Scene/System/Graphics/ModelRendererSystem.hpp"
#include "Lumen/Scene/System/Graphics/SpriteRendererSystem.hpp"

namespace Lumen
{

Path SceneManager::s_WorkingDirectory = "assets/Scene";
Ref<Scene> SceneManager::s_ActiveScene;
std::unordered_map<UUID, Ref<Scene>> SceneManager::s_LoadedScene;

Ref<Scene> SceneManager::CreateScene(const Path &path, const std::string &name,
                                     SceneType type)
{
    Ref<Scene> newScene = CreateRef<Scene>(UUID(), name, s_WorkingDirectory / path, type);
    AddDefaultEntities(newScene);
    AddDefaultSystems(newScene);
    return newScene;
}

Ref<Scene> SceneManager::LoadScene(const Path &path)
{
    Ref<Scene> loadedScene = CreateRef<Scene>(SceneType::Type3D);
    AddDefaultEntities(loadedScene);
    AddDefaultSystems(loadedScene);

    SceneSerializer serializer;
    if (serializer.Deserialize(loadedScene, s_WorkingDirectory / path))
        s_LoadedScene[loadedScene->GetID()] = loadedScene;
    else
        loadedScene = nullptr;

    return loadedScene;
}

void SceneManager::SaveScene(const Ref<Scene> &scene)
{
    if (scene == nullptr)
        return;

    SceneSerializer serializer;
    serializer.Serialize(scene, scene->GetPath());
}

void SceneManager::UnloadScene(UUID uuid)
{
    auto it = s_LoadedScene.find(uuid);
    if (it == s_LoadedScene.end())
        return;

    SaveScene(it->second);
    s_LoadedScene.erase(it);
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
        s_ActiveScene = it->second;
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

void SceneManager::SetActiveScene(const Ref<Scene> &scene)
{
    if (scene == nullptr)
        return;

    s_ActiveScene = scene;
}

void SceneManager::SetWorkingDirectory(const Path &path)
{
    s_WorkingDirectory = path;
}

Ref<Scene> SceneManager::GetActiveScene()
{
    return s_ActiveScene;
}

Ref<Scene> &SceneManager::GetActiveSceneRef()
{
    return s_ActiveScene;
}

Ref<Scene> SceneManager::GetScene(UUID uuid)
{
    auto it = s_LoadedScene.find(uuid);
    if (it == s_LoadedScene.end())
        return nullptr;

    return it->second;
}

Ref<Scene> SceneManager::GetScene(const std::string &name)
{
    for (const auto &[uuid, scene] : s_LoadedScene)
    {
        if (scene->GetName() == name)
            return scene;
    }

    return nullptr;
}

Ref<Scene> SceneManager::GetSceneAt(int index)
{
    if (index >= s_LoadedScene.size())
        return nullptr;

    auto it = s_LoadedScene.begin();
    std::advance(it, index);
    return it->second;
}

Path SceneManager::GetWorkingDirectory()
{
    return s_WorkingDirectory;
}

void SceneManager::AddDefaultEntities(const Ref<Scene> &scene)
{
}

void SceneManager::AddDefaultSystems(const Ref<Scene> &scene)
{
    World &world = scene->GetWorld();

    world.AddSystem<TransformUpdateSystem>();

    world.AddSystem<ModelRendererSystem>();
    world.AddSystem<SpriteRendererSystem>();
}

} // namespace Lumen