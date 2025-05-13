#include "Lumen/Graphics/Font.hpp"

#include "raylib.h"

namespace Lumen
{

Font::Font(const AssetHandle &handle, const ::Font &font)
    : Asset(handle), m_Font(new ::Font(font))
{
}

Font::Font(const AssetHandle &handle, ::Font *font) : Asset(handle), m_Font(font)
{
}

Font::Font(const ::Font &font) : Font({}, font)
{
}

Font::Font(::Font *font) : Font({}, font)
{
}

bool Font::IsValid() const
{
    return m_Font && ::IsFontValid(*m_Font);
}

Texture2D Font::GetTexture() const
{
    return &m_Font->texture;
}

AssetType Font::GetType() const
{
    return AssetType::Font;
}

Font::operator ::Font() const
{
    return *m_Font;
}

Font::operator ::Font *() const
{
    return m_Font;
}

} // namespace Lumen