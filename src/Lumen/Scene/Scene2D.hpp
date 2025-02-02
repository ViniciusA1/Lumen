#pragma once

#include "Lumen/Physics2D/World2D.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class Scene2D : public Scene
{
public:
    Scene2D();
    Scene2D(UUID uuid, std::string name, Path path);

    [[nodiscard]] const World2D &GetPhysicsWorld() const;
    World2D &GetPhysicsWorld();

    void OnUpdate() override;

private:
    World2D m_PhysicsWorld;
};

} // namespace Lumen