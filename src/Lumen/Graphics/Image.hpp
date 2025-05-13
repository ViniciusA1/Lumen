#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"

struct Image;

namespace Lumen
{

class Image : public Asset
{
public:
    Image() = default;
    Image(const AssetHandle &handle, const ::Image &image);
    Image(const AssetHandle &handle, ::Image *image);
    Image(const ::Image &image);
    Image(::Image *image);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] Rectangle GetAlphaBorder(float threshold) const;
    [[nodiscard]] Color GetColor(int x, int y) const;
    [[nodiscard]] void *GetData() const;
    [[nodiscard]] int GetFormat() const;
    [[nodiscard]] int GetHeight() const;
    [[nodiscard]] int GetMipmap() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] AssetType GetType() const final;
    [[nodiscard]] int GetWidth() const;

    void AlphaClear(Color color, float threshold);
    void AlphaCrop(float threshold);
    void AlphaMask(const Image &mask);
    void AlphaPremultiply();
    void Crop(const Rectangle &crop);
    void Dither(int rBpp, int gBpp, int bBpp, int aBpp);
    void KernelConvolution(const float *kernel, int kernelSize);
    void Resize(int newWidth, int newHeight);
    void ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color fill);
    void ResizeNN(int newWidth, int newHeight);
    void Rotate(int degrees);
    void RotateCCW();
    void RotateCW();
    void ToMipmaps();
    void ToPOT(Color fill);
    void ConvertFormat(int newFormat);
    void BlurGaussian(int blurSize);
    void ColorBrightness(int brightness);
    void ColorContrast(float contrast);
    void ColorGrayscale();
    void ColorInvert();
    void ColorReplace(Color color, Color replace);
    void ColorTint(Color color);
    void FlipHorizontal();
    void FlipVertical();

    operator ::Image() const;
    operator ::Image *() const;

private:
    ::Image *m_Image = nullptr;
};

} // namespace Lumen