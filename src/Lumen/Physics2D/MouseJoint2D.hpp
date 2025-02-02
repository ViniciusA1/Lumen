#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class MouseJoint2D : public Joint2D
{
public:
    MouseJoint2D(const b2JointId &jointID);

    [[nodiscard]] float GetMaxForce() const;
    [[nodiscard]] float GetSpringDampingRatio() const;
    [[nodiscard]] float GetSpringHertz() const;
    [[nodiscard]] Vector2 GetTarget() const;

    void SetMaxForce(float maxForce);
    void SetSpringDampingRatio(float ratio);
    void SetSpringHertz(float hertz);
    void SetTarget(const Vector2 &target);
};

} // namespace Lumen