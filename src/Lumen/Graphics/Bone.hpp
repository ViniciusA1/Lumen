#pragma once

#include <string>

struct BoneInfo;

namespace Lumen
{

class Bone
{
public:
    Bone() = default;
    Bone(const ::BoneInfo &bone);
    Bone(::BoneInfo *bone);

    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] int GetParent() const;

    operator ::BoneInfo() const;
    operator ::BoneInfo *() const;

private:
    ::BoneInfo *m_Bone = nullptr;
};

} // namespace Lumen