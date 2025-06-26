#include "Lumen/Graphics/Material.hpp"

#include "raylib.h"

namespace Lumen
{

Material::Material(const AssetHandle &handle, const ::Material &material)
    : Asset(handle), m_Material(new ::Material(material))
{
}

Material::Material(const AssetHandle &handle, ::Material *material)
    : Asset(handle), m_Material(material)
{
}

Material::Material(const ::Material &material) : Material({}, material)
{
}

Material::Material(::Material *material) : Material({}, material)
{
}

bool Material::IsValid() const
{
    return m_Material && IsMaterialValid(*m_Material);
}

Color Material::GetColor(MaterialMapIndex index) const
{
    return m_Material->maps[static_cast<int>(index)].color;
}

MaterialMap Material::GetMap(MaterialMapIndex index) const
{
    return &m_Material->maps[static_cast<int>(index)];
}

int Material::GetMapCount() const
{
    return static_cast<int>(MaterialMapIndex::MaxAmount);
}

Shader Material::GetShader() const
{
    return &m_Material->shader;
}

AssetType Material::GetType() const
{
    return AssetType::Material;
}

void Material::SetColor(MaterialMapIndex index, Color color)
{
    m_Material->maps[static_cast<int>(index)].color = color;
}

void Material::SetShader(const Shader &shader)
{
    m_Material->shader = shader;
}

Material::operator ::Material() const
{
    return *m_Material;
}

Material::operator ::Material *() const
{
    return m_Material;
}

} // namespace Lumen