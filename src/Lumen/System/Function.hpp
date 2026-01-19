#pragma once

#include <functional>
#include <vector>

#define BIND_FUNC(fn)                                                                    \
    [this](auto &&...args) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Lumen
{

template <typename Signature> class Function;

template <typename... Args> class Function<void(Args...)>
{
public:
    Function() = default;
    template <typename Callable> Function(Callable &&function);

    [[nodiscard]] bool IsBound() const;

    void Clear();
    void Invoke(Args... args) const;

    template <typename Callable> Function &operator=(Callable &&function);
    template <typename Callable> Function &operator+=(Callable &&function);
    void operator()(Args... args) const;

private:
    std::vector<std::function<void(Args...)>> m_Functions;
};

template <typename Ret, typename... Args> class Function<Ret(Args...)>
{
public:
    Function() = default;
    template <typename Callable> Function(Callable &&function);

    [[nodiscard]] bool IsBound() const;

    void Clear();

    std::vector<Ret> Invoke(Args... args) const;

    template <typename Callable> Function &operator=(Callable &&function);
    template <typename Callable> Function &operator+=(Callable &&function);
    std::vector<Ret> operator()(Args... args) const;

private:
    std::vector<std::function<Ret(Args...)>> m_Functions;
};

} // namespace Lumen

#include "Function.inl"