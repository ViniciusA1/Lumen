#pragma once

#include "Lumen/Graphics/Texture.hpp"

struct RenderTexture;

namespace Lumen
{

class RenderTexture
{
public:
    RenderTexture() = default;
    RenderTexture(const ::RenderTexture &renderTexture);
    RenderTexture(::RenderTexture *renderTexture);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Texture2D GetColorTexture() const;
    [[nodiscard]] Texture2D GetDepthTexture() const;
    [[nodiscard]] int GetRendererID() const;

    operator ::RenderTexture() const;
    operator ::RenderTexture *() const;

private:
    ::RenderTexture *m_RenderTexture = nullptr;
};

} // namespace Lumen