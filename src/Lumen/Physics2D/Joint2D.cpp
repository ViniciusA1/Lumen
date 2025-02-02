#include "Lumen/Physics2D/Joint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

Joint2D::Joint2D(const b2JointId &joint) : m_JointID(joint)
{
}

bool Joint2D::IsValid() const
{
    return b2Joint_IsValid(m_JointID);
}

Body2D Joint2D::GetBodyA() const
{
    return b2Joint_GetBodyA(m_JointID);
}

Body2D Joint2D::GetBodyB() const
{
    return b2Joint_GetBodyB(m_JointID);
}

bool Joint2D::GetCollideConnected() const
{
    return b2Joint_GetCollideConnected(m_JointID);
}

Vector2 Joint2D::GetConstraintForce() const
{
    return b2Joint_GetConstraintForce(m_JointID);
}

float Joint2D::GetConstraintTorque() const
{
    return b2Joint_GetConstraintTorque(m_JointID);
}

Vector2 Joint2D::GetLocalAnchorA() const
{
    return b2Joint_GetLocalAnchorA(m_JointID);
}

Vector2 Joint2D::GetLocalAnchorB() const
{
    return b2Joint_GetLocalAnchorB(m_JointID);
}

JointType2D Joint2D::GetType() const
{
    return static_cast<JointType2D>(b2Joint_GetType(m_JointID));
}

void *Joint2D::GetUserData() const
{
    return b2Joint_GetUserData(m_JointID);
}

void Joint2D::SetCollideConnected(bool shouldCollide)
{
    b2Joint_SetCollideConnected(m_JointID, shouldCollide);
}

void Joint2D::SetUserData(void *data)
{
    b2Joint_SetUserData(m_JointID, data);
}

void Joint2D::WakeBodies()
{
    b2Joint_WakeBodies(m_JointID);
}

} // namespace Lumen