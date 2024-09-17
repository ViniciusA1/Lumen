#include "Lumen/Graphics/Texture.hpp"
#include <raylib.h>

namespace Lumen
{

Texture2D::Texture2D(const AssetMetadata &metadata, ::Texture texture) : Asset(metadata)
{
    m_Texture = CreateScope<::Texture>(texture);
}

Texture2D::~Texture2D()
{
    UnloadTexture(*m_Texture);
}

bool Texture2D::IsReady() const
{
    return ::IsTextureReady(*m_Texture);
}

} // namespace Lumen