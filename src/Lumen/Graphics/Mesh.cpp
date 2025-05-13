#include "Lumen/Graphics/Mesh.hpp"

#include "raylib.h"

namespace Lumen
{

Mesh::Mesh(const AssetHandle &handle, const ::Mesh &mesh)
    : Asset(handle), m_Mesh(new ::Mesh(mesh))
{
}

Mesh::Mesh(const AssetHandle &handle, ::Mesh *mesh) : Asset(handle), m_Mesh(mesh)
{
}

Mesh::Mesh(const ::Mesh &mesh) : Mesh({}, mesh)
{
}

Mesh::Mesh(::Mesh *mesh) : Mesh({}, mesh)
{
}

bool Mesh::IsValid() const
{
    return m_Mesh && m_Mesh->vertexCount != 0;
}

AssetType Mesh::GetType() const
{
    return AssetType::Mesh;
}

Mesh::operator ::Mesh() const
{
    return *m_Mesh;
}

Mesh::operator ::Mesh *() const
{
    return m_Mesh;
}

} // namespace Lumen