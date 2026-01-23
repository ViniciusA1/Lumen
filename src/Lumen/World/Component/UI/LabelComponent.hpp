#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/World/Component/UI/UIComponentBase.hpp"

#include <string>

namespace Lumen
{

struct LabelComponent : public UIComponentBase
{
    std::string Text;
    AssetHandle Font;
    int FontSize = 16;
};

} // namespace Lumen