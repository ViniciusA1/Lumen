#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/MaterialMap.hpp"
#include "Lumen/Graphics/Shader.hpp"

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

    [[nodiscard]] Color GetColor(MaterialMapIndex index) const;
    [[nodiscard]] MaterialMap GetMap(MaterialMapIndex index) const;
    [[nodiscard]] int GetMapCount() const;
    [[nodiscard]] Shader GetShader() const;
    [[nodiscard]] AssetType GetType() const final;

    void SetColor(MaterialMapIndex index, Color color);
    void SetShader(const Shader &shader);

    operator ::Material() const;
    operator ::Material *() const;

private:
    ::Material *m_Material = nullptr;
};

} // namespace Lumen