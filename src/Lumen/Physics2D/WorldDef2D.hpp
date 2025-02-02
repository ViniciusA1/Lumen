#pragma once

#include "Lumen/Math/Vector2.hpp"

#include <cstdint>

struct b2WorldDef;

namespace Lumen
{

struct WorldDef2D
{
    Vector2 Gravity;
    float RestitutionThreshold;
    float ContactPushoutVelocity;
    float HitEventThreshold;
    float ContactHertz;
    float ContactDampingRatio;
    float JointHertz;
    float JointDampingRatio;
    float MaximumLinearVelocity;
    bool EnableSleep;
    bool EnableContinous;

    WorldDef2D();
    WorldDef2D(const b2WorldDef &def);

    operator b2WorldDef() const;
};

struct WorldCounters2D
{
    std::int32_t StaticBodyCount;
    std::int32_t BodyCount;
    std::int32_t ShapeCount;
    std::int32_t ContactCount;
    std::int32_t JointCount;
    std::int32_t IslandCount;
    std::int32_t StackUsed;
    std::int32_t StaticTreeHeight;
    std::int32_t TreeHeight;
    std::int32_t ByteCount;
    std::int32_t TaskCount;
};

struct WorldProfile2D
{
    float Step;
    float Pairs;
    float Collide;
    float Solve;
    float BuildIslands;
    float SolveConstraints;
    float PrepareTasks;
    float SolverTasks;
    float PrepareConstraints;
    float IntegrateVelocities;
    float WarmStart;
    float SolveVelocities;
    float IntegratePositions;
    float RelaxVelocities;
    float ApplyRestitution;
    float StoreImpulses;
    float FinalizeBodies;
    float SplitIslands;
    float SleepIslands;
    float HitEvents;
    float Broadphase;
    float Continuous;
};

} // namespace Lumen