#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Math/Vector3.hpp"

struct ma_sound;

namespace Lumen
{

class Audio : public Asset
{
public:
    Audio() = default;
    Audio(const AssetHandle &handle, const ::ma_sound &audio);
    Audio(const AssetHandle &handle, ::ma_sound *audio);
    Audio(const ::ma_sound &audio);
    Audio(::ma_sound *audio);

    [[nodiscard]] bool IsLooping() const;
    [[nodiscard]] bool IsPlaying() const;
    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] float GetCursorPosition() const;
    [[nodiscard]] float GetLengthInSeconds() const;
    [[nodiscard]] float GetPan() const;
    [[nodiscard]] float GetPitch() const;
    [[nodiscard]] Vector3 GetPosition() const;
    [[nodiscard]] AssetType GetType() const final;
    [[nodiscard]] Vector3 GetVelocity() const;
    [[nodiscard]] float GetVolume() const;

    void Seek(float seconds);
    void SetLooping(bool looping);
    void SetMaxDistance(float distance);
    void SetMinDistance(float distance);
    void SetPan(float pan);
    void SetPitch(float pitch);
    void SetPosition(float x, float y, float z);
    void SetPosition(const Vector3 &position);
    void SetVelocity(float x, float y, float z);
    void SetVelocity(const Vector3 &velocity);
    void SetVolume(float volume);

    void Pause();
    void Play();
    void Restart();
    void Stop();

    operator ma_sound() const;
    operator ma_sound *() const;

private:
    ma_sound *m_Audio = nullptr;
};

} // namespace Lumen