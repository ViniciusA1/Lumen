#include "Lumen/Audio/Sound.hpp"

#include "raylib.h"

namespace Lumen
{

Sound::Sound(const ::Sound &Sound) : m_Sound(new ::Sound(Sound))
{
}

Sound::Sound(::Sound *Sound) : m_Sound(Sound)
{
}

bool Sound::IsPlaying() const
{
    return IsSoundPlaying(*m_Sound);
}

bool Sound::IsValid() const
{
    return IsSoundValid(*m_Sound);
}

int Sound::GetSampleCount() const
{
    return m_Sound->frameCount;
}

AudioStream Sound::GetStream() const
{
    return &m_Sound->stream;
}

AssetType Sound::GetType() const
{
    return AssetType::Audio;
}

void Sound::Pause() const
{
    PauseSound(*m_Sound);
}

void Sound::Play() const
{
    PlaySound(*m_Sound);
}

void Sound::Resume() const
{
    ResumeSound(*m_Sound);
}

void Sound::Stop() const
{
    StopSound(*m_Sound);
}

void Sound::SetPan(float pan) const
{
    SetSoundPan(*m_Sound, pan);
}

void Sound::SetPitch(float pitch) const
{
    SetSoundPitch(*m_Sound, pitch);
}

void Sound::SetVolume(float volume) const
{
    SetSoundVolume(*m_Sound, volume);
}

Sound::operator ::Sound() const
{
    return *m_Sound;
}

Sound::operator ::Sound *() const
{
    return m_Sound;
}

} // namespace Lumen