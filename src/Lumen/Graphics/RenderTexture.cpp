#include "Lumen/Graphics/RenderTexture.hpp"

#include "raylib.h"

namespace Lumen
{

RenderTexture::RenderTexture() : m_RendererID(0), m_ColorTexture({}), m_DepthTexture({})
{
}

RenderTexture::RenderTexture(const ::RenderTexture &renderTexture)
    : m_RendererID(renderTexture.id), m_ColorTexture(renderTexture.texture),
      m_DepthTexture(renderTexture.depth)
{
}

bool RenderTexture::IsValid() const
{
    return IsRenderTextureReady(*this);
}

Texture2D RenderTexture::GetColorTexture() const
{
    return m_ColorTexture;
}

Texture2D RenderTexture::GetDepthTexture() const
{
    return m_DepthTexture;
}

unsigned int RenderTexture::GetRendererID() const
{
    return m_RendererID;
}

Texture2D &RenderTexture::GetColorTexture()
{
    return m_ColorTexture;
}

Texture2D &RenderTexture::GetDepthTexture()
{
    return m_DepthTexture;
}

unsigned int &RenderTexture::GetRendererID()
{
    return m_RendererID;
}

RenderTexture::operator ::RenderTexture() const
{
    return {m_RendererID, m_ColorTexture, m_DepthTexture};
}

} // namespace Lumen