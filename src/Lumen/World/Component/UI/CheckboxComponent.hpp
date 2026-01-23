#pragma once

#include "Lumen/World/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct CheckboxComponent : public UIComponentBase
{
    bool Value = false;
};

} // namespace Lumen