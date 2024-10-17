#pragma once

#include <functional>
#include <string>

namespace Lumen
{

template <typename T> struct Action
{
    std::string Name;
    std::function<T> Func;

    template <typename... Args> void operator()(Args &&...args)
    {
        Func(std::forward<Args>(args)...);
    }
};

} // namespace Lumen