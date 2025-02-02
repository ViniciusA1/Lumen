#pragma once

#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class Scene3D : public Scene
{
public:
    Scene3D();
    Scene3D(UUID uuid, std::string name, Path path);

    void OnUpdate() override;

private:
};

} // namespace Lumen