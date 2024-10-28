#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Texture;

namespace Lumen
{

class Texture2D : public Asset
{
public:
    Texture2D(const AssetMetadata &metadata, const ::Texture &texture);
    ~Texture2D() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Texture() const;

private:
    Scope<::Texture> m_Instance;
};

} // namespace Lumen