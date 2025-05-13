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

MaterialMap::operator ::MaterialMap() const
{
    return *m_MaterialMap;
}

MaterialMap::operator ::MaterialMap *() const
{
    return m_MaterialMap;
}

} // namespace Lumen