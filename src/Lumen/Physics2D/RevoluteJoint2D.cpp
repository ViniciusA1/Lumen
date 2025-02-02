#include "Lumen/Physics2D/RevoluteJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

RevoluteJoint2D::RevoluteJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

void RevoluteJoint2D::EnableLimit(bool enable)
{
    b2RevoluteJoint_EnableLimit(m_JointID, enable);
}

void RevoluteJoint2D::EnableMotor(bool enable)
{
    b2RevoluteJoint_EnableMotor(m_JointID, enable);
}

void RevoluteJoint2D::EnableSpring(bool enable)
{
    b2RevoluteJoint_EnableSpring(m_JointID, enable);
}

bool RevoluteJoint2D::IsLimitEnabled() const
{
    return b2RevoluteJoint_IsLimitEnabled(m_JointID);
}

bool RevoluteJoint2D::IsMotorEnabled() const
{
    return b2RevoluteJoint_IsMotorEnabled(m_JointID);
}

float RevoluteJoint2D::GetAngle() const
{
    return b2RevoluteJoint_GetAngle(m_JointID);
}

float RevoluteJoint2D::GetLowerLimit() const
{
    return b2RevoluteJoint_GetLowerLimit(m_JointID);
}

float RevoluteJoint2D::GetUpperLimit() const
{
    return b2RevoluteJoint_GetUpperLimit(m_JointID);
}

float RevoluteJoint2D::GetMaxMotorTorque() const
{
    return b2RevoluteJoint_GetMaxMotorTorque(m_JointID);
}

float RevoluteJoint2D::GetMotorSpeed() const
{
    return b2RevoluteJoint_GetMotorSpeed(m_JointID);
}

float RevoluteJoint2D::GetMotorTorque() const
{
    return b2RevoluteJoint_GetMotorTorque(m_JointID);
}

float RevoluteJoint2D::GetSpringDampingRatio() const
{
    return b2RevoluteJoint_GetSpringDampingRatio(m_JointID);
}

float RevoluteJoint2D::GetSpringHertz() const
{
    return b2RevoluteJoint_GetSpringHertz(m_JointID);
}

void RevoluteJoint2D::SetLimits(float lower, float upper)
{
    b2RevoluteJoint_SetLimits(m_JointID, lower, upper);
}

void RevoluteJoint2D::SetMaxMotorTorque(float maxTorque)
{
    b2RevoluteJoint_SetMaxMotorTorque(m_JointID, maxTorque);
}

void RevoluteJoint2D::SetMotorSpeed(float speed)
{
    b2RevoluteJoint_SetMotorSpeed(m_JointID, speed);
}

void RevoluteJoint2D::SetSpringDampingRatio(float ratio)
{
    b2RevoluteJoint_SetSpringDampingRatio(m_JointID, ratio);
}

void RevoluteJoint2D::SetSpringHertz(float hertz)
{
    b2RevoluteJoint_SetSpringHertz(m_JointID, hertz);
}

} // namespace Lumen