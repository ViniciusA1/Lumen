#pragma once

#include "Lumen/Event/SceneEvent.hpp"
#include "Lumen/Scene/System/UpdateSystem.hpp"

namespace Lumen
{

class TransformUpdateSystem : public UpdateSystem
{
public:
    TransformUpdateSystem(World &world);

    void OnCreate() final;
    void OnUpdate() final;

private:
    void OnAddChild(const AddChildEvent &event);
    void OnRemoveChild(const RemoveChildEvent &event);
    void OnReparent(const ReparentEvent &event);
};

} // namespace Lumen