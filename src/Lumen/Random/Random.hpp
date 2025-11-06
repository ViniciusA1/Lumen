#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/System/Limits.hpp"

#include <random>
#include <span>

namespace Lumen
{

class Random
{
public:
    explicit Random(uint64_t seed = std::random_device{}());
    Random(const Random &) = default;
    Random &operator=(const Random &) = default;

    [[nodiscard]] uint64_t GetSeed() const;
    void Reseed();
    void SetSeed(uint64_t seed);
    [[nodiscard]] Random Split(uint64_t salt) const;

    int64_t Int(int64_t min = 0, int64_t max = Limits::Int64Max);

    float Float(float min = 0.0f, float max = 1.0f);
    double Double(double min = 0.0, double max = 1.0);

    bool Bool(double probability = 0.5);
    int Sign();

    Vector2 Vector2D(float min = 0.0f, float max = 1.0f);
    Vector3 Vector3D(float min = 0.0f, float max = 1.0f);

    std::vector<int64_t> RangeInt(size_t count, int64_t min = 0,
                                  int64_t max = Limits::Int64Max);
    std::vector<float> RangeFloat(size_t count, float min = 0.0f, float max = 1.0f);

    double Cauchy(double location = 0.0, double scale = 1.0);
    double ChiSquared(double degreesOfFreedom = 1.0);
    double Exponential(double lambda = 1.0);
    double Gamma(double alpha = 1.0, double beta = 1.0);
    double Gaussian(double mean = 0.0, double stddev = 1.0);
    double LogNormal(double mean = 0.0, double stddev = 1.0);
    double Normal(double mean = 0.0, double stddev = 1.0);
    double StudentT(double degreesOfFreedom = 1.0);
    double Uniform(double min = 0.0, double max = 1.0);
    double Weibull(double a = 1.0, double b = 1.0);

    template <typename T> T Choice(const std::span<std::pair<T, double>> &items);
    template <typename T> T Choice(const std::span<T> &items);
    template <typename T> void Shuffle(const std::span<T> &items);

public:
    static Random &Global();

private:
    std::mt19937_64 m_Engine;
    uint64_t m_Seed = 0;
};

} // namespace Lumen

#include "Lumen/Random/Random.inl"