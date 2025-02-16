#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"

struct MaterialMap;

namespace Lumen
{

class MaterialMap
{
public:
    MaterialMap(const ::MaterialMap &materialMap);

    [[nodiscard]] Texture2D GetTexture() const;
    [[nodiscard]] Color GetColor() const;
    [[nodiscard]] float GetValue() const;

    operator ::MaterialMap() const;

private:
    Texture2D m_Texture;
    Color m_Color;
    float m_Value;
};

} // namespace Lumen