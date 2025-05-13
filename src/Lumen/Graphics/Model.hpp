#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Bone.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/ModelAnimation.hpp"

#include <vector>

struct Model;

namespace Lumen
{

class Model : public Asset
{
public:
    Model() = default;
    Model(const AssetHandle &handle, const ::Model &model);
    Model(const AssetHandle &handle, ::Model *model);
    Model(const ::Model &model);
    Model(::Model *model);

    Model(const AssetHandle &handle, const ::Model &model, ::ModelAnimation *animation,
          int animationCount);
    Model(const AssetHandle &handle, ::Model *model, ::ModelAnimation *animation,
          int animationCount);
    Model(const ::Model &model, ::ModelAnimation *animation, int animationCount);
    Model(::Model *model, ::ModelAnimation *animation, int animationCount);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] ModelAnimation GetAnimation(int index) const;
    [[nodiscard]] std::vector<ModelAnimation> GetAnimations() const;
    [[nodiscard]] int GetAnimationCount() const;
    [[nodiscard]] Bone GetBone(int index) const;
    [[nodiscard]] std::vector<Bone> GetBones() const;
    [[nodiscard]] int GetBoneCount() const;
    [[nodiscard]] Material GetMaterial(int index) const;
    [[nodiscard]] std::vector<Material> GetMaterials() const;
    [[nodiscard]] int GetMaterialCount() const;
    [[nodiscard]] Mesh GetMesh(int index) const;
    [[nodiscard]] std::vector<Mesh> GetMeshes() const;
    [[nodiscard]] int GetMeshCount() const;
    [[nodiscard]] AssetType GetType() const final;

    operator ::Model() const;
    operator ::Model *() const;

private:
    ::Model *m_Model = nullptr;
    ::ModelAnimation *m_ModelAnimation = nullptr;
    int m_AnimationCount = 0;
};

} // namespace Lumen