#include "Lumen/Random/Random.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterRandom();

void RegisterRandomAPI()
{
    RegisterRandom();
}

static void RegisterRandom()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Random>("Random")
        .Constructors<uint64_t>()
        .Property("seed", &Random::GetSeed, &Random::SetSeed)
        .Method("reseed", &Random::Reseed)
        .Method("split", &Random::Split)
        .Method("int", &Random::Int)
        .Method("float", &Random::Float)
        .Method("bool", &Random::Bool)
        .Method("sign", &Random::Sign)
        .Method("vector2D", &Random::Vector2D)
        .Method("vector3D", &Random::Vector3D)
        .Method("range_int", &Random::RangeInt)
        .Method("range_float", &Random::RangeFloat)
        .Method("cauchy", &Random::Cauchy)
        .Method("chi_squared", &Random::ChiSquared)
        .Method("exponential", &Random::Exponential)
        .Method("gamma", &Random::Gamma)
        .Method("gaussian", &Random::Gaussian)
        .Method("log_normal", &Random::LogNormal)
        .Method("normal", &Random::Normal)
        .Method("student", &Random::StudentT)
        .Method("uniform", &Random::Uniform)
        .Method("weibull", &Random::Weibull)
        .StaticMethod("global", &Random::Global);
}

} // namespace Lumen