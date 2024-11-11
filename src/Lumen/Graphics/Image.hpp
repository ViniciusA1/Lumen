#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Image;

namespace Lumen
{

class Image : public Asset
{
public:
    Image(const AssetMetadata &metadata, const ::Image &image);
    ~Image() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Image() const;

private:
    Scope<::Image> m_Instance;
};

} // namespace Lumen