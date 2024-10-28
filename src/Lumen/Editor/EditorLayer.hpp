#pragma once

#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

class EditorLayer : public Layer
{
public:
    EditorLayer(std::string name = "Editor Layer", bool visible = true);
    ~EditorLayer() override = default;

    void OnUpdate() override;
    void OnDraw() override;

private:
};

} // namespace Lumen