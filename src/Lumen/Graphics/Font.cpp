#include "Lumen/Graphics/Font.hpp"
#include "raylib.h"

namespace Lumen
{

Font::Font(UUID uuid, const ::Font &font)
    : Asset(uuid), m_BaseSize(font.baseSize), m_GlyphCount(font.glyphCount),
      m_GlyphPadding(font.glyphPadding), m_Texture(font.texture), m_Recs(font.recs),
      m_Glyphs(font.glyphs)
{
}

Font::Font(const ::Font &font) : Font(UUID(), font)
{
}

bool Font::IsValid() const
{
    return ::IsFontReady(*this);
}

AssetType Font::GetType() const
{
    return AssetType::Font;
}

Font::operator ::Font() const
{
    return {m_BaseSize, m_GlyphCount, m_GlyphPadding, m_Texture, m_Recs, m_Glyphs};
}

} // namespace Lumen