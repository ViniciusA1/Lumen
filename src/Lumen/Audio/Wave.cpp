#include "Lumen/Audio/Wave.hpp"

#include "raylib.h"

namespace Lumen
{

Wave::Wave(const ::Wave &wave) : m_Wave(new ::Wave(wave))
{
}

Wave::Wave(::Wave *wave) : m_Wave(wave)
{
}

bool Wave::IsValid() const
{
    return IsWaveValid(*m_Wave);
}

int Wave::GetChannels() const
{
    return m_Wave->channels;
}

std::span<unsigned char> Wave::GetData() const
{
    return {
        reinterpret_cast<unsigned char *>(m_Wave->data),
        m_Wave->frameCount * m_Wave->channels * (m_Wave->sampleSize / 8),
    };
}

int Wave::GetSampleCount() const
{
    return m_Wave->frameCount;
}

int Wave::GetSampleRate() const
{
    return m_Wave->sampleRate;
}

int Wave::GetSampleSize() const
{
    return m_Wave->sampleSize;
}

AssetType Wave::GetType() const
{
    return AssetType::Audio;
}

void Wave::Crop(int initFrame, int finalFrame)
{
    ::WaveCrop(m_Wave, initFrame, finalFrame);
}

void Wave::Format(int sampleRate, int sampleSize, int channels)
{
    ::WaveFormat(m_Wave, sampleRate, sampleSize, channels);
}

Wave::operator ::Wave() const
{
    return *m_Wave;
}

Wave::operator ::Wave *() const
{
    return m_Wave;
}

} // namespace Lumen