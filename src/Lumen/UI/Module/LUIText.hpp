#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIFont.hpp"

#include <string>

namespace Lumen::LUI
{

Vector2 CalcTextSize(const std::string &text);

void Text(const std::string &text, FontScale scale = FontScale::x100);
void TextDisabled(const std::string &text, FontScale scale = FontScale::x100);
void TextWrapped(const std::string &text, FontScale scale = FontScale::x100);

} // namespace Lumen::LUI