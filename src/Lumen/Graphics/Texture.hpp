#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"

struct Texture;

namespace Lumen
{

enum class TextureFilter
{
    Point,
    Bilinear,
    Trilinear,
    Anisotropic4X,
    Anisotropic8X,
    Anisotropic16X,
};

enum class TextureWrap
{
    Repeat,
    Clamp,
    MirrorRepeat,
    MirrorClamp
};

class Texture2D : public Asset
{
public:
    Texture2D() = default;
    Texture2D(const AssetHandle &handle, const ::Texture &texture);
    Texture2D(const AssetHandle &handle, ::Texture *texture);
    Texture2D(const ::Texture &texture);
    Texture2D(::Texture *texture);

    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] int GetFormat() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] int GetMipmap() const;
    [[nodiscard]] unsigned int GetRendererID() const;
    [[nodiscard]] unsigned int *GetRendererIDPtr() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] AssetType GetType() const final;
    [[nodiscard]] int GetWidth() const;

    void SetFilter(TextureFilter filter);
    void SetWrap(TextureWrap wrap);

    void UpdateData(const void *data);
    void UpdateDataRect(const void *data, const Rectangle &rect);

    operator ::Texture() const;
    operator ::Texture *() const;

private:
    ::Texture *m_Texture = nullptr;
};

} // namespace Lumen