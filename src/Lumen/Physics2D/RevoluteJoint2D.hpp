#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class RevoluteJoint2D : Joint2D
{
public:
    RevoluteJoint2D(const b2JointId &jointID);

    [[nodiscard]] bool IsLimitEnabled() const;
    [[nodiscard]] bool IsMotorEnabled() const;

    [[nodiscard]] float GetAngle() const;
    [[nodiscard]] float GetLowerLimit() const;
    [[nodiscard]] float GetUpperLimit() const;
    [[nodiscard]] float GetMaxMotorTorque() const;
    [[nodiscard]] float GetMotorSpeed() const;
    [[nodiscard]] float GetMotorTorque() const;
    [[nodiscard]] float GetSpringDampingRatio() const;
    [[nodiscard]] float GetSpringHertz() const;

    void SetLimits(float lower, float upper);
    void SetMaxMotorTorque(float maxTorque);
    void SetMotorSpeed(float speed);
    void SetSpringDampingRatio(float ratio);
    void SetSpringHertz(float hertz);

    void EnableLimit(bool enable);
    void EnableMotor(bool enable);
    void EnableSpring(bool enable);
};

} // namespace Lumen