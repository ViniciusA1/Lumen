#pragma once

#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

class TestLayer : public Layer
{
public:
    TestLayer();
    ~TestLayer() override = default;

    void OnUpdate() override;
    void OnDraw() override;
};

} // namespace Lumen