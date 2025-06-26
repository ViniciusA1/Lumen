#pragma once

#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

bool BeginMainMenuBar();
void EndMainMenuBar();

bool BeginMenu(const std::string &label, bool enabled = true);
void EndMenu();

bool BeginSideMenu(const std::string &label, WindowFlags flags = WindowFlags::None);
void EndSideMenu();
bool BeginMainContent(const std::string &label, WindowFlags flags = WindowFlags::None);
void EndMainContent();

bool MenuItem(const std::string &label, const std::string &shortcut = "",
              bool selected = false, bool enabled = true);

} // namespace Lumen::LUI