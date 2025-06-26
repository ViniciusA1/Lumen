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

std::span<float> Mesh::GetAnimVertices() const
{
    return {
        m_Mesh->animVertices,
        static_cast<size_t>(m_Mesh->vertexCount * 3),
    };
}

std::span<float> Mesh::GetAnimNormals() const
{
    return {
        m_Mesh->animNormals,
        static_cast<size_t>(m_Mesh->vertexCount * 3),
    };
}

int Mesh::GetBoneCount() const
{
    return m_Mesh->boneCount;
}

std::span<unsigned char> Mesh::GetBoneIds() const
{
    return {
        m_Mesh->boneIds,
        static_cast<size_t>(m_Mesh->vertexCount * 4),
    };
}

std::span<Matrix> Mesh::GetBoneMatrices() const
{
    return {
        m_Mesh->boneMatrices,
        static_cast<size_t>(m_Mesh->boneCount),
    };
}

std::span<float> Mesh::GetBoneWeights() const
{
    return {
        m_Mesh->boneWeights,
        static_cast<size_t>(m_Mesh->vertexCount * 4),
    };
}

BoundingBox Mesh::GetBoundingBox() const
{
    return ::GetMeshBoundingBox(*m_Mesh);
}

std::span<unsigned char> Mesh::GetColors() const
{
    return {
        m_Mesh->colors,
        static_cast<size_t>(m_Mesh->vertexCount * 4),
    };
}

std::span<unsigned short> Mesh::GetIndices() const
{
    return {
        m_Mesh->indices,
        static_cast<size_t>(m_Mesh->triangleCount * 3),
    };
}

std::span<float> Mesh::GetNormals() const
{
    return {
        m_Mesh->normals,
        static_cast<size_t>(m_Mesh->vertexCount * 3),
    };
}

std::span<float> Mesh::GetTangents() const
{
    return {
        m_Mesh->tangents,
        static_cast<size_t>(m_Mesh->vertexCount * 4),
    };
}

std::span<float> Mesh::GetTexCoords() const
{
    return {
        m_Mesh->texcoords,
        static_cast<size_t>(m_Mesh->vertexCount * 2),
    };
}

std::span<float> Mesh::GetTexCoords2() const
{
    return {
        m_Mesh->texcoords2,
        static_cast<size_t>(m_Mesh->vertexCount * 2),
    };
}

int Mesh::GetTriangleCount() const
{
    return m_Mesh->triangleCount;
}

AssetType Mesh::GetType() const
{
    return AssetType::Mesh;
}

unsigned int Mesh::GetVAO() const
{
    return m_Mesh->vaoId;
}

std::span<unsigned int> Mesh::GetVBOs() const
{
    return {
        m_Mesh->vboId,
        static_cast<size_t>(7),
    };
}

int Mesh::GetVertexCount() const
{
    return m_Mesh->vertexCount;
}

std::span<float> Mesh::GetVertices() const
{
    return {
        m_Mesh->vertices,
        static_cast<size_t>(m_Mesh->vertexCount * 3),
    };
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