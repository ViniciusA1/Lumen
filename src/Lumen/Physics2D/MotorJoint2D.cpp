#include "Lumen/Physics2D/MotorJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

MotorJoint2D::MotorJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

float MotorJoint2D::GetAngularOffset() const
{
    return b2MotorJoint_GetAngularOffset(m_JointID);
}

float MotorJoint2D::GetCorrectionFactor() const
{
    return b2MotorJoint_GetCorrectionFactor(m_JointID);
}

Vector2 MotorJoint2D::GetLinearOffset() const
{
    return b2MotorJoint_GetLinearOffset(m_JointID);
}

float MotorJoint2D::GetMaxForce() const
{
    return b2MotorJoint_GetMaxForce(m_JointID);
}

float MotorJoint2D::GetMaxTorque() const
{
    return b2MotorJoint_GetMaxTorque(m_JointID);
}

void MotorJoint2D::SetAngularOffset(float angularOffset)
{
    b2MotorJoint_SetAngularOffset(m_JointID, angularOffset);
}

void MotorJoint2D::SetCorrectionFactor(float correctionFactor)
{
    b2MotorJoint_SetCorrectionFactor(m_JointID, correctionFactor);
}

void MotorJoint2D::SetLinearOffset(const Vector2 &linearOffset)
{
    b2MotorJoint_SetLinearOffset(m_JointID, linearOffset);
}

void MotorJoint2D::SetMaxForce(float maxForce)
{
    b2MotorJoint_SetMaxForce(m_JointID, maxForce);
}

void MotorJoint2D::SetMaxTorque(float maxTorque)
{
    b2MotorJoint_SetMaxTorque(m_JointID, maxTorque);
}

} // namespace Lumen