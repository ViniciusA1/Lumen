#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Audio/AudioType.hpp"

namespace Lumen
{

struct AudioSourceComponent
{
    AudioType Type;
    AssetHandle Audio;
};

} // namespace Lumen