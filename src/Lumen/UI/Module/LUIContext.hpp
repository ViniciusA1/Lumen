#pragma once

#include "Lumen/Core/Function.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

namespace Lumen::LUI
{

void Init();
void Shutdown();

void BeginUI();
void EndUI();

void SetConfigFlags(ConfigFlags flags);

void PushOverlay(const Function<void()> &overlay);
void PopOverlay();

} // namespace Lumen::LUI