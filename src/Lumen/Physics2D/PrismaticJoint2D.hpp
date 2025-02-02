#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class PrismaticJoint2D : public Joint2D
{
public:
    PrismaticJoint2D(const b2JointId &jointID);

    [[nodiscard]] bool IsLimitEnabled() const;
    [[nodiscard]] bool IsMotorEnabled() const;
    [[nodiscard]] bool IsSpringEnabled() const;

    [[nodiscard]] float GetLowerLimit() const;
    [[nodiscard]] float GetUpperLimit() const;
    [[nodiscard]] float GetMaxMotorForce() const;
    [[nodiscard]] float GetMotorForce() const;
    [[nodiscard]] float GetMotorSpeed() const;
    [[nodiscard]] float GetSpringDampingRatio() const;
    [[nodiscard]] float GetSpringHertz() const;

    void SetLimits(float lower, float upper);
    void SetMaxMotorForce(float maxForce);
    void SetMotorSpeed(float speed);
    void SetSpringDampingRatio(float ratio);
    void SetSpringHertz(float hertz);

    void EnableLimit(bool enable);
    void EnableMotor(bool enable);
    void EnableSpring(bool enable);
};

} // namespace Lumen