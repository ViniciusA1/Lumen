#include "Lumen/Graphics/Mesh.hpp"
#include "raylib.h"

namespace Lumen
{

Mesh::Mesh(const AssetMetadata &metadata, const ::Mesh &mesh)
    : Asset(metadata), m_Instance(CreateScope<::Mesh>(mesh))
{
}

Mesh::~Mesh()
{
    UnloadMesh(*m_Instance);
}

bool Mesh::IsValid() const
{
    return true;
}

Mesh::operator ::Mesh() const
{
    return *m_Instance;
}

} // namespace Lumen