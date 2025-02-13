#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Texture.hpp"

struct Font;
struct Rectangle;
struct GlyphInfo;

namespace Lumen
{

class Font : public Asset
{
public:
    Font(UUID uuid, const ::Font &font);
    Font(const ::Font &font);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const override;

    operator ::Font() const;

private:
    int m_BaseSize;
    int m_GlyphCount;
    int m_GlyphPadding;
    Texture2D m_Texture;
    ::Rectangle *m_Recs;
    ::GlyphInfo *m_Glyphs;
};

} // namespace Lumen