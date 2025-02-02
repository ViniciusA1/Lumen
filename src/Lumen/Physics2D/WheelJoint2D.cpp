#include "Lumen/Physics2D/WheelJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

WheelJoint2D::WheelJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

void WheelJoint2D::EnableLimit(bool enable)
{
    b2WheelJoint_EnableLimit(m_JointID, enable);
}

void WheelJoint2D::EnableMotor(bool enable)
{
    b2WheelJoint_EnableMotor(m_JointID, enable);
}

void WheelJoint2D::EnableSpring(bool enable)
{
    b2WheelJoint_EnableSpring(m_JointID, enable);
}

bool WheelJoint2D::IsLimitEnabled() const
{
    return b2WheelJoint_IsLimitEnabled(m_JointID);
}

bool WheelJoint2D::IsMotorEnabled() const
{
    return b2WheelJoint_IsMotorEnabled(m_JointID);
}

bool WheelJoint2D::IsSpringEnabled() const
{
    return b2WheelJoint_IsSpringEnabled(m_JointID);
}

float WheelJoint2D::GetLowerLimit() const
{
    return b2WheelJoint_GetLowerLimit(m_JointID);
}

float WheelJoint2D::GetUpperLimit() const
{
    return b2WheelJoint_GetUpperLimit(m_JointID);
}

float WheelJoint2D::GetMaxMotorTorque() const
{
    return b2WheelJoint_GetMaxMotorTorque(m_JointID);
}

float WheelJoint2D::GetMotorSpeed() const
{
    return b2WheelJoint_GetMotorSpeed(m_JointID);
}

float WheelJoint2D::GetMotorTorque() const
{
    return b2WheelJoint_GetMotorTorque(m_JointID);
}

float WheelJoint2D::GetSpringDampingRatio() const
{
    return b2WheelJoint_GetSpringDampingRatio(m_JointID);
}

float WheelJoint2D::GetSpringHertz() const
{
    return b2WheelJoint_GetSpringHertz(m_JointID);
}

void WheelJoint2D::SetLimits(float lower, float upper)
{
    b2WheelJoint_SetLimits(m_JointID, lower, upper);
}

void WheelJoint2D::SetMaxMotorTorque(float maxTorque)
{
    b2WheelJoint_SetMaxMotorTorque(m_JointID, maxTorque);
}

void WheelJoint2D::SetMotorSpeed(float speed)
{
    b2WheelJoint_SetMotorSpeed(m_JointID, speed);
}

void WheelJoint2D::SetSpringDampingRatio(float ratio)
{
    b2WheelJoint_SetSpringDampingRatio(m_JointID, ratio);
}

void WheelJoint2D::SetSpringHertz(float hertz)
{
    b2WheelJoint_SetSpringHertz(m_JointID, hertz);
}

} // namespace Lumen