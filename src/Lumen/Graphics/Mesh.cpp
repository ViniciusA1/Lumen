#include "Lumen/Graphics/Mesh.hpp"
#include "raylib.h"

namespace Lumen
{

Mesh::Mesh(const AssetMetadata &metadata, const ::Mesh &mesh)
    : Asset(metadata), m_VertexCount(mesh.vertexCount),
      m_TriangleCount(mesh.triangleCount), m_Vertices(mesh.vertices),
      m_Texcoords(mesh.texcoords), m_Texcoords2(mesh.texcoords2), m_Normals(mesh.normals),
      m_Tangents(mesh.tangents), m_Colors(mesh.colors), m_Indices(mesh.indices),
      m_AnimVertices(mesh.animVertices), m_AnimNormals(mesh.animNormals),
      m_BoneIds(mesh.boneIds), m_BoneWeights(mesh.boneWeights), m_VaoID(mesh.vaoId),
      m_VboID(mesh.vboId)
{
}

Mesh::Mesh(const ::Mesh &mesh) : Mesh({UUID(), "", {""}}, mesh)
{
}

bool Mesh::IsValid() const
{
    return true;
}

Mesh::operator ::Mesh() const
{
    return {m_VertexCount, m_TriangleCount, m_Vertices,    m_Texcoords, m_Texcoords2,
            m_Normals,     m_Tangents,      m_Colors,      m_Indices,   m_AnimVertices,
            m_AnimNormals, m_BoneIds,       m_BoneWeights, m_VaoID,     m_VboID};
}

} // namespace Lumen