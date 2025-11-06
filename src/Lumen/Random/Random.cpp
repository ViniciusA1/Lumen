#include "Lumen/Random/Random.hpp"

namespace Lumen
{

Random::Random(uint64_t seed) : m_Seed(seed), m_Engine(seed)
{
}

uint64_t Random::GetSeed() const
{
    return m_Seed;
}

void Random::Reseed()
{
    SetSeed(std::random_device{}());
}

void Random::SetSeed(uint64_t seed)
{
    m_Seed = seed;
    m_Engine.seed(seed);
}

Random Random::Split(uint64_t salt) const
{
    return Random(m_Seed ^ (salt + 0x9E3779B97F4A7C15ULL));
}

int64_t Random::Int(int64_t min, int64_t max)
{
    std::uniform_int_distribution<int64_t> dist(min, max);
    return dist(m_Engine);
}

float Random::Float(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(m_Engine);
}

double Random::Double(double min, double max)
{
    std::uniform_real_distribution<double> dist(min, max);
    return dist(m_Engine);
}

bool Random::Bool(double probability)
{
    std::bernoulli_distribution dist(probability);
    return dist(m_Engine);
}

int Random::Sign()
{
    return Bool() ? 1 : -1;
}

Vector2 Random::Vector2D(float min, float max)
{
    return {Float(min, max), Float(min, max)};
}

Vector3 Random::Vector3D(float min, float max)
{
    return {Float(min, max), Float(min, max), Float(min, max)};
}

std::vector<int64_t> Random::RangeInt(size_t count, int64_t min, int64_t max)
{
    std::vector<int64_t> result;
    result.reserve(count);
    for (size_t i = 0; i < count; i++)
        result.push_back(Int(min, max));
    return result;
}

std::vector<float> Random::RangeFloat(size_t count, float min, float max)
{
    std::vector<float> result;
    result.reserve(count);
    for (size_t i = 0; i < count; i++)
        result.push_back(Float(min, max));
    return result;
}

double Random::Cauchy(double location, double scale)
{
    std::cauchy_distribution<double> dist(location, scale);
    return dist(m_Engine);
}

double Random::ChiSquared(double degreesOfFreedom)
{
    std::chi_squared_distribution<double> dist(degreesOfFreedom);
    return dist(m_Engine);
}

double Random::Exponential(double lambda)
{
    std::exponential_distribution<double> dist(lambda);
    return dist(m_Engine);
}

double Random::Gamma(double alpha, double beta)
{
    std::gamma_distribution<double> dist(alpha, beta);
    return dist(m_Engine);
}

double Random::Gaussian(double mean, double stddev)
{
    return Normal(mean, stddev);
}

double Random::LogNormal(double mean, double stddev)
{
    std::lognormal_distribution<double> dist(mean, stddev);
    return dist(m_Engine);
}

double Random::Normal(double mean, double stddev)
{
    std::normal_distribution<double> dist(mean, stddev);
    return dist(m_Engine);
}

double Random::StudentT(double degreesOfFreedom)
{
    std::student_t_distribution<double> dist(degreesOfFreedom);
    return dist(m_Engine);
}

double Random::Uniform(double min, double max)
{
    std::uniform_real_distribution<double> dist(min, max);
    return dist(m_Engine);
}

double Random::Weibull(double a, double b)
{
    std::weibull_distribution<double> dist(a, b);
    return dist(m_Engine);
}

Random &Random::Global()
{
    thread_local Random instance(std::random_device{}());
    return instance;
}

} // namespace Lumen