#pragma once

#include "Lumen/Core/Memory.hpp"

struct Texture;
struct RenderTexture;

namespace Lumen
{

class RenderTexture
{
public:
    RenderTexture() = default;
    RenderTexture(const ::RenderTexture &renderTexture);

    [[nodiscard]] unsigned int GetID() const;
    [[nodiscard]] ::Texture GetColorTexture() const;
    [[nodiscard]] ::Texture GetDepthTexture() const;

    operator ::RenderTexture() const;

private:
    Scope<::RenderTexture> m_Instance;
};

} // namespace Lumen