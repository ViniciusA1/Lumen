#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Material;

namespace Lumen
{

class Material : public Asset
{
public:
    Material() = default;
    Material(const AssetHandle &handle, const ::Material &material);
    Material(const AssetHandle &handle, ::Material *material);
    Material(const ::Material &material);
    Material(::Material *material);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const final;

    operator ::Material() const;
    operator ::Material *() const;

private:
    ::Material *m_Material = nullptr;
};

} // namespace Lumen