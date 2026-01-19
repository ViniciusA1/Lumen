#pragma once

#include "Lumen/Meta/MetaType.hpp"

namespace Lumen
{

class MetaRegistry
{
public:
    MetaRegistry() = delete;

public:
    template <typename T> static MetaType Resolve();
    template <typename T> static MetaType Resolve(const MetaContext &ctx);
    static MetaType Resolve(MetaID id);
    static MetaType Resolve(const MetaContext &ctx, MetaID id);
};

} // namespace Lumen

#include "Lumen/Meta/MetaRegistry.inl"