#include "Lumen/Graphics/RenderTexture.hpp"

#include "raylib.h"

namespace Lumen
{

RenderTexture::RenderTexture(const ::RenderTexture &renderTexture)
    : m_RenderTexture(new ::RenderTexture(renderTexture))
{
}

RenderTexture::RenderTexture(::RenderTexture *renderTexture)
    : m_RenderTexture(renderTexture)
{
}

bool RenderTexture::IsValid() const
{
    return m_RenderTexture && ::IsRenderTextureValid(*m_RenderTexture);
}

Texture2D RenderTexture::GetColorTexture() const
{
    return &m_RenderTexture->texture;
}

Texture2D RenderTexture::GetDepthTexture() const
{
    return &m_RenderTexture->depth;
}

int RenderTexture::GetRendererID() const
{
    return m_RenderTexture->id;
}

RenderTexture::operator ::RenderTexture() const
{
    return *m_RenderTexture;
}

RenderTexture::operator ::RenderTexture *() const
{
    return m_RenderTexture;
}

} // namespace Lumen