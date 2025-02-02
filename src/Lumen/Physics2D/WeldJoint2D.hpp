#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class WeldJoint2D : Joint2D
{
public:
    WeldJoint2D(const b2JointId &jointID);

    [[nodiscard]] float GetAngularDampingRatio() const;
    [[nodiscard]] float GetAngularHertz() const;
    [[nodiscard]] float GetLinearDampingRatio() const;
    [[nodiscard]] float GetLinearHertz() const;

    void SetAngularDampingRatio(float ratio);
    void SetAngularHertz(float hertz);
    void SetLinearDampingRatio(float ratio);
    void SetLinearHertz(float hertz);
};

} // namespace Lumen