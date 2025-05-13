#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Math/Vector2.hpp"

struct Texture;

namespace Lumen
{

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
    [[nodiscard]] unsigned int *GetRendererID();
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] AssetType GetType() const final;
    [[nodiscard]] int GetWidth() const;

    operator ::Texture() const;
    operator ::Texture *() const;

private:
    ::Texture *m_Texture = nullptr;
};

} // namespace Lumen