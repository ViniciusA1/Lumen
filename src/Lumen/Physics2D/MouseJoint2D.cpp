#include "Lumen/Physics2D/MouseJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

MouseJoint2D::MouseJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

float MouseJoint2D::GetMaxForce() const
{
    return b2MouseJoint_GetMaxForce(m_JointID);
}

float MouseJoint2D::GetSpringDampingRatio() const
{
    return b2MouseJoint_GetSpringDampingRatio(m_JointID);
}

float MouseJoint2D::GetSpringHertz() const
{
    return b2MouseJoint_GetSpringHertz(m_JointID);
}

Vector2 MouseJoint2D::GetTarget() const
{
    return b2MouseJoint_GetTarget(m_JointID);
}

void MouseJoint2D::SetMaxForce(float maxForce)
{
    b2MouseJoint_SetMaxForce(m_JointID, maxForce);
}

void MouseJoint2D::SetSpringDampingRatio(float ratio)
{
    b2MouseJoint_SetSpringDampingRatio(m_JointID, ratio);
}

void MouseJoint2D::SetSpringHertz(float hertz)
{
    b2MouseJoint_SetSpringHertz(m_JointID, hertz);
}

void MouseJoint2D::SetTarget(const Vector2 &target)
{
    b2MouseJoint_SetTarget(m_JointID, target);
}

} // namespace Lumen