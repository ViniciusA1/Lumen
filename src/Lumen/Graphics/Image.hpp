#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Image;

namespace Lumen
{

class Image : public Asset
{
public:
    Image(const AssetMetadata &metadata, const ::Image &image);
    Image(const ::Image &image);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] void *GetData() const;
    [[nodiscard]] int GetFormat() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] int GetMipmap() const;
    [[nodiscard]] int GetWidth() const;

    operator ::Image() const;

private:
    void *m_Data;
    int m_Width;
    int m_Height;
    int m_Mipmaps;
    int m_Format;
};

} // namespace Lumen