#include "Lumen/Graphics/Texture.hpp"
#include <raylib.h>

namespace Lumen
{

Texture2D::Texture2D(const AssetMetadata &metadata, const ::Texture &texture)
    : Asset(metadata), m_Instance(CreateScope<::Texture>(texture))
{
}

Texture2D::~Texture2D()
{
    UnloadTexture(*m_Instance);
}

bool Texture2D::IsValid() const
{
    return ::IsTextureReady(*m_Instance);
}

Texture2D::operator ::Texture() const
{
    return *m_Instance;
}

} // namespace Lumen