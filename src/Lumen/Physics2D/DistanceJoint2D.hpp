#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class DistanceJoint2D : public Joint2D
{
public:
    DistanceJoint2D(const b2JointId &jointID);

    [[nodiscard]] bool IsLimitEnabled() const;
    [[nodiscard]] bool IsMotorEnabled() const;
    [[nodiscard]] bool IsSpringEnabled() const;

    [[nodiscard]] float GetCurrentLength() const;
    [[nodiscard]] float GetLength() const;
    [[nodiscard]] float GetMinLength() const;
    [[nodiscard]] float GetMaxLength() const;
    [[nodiscard]] float GetMaxMotorForce() const;
    [[nodiscard]] float GetMotorSpeed() const;
    [[nodiscard]] float GetMotorForce() const;

    void SetLength(float length);
    void SetLengthRange(float minLength, float maxLength);
    void SetMaxMotorForce(float force);
    void SetMotorSpeed(float speed);
    void SetSpringDampingRatio(float ratio);
    void SetSpringHertz(float hertz);

    void EnableLimit(bool enable);
    void EnableMotor(bool enable);
    void EnableSpring(bool enable);
};

} // namespace Lumen