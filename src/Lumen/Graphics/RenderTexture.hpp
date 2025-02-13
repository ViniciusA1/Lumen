#pragma once

#include "Lumen/Graphics/Texture.hpp"

struct RenderTexture;

namespace Lumen
{

class RenderTexture
{
public:
    RenderTexture();
    RenderTexture(const ::RenderTexture &renderTexture);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Texture2D GetColorTexture() const;
    [[nodiscard]] Texture2D GetDepthTexture() const;
    [[nodiscard]] unsigned int GetRendererID() const;
    Texture2D &GetColorTexture();
    Texture2D &GetDepthTexture();
    unsigned int &GetRendererID();

    operator ::RenderTexture() const;

private:
    unsigned int m_RendererID;
    Texture2D m_ColorTexture;
    Texture2D m_DepthTexture;
};

} // namespace Lumen