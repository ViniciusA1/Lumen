#include "Lumen/Graphics/ModelAnimation.hpp"

#include "raylib.h"

namespace Lumen
{

ModelAnimation::ModelAnimation(::ModelAnimation *modelAnimation)
    : m_ModelAnimation(modelAnimation)
{
}

int ModelAnimation::GetBoneCount() const
{
    return m_ModelAnimation->boneCount;
}

int ModelAnimation::GetFrameCount() const
{
    return m_ModelAnimation->frameCount;
}

std::string ModelAnimation::GetName() const
{
    return m_ModelAnimation->name;
}

ModelAnimation::operator ::ModelAnimation() const
{
    return *m_ModelAnimation;
}

ModelAnimation::operator ::ModelAnimation *() const
{
    return m_ModelAnimation;
}

} // namespace Lumen