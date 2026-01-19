#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Audio/AudioStream.hpp"

struct Music;

namespace Lumen
{

class Music : public Asset
{
public:
    Music() = default;
    Music(const ::Music &Music);
    Music(::Music *Music);

    [[nodiscard]] bool IsLooping() const;
    [[nodiscard]] bool IsPlaying() const;
    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] float GetLength() const;
    [[nodiscard]] int GetSampleCount() const;
    [[nodiscard]] AudioStream GetStream() const;
    [[nodiscard]] float GetTimePlayed() const;
    [[nodiscard]] AssetType GetType() const final;

    void Pause() const;
    void Play() const;
    void Resume() const;
    void Stop() const;

    void SetLooping(bool looping) const;
    void SetPan(float pan) const;
    void SetPitch(float pitch) const;
    void SetVolume(float volume) const;

    void Seek(float position) const;
    void Update() const;

    operator ::Music() const;
    operator ::Music *() const;

private:
    ::Music *m_Music = nullptr;
};

} // namespace Lumen