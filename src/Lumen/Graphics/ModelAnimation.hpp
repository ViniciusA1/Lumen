#pragma once

#include <string>

struct ModelAnimation;

namespace Lumen
{

class ModelAnimation
{
public:
    ModelAnimation() = default;
    ModelAnimation(::ModelAnimation *modelAnimation);

    [[nodiscard]] int GetBoneCount() const;
    [[nodiscard]] int GetFrameCount() const;
    [[nodiscard]] std::string GetName() const;

    operator ::ModelAnimation() const;
    operator ::ModelAnimation *() const;

private:
    ::ModelAnimation *m_ModelAnimation = nullptr;
};

} // namespace Lumen