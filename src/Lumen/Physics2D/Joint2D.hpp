#pragma once

#include "Lumen/Physics2D/Body2D.hpp"
#include "Lumen/Physics2D/JointDef2D.hpp"

#include "box2d/id.h"

namespace Lumen
{

class Joint2D
{
public:
    Joint2D(const b2JointId &jointID = {0, 0, 0});

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Body2D GetBodyA() const;
    [[nodiscard]] Body2D GetBodyB() const;
    [[nodiscard]] bool GetCollideConnected() const;
    [[nodiscard]] Vector2 GetConstraintForce() const;
    [[nodiscard]] float GetConstraintTorque() const;
    [[nodiscard]] Vector2 GetLocalAnchorA() const;
    [[nodiscard]] Vector2 GetLocalAnchorB() const;
    [[nodiscard]] JointType2D GetType() const;
    [[nodiscard]] void *GetUserData() const;

    void SetCollideConnected(bool shouldCollide);
    void SetUserData(void *data);

    void WakeBodies();

protected:
    b2JointId m_JointID;
};

} // namespace Lumen