#pragma once

#include "Lumen/World/Component/UI/LabelComponent.hpp"
#include "Lumen/World/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct InputFieldComponent : public UIComponentBase
{
    LabelComponent Text;
};

} // namespace Lumen