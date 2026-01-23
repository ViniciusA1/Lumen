#pragma once

#include "Lumen/Layer/Layer.hpp"
#include "Lumen/World/Scene.hpp"

namespace Lumen
{

class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer() override = default;

    void OnUpdate() override;
    void OnDraw() override;

protected:
    Ref<Scene> &m_Scene;
};

} // namespace Lumen