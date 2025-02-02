#include "Lumen/Physics2D/WeldJoint2D.hpp"

#include "box2d/box2d.h"

namespace Lumen
{

WeldJoint2D::WeldJoint2D(const b2JointId &jointID) : Joint2D(jointID)
{
}

float WeldJoint2D::GetAngularDampingRatio() const
{
    return b2WeldJoint_GetAngularDampingRatio(m_JointID);
}

float WeldJoint2D::GetAngularHertz() const
{
    return b2WeldJoint_GetAngularHertz(m_JointID);
}

float WeldJoint2D::GetLinearDampingRatio() const
{
    return b2WeldJoint_GetLinearDampingRatio(m_JointID);
}

float WeldJoint2D::GetLinearHertz() const
{
    return b2WeldJoint_GetLinearHertz(m_JointID);
}

void WeldJoint2D::SetAngularDampingRatio(float ratio)
{
    b2WeldJoint_SetAngularDampingRatio(m_JointID, ratio);
}

void WeldJoint2D::SetAngularHertz(float hertz)
{
    b2WeldJoint_SetAngularHertz(m_JointID, hertz);
}

void WeldJoint2D::SetLinearDampingRatio(float ratio)
{
    b2WeldJoint_SetLinearDampingRatio(m_JointID, ratio);
}

void WeldJoint2D::SetLinearHertz(float hertz)
{
    b2WeldJoint_SetLinearHertz(m_JointID, hertz);
}

} // namespace Lumen