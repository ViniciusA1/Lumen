#include "Lumen/Physics2D/DistanceJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

DistanceJoint2D::DistanceJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

bool DistanceJoint2D::IsLimitEnabled() const
{
    return b2DistanceJoint_IsLimitEnabled(m_JointID);
}

bool DistanceJoint2D::IsMotorEnabled() const
{
    return b2DistanceJoint_IsMotorEnabled(m_JointID);
}

bool DistanceJoint2D::IsSpringEnabled() const
{
    return b2DistanceJoint_IsSpringEnabled(m_JointID);
}

float DistanceJoint2D::GetCurrentLength() const
{
    return b2DistanceJoint_GetCurrentLength(m_JointID);
}

float DistanceJoint2D::GetLength() const
{
    return b2DistanceJoint_GetLength(m_JointID);
}

float DistanceJoint2D::GetMinLength() const
{
    return b2DistanceJoint_GetMinLength(m_JointID);
}

float DistanceJoint2D::GetMaxLength() const
{
    return b2DistanceJoint_GetMaxLength(m_JointID);
}

float DistanceJoint2D::GetMaxMotorForce() const
{
    return b2DistanceJoint_GetMaxMotorForce(m_JointID);
}

float DistanceJoint2D::GetMotorSpeed() const
{
    return b2DistanceJoint_GetMotorSpeed(m_JointID);
}

float DistanceJoint2D::GetMotorForce() const
{
    return b2DistanceJoint_GetMotorForce(m_JointID);
}

void DistanceJoint2D::SetLength(float length)
{
    b2DistanceJoint_SetLength(m_JointID, length);
}

void DistanceJoint2D::SetLengthRange(float minLength, float maxLength)
{
    b2DistanceJoint_SetLengthRange(m_JointID, minLength, maxLength);
}

void DistanceJoint2D::SetMaxMotorForce(float force)
{
    b2DistanceJoint_SetMaxMotorForce(m_JointID, force);
}

void DistanceJoint2D::SetMotorSpeed(float speed)
{
    b2DistanceJoint_SetMotorSpeed(m_JointID, speed);
}

void DistanceJoint2D::SetSpringDampingRatio(float ratio)
{
    b2DistanceJoint_SetSpringDampingRatio(m_JointID, ratio);
}

void DistanceJoint2D::SetSpringHertz(float hertz)
{
    b2DistanceJoint_SetSpringHertz(m_JointID, hertz);
}

void DistanceJoint2D::EnableLimit(bool enable)
{
    b2DistanceJoint_EnableLimit(m_JointID, enable);
}

void DistanceJoint2D::EnableMotor(bool enable)
{
    b2DistanceJoint_EnableMotor(m_JointID, enable);
}

void DistanceJoint2D::EnableSpring(bool enable)
{
    b2DistanceJoint_EnableSpring(m_JointID, enable);
}

} // namespace Lumen