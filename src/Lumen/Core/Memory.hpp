#pragma once

#include <memory>

namespace Lumen
{

template <typename T> using Scope = std::unique_ptr<T>;
template <typename T> Scope<T> CreateScope()
{
    return std::make_unique<T>();
}

template <typename T> using Ref = std::shared_ptr<T>;
template <typename T> Scope<T> CreateRef()
{
    return std::make_shared<T>();
}

} // namespace Lumen