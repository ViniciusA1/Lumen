#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Mesh;

namespace Lumen
{

class Mesh : public Asset
{
public:
    Mesh(UUID uuid, const ::Mesh &mesh);
    Mesh(const ::Mesh &mesh);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const override;

    operator ::Mesh() const;

private:
    int m_VertexCount;
    int m_TriangleCount;

    float *m_Vertices;
    float *m_Texcoords;
    float *m_Texcoords2;
    float *m_Normals;
    float *m_Tangents;
    unsigned char *m_Colors;
    unsigned short *m_Indices;

    float *m_AnimVertices;
    float *m_AnimNormals;
    unsigned char *m_BoneIds;

    float *m_BoneWeights;

    unsigned int m_VaoID;
    unsigned int *m_VboID;
};

} // namespace Lumen