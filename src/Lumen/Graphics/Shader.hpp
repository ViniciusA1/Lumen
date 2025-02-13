#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Shader;

namespace Lumen
{

class Shader : public Asset
{
public:
    Shader(UUID uuid, const ::Shader &shader);
    Shader(const ::Shader &shader);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] int *GetLocations() const;
    [[nodiscard]] unsigned int GetRendererID() const;
    [[nodiscard]] AssetType GetType() const override;

    operator ::Shader() const;

private:
    unsigned int m_RendererID;
    int *m_Locs;
};

} // namespace Lumen