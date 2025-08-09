#pragma once

#include "Lumen/Scene/Component/UI/LabelComponent.hpp"
#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct InputFieldComponent : public UIComponentBase
{
    LabelComponent Text;
};

} // namespace Lumen