#pragma once

namespace Lumen::LUI
{

enum class FontScale
{
    x100,
    x125,
    x150,
    x175,
    x200,
    x500,
};

void InitFont();
void InitIconFont(float size);

float GetFontScaleFactor(FontScale scale);

void PushFont(FontScale scale);
void PopFont();

} // namespace Lumen::LUI