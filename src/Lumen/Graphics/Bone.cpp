#include "Lumen/Graphics/Bone.hpp"

#include "raylib.h"

namespace Lumen
{

Bone::Bone(const ::BoneInfo &bone) : m_Bone(new ::BoneInfo(bone))
{
}

Bone::Bone(::BoneInfo *bone) : m_Bone(bone)
{
}

std::string Bone::GetName() const
{
    return m_Bone->name;
}

int Bone::GetParent() const
{
    return m_Bone->parent;
}

Bone::operator ::BoneInfo() const
{
    return *m_Bone;
}

Bone::operator ::BoneInfo *() const
{
    return m_Bone;
}

} // namespace Lumen