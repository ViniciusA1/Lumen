#include "Lumen/Graphics/MaterialMap.hpp"

#include "raylib.h"

namespace Lumen
{

MaterialMap::MaterialMap(const ::MaterialMap &materialMap)
    : m_MaterialMap(new ::MaterialMap(materialMap))
{
}

MaterialMap::MaterialMap(::MaterialMap *materialMap) : m_MaterialMap(materialMap)
{
}

Texture2D MaterialMap::GetTexture() const
{
    return m_MaterialMap->texture;
}

Color MaterialMap::GetColor() const
{
    return m_MaterialMap->color;
}

float MaterialMap::GetValue() const
{
    return m_MaterialMap->value;
}

void MaterialMap::SetColor(Color color)
{
    m_MaterialMap->color = color;
}

void MaterialMap::SetTexture(const Texture2D &texture)
{
    m_MaterialMap->texture = texture;
}

void MaterialMap::SetValue(float value)
{
    m_MaterialMap->value = value;
}

MaterialMap::operator ::MaterialMap() const
{
    return *m_MaterialMap;
}

MaterialMap::operator ::MaterialMap *() const
{
    return m_MaterialMap;
}

} // namespace Lumen