#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Texture;

namespace Lumen
{

class Texture2D : public Asset
{
public:
    Texture2D(UUID uuid, const ::Texture &texture);
    Texture2D(const ::Texture &texture);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] int GetFormat() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] int GetMipmap() const;
    [[nodiscard]] unsigned int GetRendererID() const;
    [[nodiscard]] unsigned int &GetRendererID();
    [[nodiscard]] AssetType GetType() const override;
    [[nodiscard]] int GetWidth() const;

    operator ::Texture() const;

private:
    unsigned int m_RendererID;
    int m_Width;
    int m_Height;
    int m_Mipmaps;
    int m_Format;
};

} // namespace Lumen