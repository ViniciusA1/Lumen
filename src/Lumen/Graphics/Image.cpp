#include "Lumen/Graphics/Image.hpp"

#include "raylib.h"

namespace Lumen
{

Image::Image(const AssetHandle &handle, const ::Image &image)
    : Asset(handle), m_Image(new ::Image(image))
{
}

Image::Image(const AssetHandle &handle, ::Image *image) : Asset(handle), m_Image(image)
{
}

Image::Image(const ::Image &image) : Image({}, image)
{
}

Image::Image(::Image *image) : Image({}, image)
{
}

bool Image::IsValid() const
{
    return m_Image && IsImageValid(*m_Image);
}

Rectangle Image::GetAlphaBorder(float threshold) const
{
    return ::GetImageAlphaBorder(*m_Image, threshold);
}

Color Image::GetColor(int x, int y) const
{
    return ::GetImageColor(*m_Image, x, y);
}

void *Image::GetData() const
{
    return m_Image->data;
}

int Image::GetFormat() const
{
    return m_Image->format;
}

int Image::GetHeight() const
{
    return m_Image->height;
}

int Image::GetMipmap() const
{
    return m_Image->mipmaps;
}

Vector2 Image::GetSize() const
{
    return {
        static_cast<float>(m_Image->width),
        static_cast<float>(m_Image->height),
    };
}

AssetType Image::GetType() const
{
    return AssetType::Image;
}

int Image::GetWidth() const
{
    return m_Image->width;
}

void Image::AlphaClear(Color color, float threshold)
{
    ::ImageAlphaClear(m_Image, color, threshold);
}

void Image::AlphaCrop(float threshold)
{
    ::ImageAlphaCrop(m_Image, threshold);
}

void Image::AlphaMask(const Image &mask)
{
    ::ImageAlphaMask(m_Image, *mask.m_Image);
}

void Image::AlphaPremultiply()
{
    ::ImageAlphaPremultiply(m_Image);
}

void Image::Crop(const Rectangle &crop)
{
    ::ImageCrop(m_Image, crop);
}

void Image::Dither(int rBpp, int gBpp, int bBpp, int aBpp)
{
    ::ImageDither(m_Image, rBpp, gBpp, bBpp, aBpp);
}

void Image::KernelConvolution(const float *kernel, int kernelSize)
{
    ::ImageKernelConvolution(m_Image, kernel, kernelSize);
}

void Image::Resize(int newWidth, int newHeight)
{
    ::ImageResize(m_Image, newWidth, newHeight);
}

void Image::ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY,
                         Color fill)
{
    ::ImageResizeCanvas(m_Image, newWidth, newHeight, offsetX, offsetY, fill);
}

void Image::ResizeNN(int newWidth, int newHeight)
{
    ::ImageResizeNN(m_Image, newWidth, newHeight);
}

void Image::Rotate(int degrees)
{
    ::ImageRotate(m_Image, degrees);
}

void Image::RotateCCW()
{
    ::ImageRotateCCW(m_Image);
}

void Image::RotateCW()
{
    ::ImageRotateCW(m_Image);
}

void Image::ToMipmaps()
{
    ::ImageMipmaps(m_Image);
}

void Image::ToPOT(Color fill)
{
    ::ImageToPOT(m_Image, fill);
}

void Image::ConvertFormat(int newFormat)
{
    ::ImageFormat(m_Image, newFormat);
}

void Image::BlurGaussian(int blurSize)
{
    ::ImageBlurGaussian(m_Image, blurSize);
}

void Image::ColorBrightness(int brightness)
{
    ::ImageColorBrightness(m_Image, brightness);
}

void Image::ColorContrast(float contrast)
{
    ::ImageColorContrast(m_Image, contrast);
}

void Image::ColorGrayscale()
{
    ::ImageColorGrayscale(m_Image);
}

void Image::ColorInvert()
{
    ::ImageColorInvert(m_Image);
}

void Image::ColorReplace(Color color, Color replace)
{
    ::ImageColorReplace(m_Image, color, replace);
}

void Image::ColorTint(Color color)
{
    ::ImageColorTint(m_Image, color);
}

void Image::FlipHorizontal()
{
    ::ImageFlipHorizontal(m_Image);
}

void Image::FlipVertical()
{
    ::ImageFlipVertical(m_Image);
}

Image::operator ::Image() const
{
    return *m_Image;
}

Image::operator ::Image *() const
{
    return m_Image;
}

} // namespace Lumen