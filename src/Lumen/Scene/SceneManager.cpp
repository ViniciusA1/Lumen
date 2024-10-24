#include "Lumen/Scene/SceneManager.hpp"
#include <iterator>

namespace Lumen
{

Ref<Scene> SceneManager::m_ActiveScene;
std::unordered_map<std::string, Ref<Scene>> SceneManager::m_LoadedScene;

Ref<Scene> SceneManager::CreateScene(const std::string &name)
{
    auto it = m_LoadedScene.find(name);

    if (it != m_LoadedScene.end())
    {
        return nullptr;
    }

    Ref<Scene> newScene = CreateRef<Scene>();
    m_LoadedScene[name] = newScene;
    return newScene;
}

void SceneManager::LoadScene(const std::string &name)
{
}

void SceneManager::UnloadScene(const std::string &name)
{
}

void SceneManager::SetActiveScene(const std::string &name)
{
    auto it = m_LoadedScene.find(name);
    if (it != m_LoadedScene.end())
    {
        m_ActiveScene = it->second;
    }
}

Ref<Scene> SceneManager::GetActiveScene()
{
    return m_ActiveScene;
}

Ref<Scene> SceneManager::GetScene(const std::string &name)
{
    auto it = m_LoadedScene.find(name);

    if (it != m_LoadedScene.end())
    {
        return it->second;
    }

    return nullptr;
}

Ref<Scene> SceneManager::GetSceneAt(int index)
{
    if (index >= m_LoadedScene.size())
    {
        return nullptr;
    }

    auto it = m_LoadedScene.begin();
    std::advance(it, index);
    return it->second;
}

} // namespace Lumen