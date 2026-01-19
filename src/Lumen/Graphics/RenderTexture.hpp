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

    [[nodiscard]] Texture2D GetDepthTexture() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] int GetRendererID() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] Texture2D GetTexture() const;
    [[nodiscard]] int GetWidth() const;

    void Resize(int width, int height);
    void Resize(const Vector2 &size);

    operator ::RenderTexture() const;
    operator ::RenderTexture *() const;

private:
    ::RenderTexture *m_RenderTexture = nullptr;
};

} // namespace Lumen