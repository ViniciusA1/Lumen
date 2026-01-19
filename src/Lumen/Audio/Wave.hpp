#pragma once

#include "Lumen/Asset/Asset.hpp"

#include <span>

struct Wave;

namespace Lumen
{

class Wave : public Asset
{
public:
    Wave() = default;
    Wave(const ::Wave &wave);
    Wave(::Wave *wave);

    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] int GetChannels() const;
    [[nodiscard]] std::span<unsigned char> GetData() const;
    [[nodiscard]] int GetSampleCount() const;
    [[nodiscard]] int GetSampleRate() const;
    [[nodiscard]] int GetSampleSize() const;
    [[nodiscard]] AssetType GetType() const final;

    void Crop(int initFrame, int finalFrame);
    void Format(int sampleRate, int sampleSize, int channels);

    operator ::Wave() const;
    operator ::Wave *() const;

private:
    ::Wave *m_Wave = nullptr;
};

} // namespace Lumen