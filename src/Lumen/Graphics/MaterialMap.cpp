#include "Lumen/Graphics/MaterialMap.hpp"

#include "raylib.h"

namespace Lumen
{

MaterialMap::MaterialMap(const ::MaterialMap &materialMap)
    : m_Texture(materialMap.texture), m_Color(materialMap.color),
      m_Value(materialMap.value)
{
}

Texture2D MaterialMap::GetTexture() const
{
    return m_Texture;
}

Color MaterialMap::GetColor() const
{
    return m_Color;
}

float MaterialMap::GetValue() const
{
    return m_Value;
}

MaterialMap::operator ::MaterialMap() const
{
    return {m_Texture, m_Color, m_Value};
}

} // namespace Lumen