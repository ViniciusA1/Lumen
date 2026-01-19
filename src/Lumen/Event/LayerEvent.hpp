#pragma once

#include "Lumen/Layer/Layer.hpp"
#include "Lumen/Memory/Memory.hpp"

#include <string>

namespace Lumen
{

struct LayerPushEvent
{
    Ref<Layer> Layer;
};

struct LayerPopEvent
{
    std::string LayerName;
};

} // namespace Lumen