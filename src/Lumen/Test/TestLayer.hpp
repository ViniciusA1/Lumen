#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class TestLayer : public Layer
{
public:
    TestLayer();
    ~TestLayer() override = default;

    void OnUpdate() override;
    void OnDraw() override;

private:
    Ref<Scene> m_TestScene;
};

} // namespace Lumen