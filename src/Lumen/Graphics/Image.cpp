#include "Lumen/Graphics/Image.hpp"
#include "raylib.h"

namespace Lumen
{

Image::Image(const AssetMetadata &metadata, const ::Image &image)
    : Asset(metadata), m_Instance(CreateScope<::Image>(image))
{
}

Image::~Image()
{
    UnloadImage(*m_Instance);
}

bool Image::IsValid() const
{
    return IsImageReady(*m_Instance);
}

Image::operator ::Image() const
{
    return *m_Instance;
}

} // namespace Lumen