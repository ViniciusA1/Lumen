#include "Lumen/Graphics/Model.hpp"

#include "raylib.h"

namespace Lumen
{

Model::Model(const AssetHandle &handle, const ::Model &model)
    : Asset(handle), m_Model(new ::Model(model))
{
}

Model::Model(const AssetHandle &handle, ::Model *model) : Asset(handle), m_Model(model)
{
}

Model::Model(const ::Model &model) : Model({}, model)
{
}

Model::Model(::Model *model) : Model({}, model)
{
}

Model::Model(const AssetHandle &handle, const ::Model &model, ::ModelAnimation *animation,
             int animationCount)
    : Asset(handle), m_Model(new ::Model(model)), m_ModelAnimation(animation),
      m_AnimationCount(animationCount)
{
}

Model::Model(const AssetHandle &handle, ::Model *model, ::ModelAnimation *animation,
             int animationCount)
    : Asset(handle), m_Model(model), m_ModelAnimation(animation),
      m_AnimationCount(animationCount)
{
}

Model::Model(const ::Model &model, ::ModelAnimation *animation, int animationCount)
    : Model({}, model, animation, animationCount)
{
}

Model::Model(::Model *model, ::ModelAnimation *animation, int animationCount)
    : Model({}, model, animation, animationCount)
{
}

bool Model::IsValid() const
{
    return m_Model && IsModelValid(*m_Model);
}

ModelAnimation Model::GetAnimation(int index) const
{
    if (m_ModelAnimation && index >= 0 && index < m_AnimationCount)
        return &m_ModelAnimation[index];

    return {};
}

std::vector<ModelAnimation> Model::GetAnimations() const
{
    std::vector<ModelAnimation> anims;
    anims.reserve(m_AnimationCount);

    for (int i = 0; i < m_AnimationCount; i++)
        anims.emplace_back(&m_ModelAnimation[i]);

    return anims;
}

int Model::GetAnimationCount() const
{
    return m_AnimationCount;
}

Bone Model::GetBone(int index) const
{
    if (index >= 0 && index < m_Model->boneCount)
        return &m_Model->bones[index];

    return {};
}

std::vector<Bone> Model::GetBones() const
{
    std::vector<Bone> bones;
    bones.reserve(m_Model->boneCount);

    for (int i = 0; i < m_Model->boneCount; i++)
        bones.emplace_back(&m_Model->bones[i]);

    return bones;
}

int Model::GetBoneCount() const
{
    return m_Model->boneCount;
}

Material Model::GetMaterial(int index) const
{
    if (index >= 0 && index < m_Model->materialCount)
        return &m_Model->materials[index];

    return {};
}

std::vector<Material> Model::GetMaterials() const
{
    std::vector<Material> materials;
    materials.reserve(m_Model->materialCount);

    for (int i = 0; i < m_Model->materialCount; i++)
        materials.emplace_back(&m_Model->materials[i]);

    return materials;
}

int Model::GetMaterialCount() const
{
    return m_Model->materialCount;
}

Mesh Model::GetMesh(int index) const
{
    if (index >= 0 && index < m_Model->meshCount)
        return &m_Model->meshes[index];

    return {};
}

std::vector<Mesh> Model::GetMeshes() const
{
    std::vector<Mesh> meshes;
    meshes.reserve(m_Model->meshCount);

    for (int i = 0; i < m_Model->meshCount; i++)
        meshes.emplace_back(&m_Model->meshes[i]);

    return meshes;
}

int Model::GetMeshCount() const
{
    return m_Model->meshCount;
}

AssetType Model::GetType() const
{
    return AssetType::Model;
}

Model::operator ::Model() const
{
    return *m_Model;
}

Model::operator ::Model *() const
{
    return m_Model;
}

} // namespace Lumen