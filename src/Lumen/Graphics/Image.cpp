#include "Lumen/Graphics/Image.hpp"
#include "raylib.h"

namespace Lumen
{

Image::Image(const AssetMetadata &metadata, const ::Image &image)
    : Asset(metadata), m_Data(image.data), m_Width(image.width), m_Height(image.height),
      m_Mipmaps(image.mipmaps), m_Format(image.format)
{
}

Image::Image(const ::Image &image) : Image({UUID(), "", {""}}, image)
{
}

bool Image::IsValid() const
{
    return IsImageReady(*this);
}

void *Image::GetData() const
{
    return m_Data;
}

int Image::GetFormat() const
{
    return m_Format;
}

int Image::GetHeight() const
{
    return m_Height;
}

int Image::GetMipmap() const
{
    return m_Mipmaps;
}

int Image::GetWidth() const
{
    return m_Width;
}

Image::operator ::Image() const
{
    return {m_Data, m_Width, m_Height, m_Mipmaps, m_Format};
}

} // namespace Lumen