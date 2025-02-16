#include "Lumen/Graphics/Material.hpp"

#include "raylib.h"

namespace Lumen
{

Material::Material(UUID uuid, const ::Material &material)
    : Asset(uuid), m_Shader(material.shader), m_Maps(material.maps),
      m_Params({material.params[0], material.params[1], material.params[2],
                material.params[3]})
{
}

Material::Material(const ::Material &material) : Material(UUID(), material)
{
}

bool Material::IsValid() const
{
    return IsMaterialReady(*this);
}

AssetType Material::GetType() const
{
    return AssetType::Material;
}

Material::operator ::Material() const
{
    return {m_Shader, m_Maps, {m_Params[0], m_Params[1], m_Params[2], m_Params[3]}};
}

} // namespace Lumen