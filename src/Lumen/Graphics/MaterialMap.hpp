#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"

struct MaterialMap;

namespace Lumen
{

enum class MaterialMapIndex
{
    Albedo = 0,
    Metalness,
    Normal,
    Roughness,
    Occlusion,
    Emission,
    Height,
    Cubemap,
    Irradiance,
    Prefilter,
    Brdf,

    Diffuse = Albedo,
    Specular = Metalness,

    MaxAmount = 12
};

class MaterialMap
{
public:
    MaterialMap() = default;
    MaterialMap(const ::MaterialMap &materialMap);
    MaterialMap(::MaterialMap *materialMap);

    [[nodiscard]] Texture2D GetTexture() const;
    [[nodiscard]] Color GetColor() const;
    [[nodiscard]] float GetValue() const;

    void SetColor(Color color);
    void SetTexture(const Texture &texture);
    void SetValue(float value);

    operator ::MaterialMap() const;
    operator ::MaterialMap *() const;

private:
    ::MaterialMap *m_MaterialMap = nullptr;
};

} // namespace Lumen