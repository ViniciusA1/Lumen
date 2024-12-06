#include "Lumen/Graphics/Texture.hpp"
#include <raylib.h>

namespace Lumen
{

Texture2D::Texture2D(const AssetMetadata &metadata, const ::Texture &texture)
    : Asset(metadata), m_RendererID(texture.id), m_Width(texture.width),
      m_Height(texture.height), m_Mipmaps(texture.mipmaps), m_Format(texture.format)
{
}

Texture2D::Texture2D(const ::Texture &texture) : Texture2D({UUID(), "", {""}}, texture)
{
}

bool Texture2D::IsValid() const
{
    return ::IsTextureReady(*this);
}

int Texture2D::GetFormat() const
{
    return m_Format;
}

int Texture2D::GetHeight() const
{
    return m_Height;
}

int Texture2D::GetMipmap() const
{
    return m_Mipmaps;
}

unsigned int Texture2D::GetRendererID() const
{
    return m_RendererID;
}

int Texture2D::GetWidth() const
{
    return m_Width;
}

Texture2D::operator ::Texture() const
{
    return {m_RendererID, m_Width, m_Height, m_Mipmaps, m_Format};
}

} // namespace Lumen