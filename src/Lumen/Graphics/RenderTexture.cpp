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

Texture2D RenderTexture::GetDepthTexture() const
{
    return &m_RenderTexture->depth;
}

int RenderTexture::GetHeight() const
{
    return m_RenderTexture->texture.height;
}

int RenderTexture::GetRendererID() const
{
    return m_RenderTexture->id;
}

Vector2 RenderTexture::GetSize() const
{
    return {
        static_cast<float>(m_RenderTexture->texture.width),
        static_cast<float>(m_RenderTexture->texture.height),
    };
}

Texture2D RenderTexture::GetTexture() const
{
    return &m_RenderTexture->texture;
}

int RenderTexture::GetWidth() const
{
    return m_RenderTexture->texture.width;
}

void RenderTexture::Resize(int width, int height)
{
    if (width <= 0 || height <= 0)
        return;

    if (GetWidth() != width || GetHeight() != height)
    {
        ::UnloadRenderTexture(*m_RenderTexture);
        *m_RenderTexture = ::LoadRenderTexture(width, height);
    }
}

void RenderTexture::Resize(const Vector2 &size)
{
    Resize(size.x, size.y);
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