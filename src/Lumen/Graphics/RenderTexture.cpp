#include "Lumen/Graphics/RenderTexture.hpp"
#include "raylib.h"

namespace Lumen
{

RenderTexture::RenderTexture(const ::RenderTexture &renderTexture)
    : m_Instance(CreateScope<::RenderTexture>(renderTexture))
{
}

unsigned int RenderTexture::GetID() const
{
    return m_Instance->id;
}

::Texture RenderTexture::GetColorTexture() const
{
    return m_Instance->texture;
}

::Texture RenderTexture::GetDepthTexture() const
{
    return m_Instance->depth;
}

RenderTexture::operator ::RenderTexture() const
{
    return *m_Instance;
}

} // namespace Lumen