#include "Lumen/Graphics/Model.hpp"
#include "raylib.h"

namespace Lumen
{

Model::Model(const AssetMetadata &metadata, const ::Model &model)
    : Asset(metadata), m_Transform(model.transform), m_MeshCount(model.meshCount),
      m_MaterialCount(model.materialCount), m_Meshes(model.meshes),
      m_Materials(model.materials), m_MeshMaterial(model.meshMaterial),
      m_BoneCount(model.boneCount), m_Bones(model.bones), m_BindPose(model.bindPose)
{
}

Model::Model(const ::Model &model) : Model({UUID(), "", {""}}, model)
{
}

bool Model::IsValid() const
{
    return IsModelReady(*this);
}

Model::operator ::Model() const
{
    return ::Model{m_Transform,    m_MeshCount, m_MaterialCount, m_Meshes,  m_Materials,
                   m_MeshMaterial, m_BoneCount, m_Bones,         m_BindPose};
}
} // namespace Lumen