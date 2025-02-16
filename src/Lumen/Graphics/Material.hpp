#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/MaterialMap.hpp"
#include "Lumen/Graphics/Shader.hpp"

#include <array>

struct MaterialMap;
struct Material;

namespace Lumen
{

class Material : public Asset
{
public:
    Material(UUID uuid, const ::Material &material);
    Material(const ::Material &material);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const override;

    operator ::Material() const;

private:
    Shader m_Shader;
    ::MaterialMap *m_Maps;
    std::array<float, 4> m_Params;
};

} // namespace Lumen