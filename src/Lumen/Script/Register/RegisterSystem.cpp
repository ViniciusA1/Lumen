#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"
#include "Lumen/System/Action.hpp"
#include "Lumen/System/Function.hpp"
#include "Lumen/System/Time.hpp"
#include "Lumen/System/TimeStep.hpp"
#include "Lumen/System/UUID.hpp"

namespace Lumen
{

static void RegisterAction();
static void RegisterFunction();
static void RegisterTime();
static void RegisterTimeStep();
static void RegisterUUID();

void RegisterSystemAPI()
{
    RegisterAction();
    RegisterFunction();
    RegisterTime();
    RegisterTimeStep();
    RegisterUUID();
}

static void RegisterAction()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Action>("Action")
        .Constructors<Action()>()
        .Method("is_bound", &Action::IsBound)
        .Method("bind", [](Action &a, const sol::function &f) { a += [f]() { f(); }; })
        .Method("clear", &Action::Clear)
        .Method("invoke", &Action::Invoke)
        .OperatorCall([](Action &a) { a.Invoke(); });
}

static void RegisterFunction()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Function<void()>>("Function")
        .Constructors<Function<void()>()>()
        .Method("is_bound", &Function<void()>::IsBound)
        .Method("bind",
                [](Function<void()> &a, const sol::function &f) { a += [f]() { f(); }; })
        .Method("clear", &Function<void()>::Clear)
        .Method("invoke", &Function<void()>::Invoke)
        .OperatorCall([](Function<void()> &a) { a.Invoke(); });
}

static void RegisterTime()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Time>("Time")
        .StaticMethod("wait", &Time::Wait)
        .StaticMethod("total_time", &Time::GetTime)
        .StaticMethod("delta_time", &Time::GetDeltaTime);
}

static void RegisterTimeStep()
{
    ScriptEngine::GetInstance()
        ->RegisterType<TimeStep>("TimeStep")
        .Constructors<TimeStep(), TimeStep(float)>()
        .Property("seconds", &TimeStep::GetSeconds)
        .Property("milliseconds", &TimeStep::GetMilliseconds)
        .OperatorAdd([](const TimeStep &a, const TimeStep &b) { return a + b; })
        .OperatorSub([](const TimeStep &a, const TimeStep &b) { return a - b; })
        .OperatorMul([](const TimeStep &a, float b) { return a * b; },
                     [](float a, const TimeStep &b) { return b * a; })
        .OperatorDiv([](const TimeStep &a, float b) { return a / b; })
        .OperatorEq([](const TimeStep &a, const TimeStep &b) { return a == b; })
        .OperatorLt([](const TimeStep &a, const TimeStep &b) { return a < b; })
        .OperatorLe([](const TimeStep &a, const TimeStep &b) { return a <= b; });
}

static void RegisterUUID()
{
    ScriptEngine::GetInstance()
        ->RegisterType<UUID>("UUID")
        .Constructors<UUID(), UUID(uint64_t)>()
        .OperatorToString([](const UUID &uuid) { return std::to_string((uint64_t)uuid); })
        .OperatorEq(
            [](const UUID &a, const UUID &b) { return (uint64_t)a == (uint64_t)b; })
        .OperatorLt(
            [](const UUID &a, const UUID &b) { return (uint64_t)a < (uint64_t)b; })
        .OperatorLe(
            [](const UUID &a, const UUID &b) { return (uint64_t)a <= (uint64_t)b; });
}

} // namespace Lumen