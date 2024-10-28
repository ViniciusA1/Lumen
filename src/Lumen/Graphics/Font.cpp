#include "Lumen/Graphics/Font.hpp"
#include "raylib.h"

namespace Lumen
{

Font::Font(const AssetMetadata &metadata, const ::Font &font)
    : Asset(metadata), m_Instance(CreateScope<::Font>(font))
{
}

Font::~Font()
{
    UnloadFont(*m_Instance);
}

bool Font::IsValid() const
{
    return ::IsFontReady(*m_Instance);
}

Font::operator ::Font() const
{
    return *m_Instance;
}

} // namespace Lumen