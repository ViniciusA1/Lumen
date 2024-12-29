#pragma once

#include "Lumen/UI/Style/Style.hpp"

namespace UI = ImGui;

namespace ImGui
{

void Init();
void Shutdown();

void BeginUI();
void EndUI();

void SetStyle(const Lumen::Style &style);

void SearchBar(char *buffer, std::size_t size);

} // namespace ImGui