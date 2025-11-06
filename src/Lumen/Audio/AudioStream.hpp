#pragma once

#include "Lumen/Asset/Asset.hpp"

struct AudioStream;

namespace Lumen
{

class AudioStream : public Asset
{
public:
    AudioStream() = default;
    AudioStream(const ::AudioStream &AudioStream);
    AudioStream(::AudioStream *AudioStream);

    [[nodiscard]] bool IsPlaying() const;
    [[nodiscard]] bool IsProcessed() const;
    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] int GetChannelCount() const;
    [[nodiscard]] int GetSampleRate() const;
    [[nodiscard]] int GetSampleSize() const;
    [[nodiscard]] AssetType GetType() const final;

    void Pause() const;
    void Play() const;
    void Resume() const;
    void Stop() const;

    void SetPan(float pan) const;
    void SetPitch(float pitch) const;
    void SetVolume(float volume) const;

    void Update(const void *data, int frameCount) const;

    operator ::AudioStream() const;
    operator ::AudioStream *() const;

private:
    ::AudioStream *m_AudioStream = nullptr;
};

} // namespace Lumen