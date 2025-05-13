#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"

struct MaterialMap;

namespace Lumen
{

class MaterialMap
{
public:
    MaterialMap() = default;
    MaterialMap(const ::MaterialMap &materialMap);
    MaterialMap(::MaterialMap *materialMap);

    [[nodiscard]] Texture2D GetTexture() const;
    [[nodiscard]] Color GetColor() const;
    [[nodiscard]] float GetValue() const;

    operator ::MaterialMap() const;
    operator ::MaterialMap *() const;

private:
    ::MaterialMap *m_MaterialMap = nullptr;
};

} // namespace Lumen