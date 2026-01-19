#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Audio/AudioStream.hpp"

struct Sound;

namespace Lumen
{

class Sound : public Asset
{
public:
    Sound() = default;
    Sound(const ::Sound &sound);
    Sound(::Sound *sound);

    [[nodiscard]] bool IsPlaying() const;
    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] int GetSampleCount() const;
    [[nodiscard]] AudioStream GetStream() const;
    [[nodiscard]] AssetType GetType() const final;

    void Pause() const;
    void Play() const;
    void Resume() const;
    void Stop() const;

    void SetPan(float pan) const;
    void SetPitch(float pitch) const;
    void SetVolume(float volume) const;

    operator ::Sound() const;
    operator ::Sound *() const;

private:
    ::Sound *m_Sound = nullptr;
};

} // namespace Lumen