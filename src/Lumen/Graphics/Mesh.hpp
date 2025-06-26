#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Math/BoundingBox.hpp"

#include <span>

struct Mesh;

namespace Lumen
{

class Mesh : public Asset
{
public:
    Mesh() = default;
    Mesh(const AssetHandle &handle, const ::Mesh &mesh);
    Mesh(const AssetHandle &handle, ::Mesh *mesh);
    Mesh(const ::Mesh &mesh);
    Mesh(::Mesh *mesh);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] std::span<float> GetAnimVertices() const;
    [[nodiscard]] std::span<float> GetAnimNormals() const;
    [[nodiscard]] int GetBoneCount() const;
    [[nodiscard]] std::span<unsigned char> GetBoneIds() const;
    [[nodiscard]] std::span<Matrix> GetBoneMatrices() const;
    [[nodiscard]] std::span<float> GetBoneWeights() const;
    [[nodiscard]] BoundingBox GetBoundingBox() const;
    [[nodiscard]] std::span<unsigned char> GetColors() const;
    [[nodiscard]] std::span<unsigned short> GetIndices() const;
    [[nodiscard]] std::span<float> GetNormals() const;
    [[nodiscard]] std::span<float> GetTangents() const;
    [[nodiscard]] std::span<float> GetTexCoords() const;
    [[nodiscard]] std::span<float> GetTexCoords2() const;
    [[nodiscard]] int GetTriangleCount() const;
    [[nodiscard]] AssetType GetType() const final;
    [[nodiscard]] unsigned int GetVAO() const;
    [[nodiscard]] std::span<unsigned int> GetVBOs() const;
    [[nodiscard]] int GetVertexCount() const;
    [[nodiscard]] std::span<float> GetVertices() const;

    operator ::Mesh() const;
    operator ::Mesh *() const;

private:
    ::Mesh *m_Mesh = nullptr;
};

} // namespace Lumen