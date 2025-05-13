#include "Lumen/Graphics/Texture.hpp"
#include <raylib.h>

namespace Lumen
{

Texture2D::Texture2D(const AssetHandle &handle, const ::Texture &texture)
    : Asset(handle), m_Texture(new ::Texture(texture))
{
}

Texture2D::Texture2D(const AssetHandle &handle, ::Texture *texture)
    : Asset(handle), m_Texture(texture)
{
}

Texture2D::Texture2D(const ::Texture &texture) : Texture2D({}, texture)
{
}

Texture2D::Texture2D(::Texture *texture) : Texture2D({}, texture)
{
}

bool Texture2D::IsValid() const
{
    return m_Texture && ::IsTextureValid(*m_Texture);
}

int Texture2D::GetFormat() const
{
    return m_Texture->format;
}

int Texture2D::GetHeight() const
{
    return m_Texture->height;
}

int Texture2D::GetMipmap() const
{
    return m_Texture->mipmaps;
}

unsigned int Texture2D::GetRendererID() const
{
    return m_Texture->id;
}

unsigned int *Texture2D::GetRendererID()
{
    return &m_Texture->id;
}

Vector2 Texture2D::GetSize() const
{
    return {static_cast<float>(m_Texture->width), static_cast<float>(m_Texture->height)};
}

AssetType Texture2D::GetType() const
{
    return AssetType::Texture2D;
}

int Texture2D::GetWidth() const
{
    return m_Texture->width;
}

Texture2D::operator ::Texture() const
{
    return *m_Texture;
}

// Texture2D::operator ::Texture *() const
// {
//     return m_Texture;
// }

} // namespace Lumen