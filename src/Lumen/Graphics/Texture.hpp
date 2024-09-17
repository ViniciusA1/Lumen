#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Texture;

namespace Lumen
{

class Texture2D : public Asset
{
public:
    Texture2D(const AssetMetadata &metadata, ::Texture texture);
    ~Texture2D() override;

    [[nodiscard]] bool IsReady() const override;

private:
    Scope<::Texture> m_Texture;
};

} // namespace Lumen