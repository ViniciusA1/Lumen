#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

void PushID(int id);
void PushID(const std::string &id);
void PopID();

void PushStyleColor(ColorFlags flag, const Color &color);
void PopStyleColor(int count = 1);

void PushStyleVar(StyleFlags flag, float var);
void PushStyleVar(StyleFlags flag, const Vector2 &var);
void PopStyleVar(int count = 1);

} // namespace Lumen::LUI