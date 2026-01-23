#include "Lumen/Layer/GameLayer.hpp"
#include "Lumen/World/SceneManager.hpp"

namespace Lumen
{

GameLayer::GameLayer()
    : Layer("GameLayer", true), m_Scene(SceneManager::GetActiveSceneRef())
{
}

void GameLayer::OnUpdate()
{
    if (m_Scene == nullptr)
        return;

    // m_Scene->OnUpdate();
}

void GameLayer::OnDraw()
{
    if (m_Scene == nullptr)
        return;

    // m_Scene->OnDraw();
}

} // namespace Lumen