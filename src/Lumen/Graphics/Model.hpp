#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Math/Matrix4.hpp"

struct Model;
struct Mesh;
struct Material;
struct BoneInfo;
struct Transform;

namespace Lumen
{

class Model : public Asset
{
public:
    Model(UUID uuid, const ::Model &model);
    Model(const ::Model &model);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const override;

    operator ::Model() const;

private:
    Matrix4 m_Transform;

    int m_MeshCount;
    int m_MaterialCount;
    ::Mesh *m_Meshes;
    ::Material *m_Materials;
    int *m_MeshMaterial;

    int m_BoneCount;
    ::BoneInfo *m_Bones;
    ::Transform *m_BindPose;
};

} // namespace Lumen