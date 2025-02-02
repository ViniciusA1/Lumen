#include "Lumen/Physics2D/PrismaticJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

PrismaticJoint2D::PrismaticJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

bool PrismaticJoint2D::IsLimitEnabled() const
{
    return b2PrismaticJoint_IsLimitEnabled(m_JointID);
}

bool PrismaticJoint2D::IsMotorEnabled() const
{
    return b2PrismaticJoint_IsMotorEnabled(m_JointID);
}

bool PrismaticJoint2D::IsSpringEnabled() const
{
    return b2PrismaticJoint_IsSpringEnabled(m_JointID);
}

float PrismaticJoint2D::GetLowerLimit() const
{
    return b2PrismaticJoint_GetLowerLimit(m_JointID);
}

float PrismaticJoint2D::GetUpperLimit() const
{
    return b2PrismaticJoint_GetUpperLimit(m_JointID);
}

float PrismaticJoint2D::GetMaxMotorForce() const
{
    return b2PrismaticJoint_GetMaxMotorForce(m_JointID);
}

float PrismaticJoint2D::GetMotorForce() const
{
    return b2PrismaticJoint_GetMotorForce(m_JointID);
}

float PrismaticJoint2D::GetMotorSpeed() const
{
    return b2PrismaticJoint_GetMotorSpeed(m_JointID);
}

float PrismaticJoint2D::GetSpringDampingRatio() const
{
    return b2PrismaticJoint_GetSpringDampingRatio(m_JointID);
}

float PrismaticJoint2D::GetSpringHertz() const
{
    return b2PrismaticJoint_GetSpringHertz(m_JointID);
}

void PrismaticJoint2D::SetLimits(float lower, float upper)
{
    b2PrismaticJoint_SetLimits(m_JointID, lower, upper);
}

void PrismaticJoint2D::SetMaxMotorForce(float maxForce)
{
    b2PrismaticJoint_SetMaxMotorForce(m_JointID, maxForce);
}

void PrismaticJoint2D::SetMotorSpeed(float speed)
{
    b2PrismaticJoint_SetMotorSpeed(m_JointID, speed);
}

void PrismaticJoint2D::SetSpringDampingRatio(float ratio)
{
    b2PrismaticJoint_SetSpringDampingRatio(m_JointID, ratio);
}

void PrismaticJoint2D::SetSpringHertz(float hertz)
{
    b2PrismaticJoint_SetSpringHertz(m_JointID, hertz);
}

void PrismaticJoint2D::EnableLimit(bool enable)
{
    b2PrismaticJoint_EnableLimit(m_JointID, enable);
}

void PrismaticJoint2D::EnableMotor(bool enable)
{
    b2PrismaticJoint_EnableMotor(m_JointID, enable);
}

void PrismaticJoint2D::EnableSpring(bool enable)
{
    b2PrismaticJoint_EnableSpring(m_JointID, enable);
}

} // namespace Lumen