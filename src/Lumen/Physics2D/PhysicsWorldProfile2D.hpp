#pragma once

namespace Lumen
{

struct PhysicsWorldProfile2D
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