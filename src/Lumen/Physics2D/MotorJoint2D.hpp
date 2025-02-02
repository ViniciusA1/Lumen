#pragma once

#include "Lumen/Physics2D/Joint2D.hpp"

namespace Lumen
{

class MotorJoint2D : public Joint2D
{
public:
    MotorJoint2D(const b2JointId &jointID);

    [[nodiscard]] float GetAngularOffset() const;
    [[nodiscard]] float GetCorrectionFactor() const;
    [[nodiscard]] Vector2 GetLinearOffset() const;
    [[nodiscard]] float GetMaxForce() const;
    [[nodiscard]] float GetMaxTorque() const;

    void SetAngularOffset(float angularOffset);
    void SetCorrectionFactor(float correctionFactor);
    void SetLinearOffset(const Vector2 &linearOffset);
    void SetMaxForce(float maxForce);
    void SetMaxTorque(float maxTorque);
};

} // namespace Lumen