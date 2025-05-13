#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Texture.hpp"

struct Font;

namespace Lumen
{

class Font : public Asset
{
public:
    Font() = default;
    Font(const AssetHandle &handle, const ::Font &font);
    Font(const AssetHandle &handle, ::Font *font);
    Font(const ::Font &font);
    Font(::Font *font);

    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] Texture2D GetTexture() const;
    [[nodiscard]] AssetType GetType() const final;

    operator ::Font() const;
    operator ::Font *() const;

private:
    ::Font *m_Font = nullptr;
};

} // namespace Lumen