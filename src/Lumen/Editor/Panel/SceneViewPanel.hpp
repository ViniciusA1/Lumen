#pragma once

#include "Lumen/Scene/Scene.hpp"
namespace Lumen
{

class SceneViewPanel
{
public:
    SceneViewPanel() = default;

    void Draw(Scene &activeScene);
};

} // namespace Lumen