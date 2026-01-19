#pragma once

#include <memory>

namespace Lumen
{

template <typename T> using Weak = std::weak_ptr<T>;

} // namespace Lumen