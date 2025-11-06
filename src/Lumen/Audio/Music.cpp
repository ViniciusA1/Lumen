#include "Lumen/Audio/Music.hpp"

#include "raylib.h"

namespace Lumen
{

Music::Music(const ::Music &Music) : m_Music(new ::Music(Music))
{
}

Music::Music(::Music *Music) : m_Music(Music)
{
}

bool Music::IsLooping() const
{
    return m_Music->looping;
}

bool Music::IsPlaying() const
{
    return IsMusicStreamPlaying(*m_Music);
}

bool Music::IsValid() const
{
    return IsMusicValid(*m_Music);
}

float Music::GetLength() const
{
    return GetMusicTimeLength(*m_Music);
}

int Music::GetSampleCount() const
{
    return m_Music->frameCount;
}

AudioStream Music::GetStream() const
{
    return &m_Music->stream;
}

float Music::GetTimePlayed() const
{
    return GetMusicTimePlayed(*m_Music);
}

AssetType Music::GetType() const
{
    return AssetType::Audio;
}

void Music::Pause() const
{
    PauseMusicStream(*m_Music);
}

void Music::Play() const
{
    PlayMusicStream(*m_Music);
}

void Music::Resume() const
{
    ResumeMusicStream(*m_Music);
}

void Music::Stop() const
{
    StopMusicStream(*m_Music);
}

void Music::SetLooping(bool looping) const
{
    m_Music->looping = looping;
}

void Music::SetPan(float pan) const
{
    SetMusicPan(*m_Music, pan);
}

void Music::SetPitch(float pitch) const
{
    SetMusicPitch(*m_Music, pitch);
}

void Music::SetVolume(float volume) const
{
    SetMusicVolume(*m_Music, volume);
}

void Music::Seek(float position) const
{
    SeekMusicStream(*m_Music, position);
}

void Music::Update() const
{
    UpdateMusicStream(*m_Music);
}

Music::operator ::Music() const
{
    return *m_Music;
}

Music::operator ::Music *() const
{
    return m_Music;
}

} // namespace Lumen