#include "Lumen/Audio/Audio.hpp"

#include "miniaudio.h"

namespace Lumen
{

Audio::Audio(const AssetHandle &handle, const ::ma_sound &audio)
{
}

Audio::Audio(const AssetHandle &handle, ::ma_sound *audio)
{
}

Audio::Audio(const ::ma_sound &audio)
{
}

Audio::Audio(::ma_sound *audio)
{
}

bool Audio::IsLooping() const
{
    return ma_sound_is_looping(m_Audio);
}

bool Audio::IsPlaying() const
{
    return ma_sound_is_playing(m_Audio);
}

bool Audio::IsValid() const
{
    return m_Audio;
}

float Audio::GetCursorPosition() const
{
    float cursorPos;
    ma_sound_get_cursor_in_seconds(m_Audio, &cursorPos);
    return cursorPos;
}

float Audio::GetLengthInSeconds() const
{
    float seconds;
    ma_sound_get_length_in_seconds(m_Audio, &seconds);
    return seconds;
}

float Audio::GetPan() const
{
    return ma_sound_get_pan(m_Audio);
}

float Audio::GetPitch() const
{
    return ma_sound_get_pitch(m_Audio);
}

Vector3 Audio::GetPosition() const
{
    ma_vec3f vec = ma_sound_get_position(m_Audio);
    return {vec.x, vec.y, vec.z};
}

AssetType Audio::GetType() const
{
    return AssetType::Audio;
}

Vector3 Audio::GetVelocity() const
{
    ma_vec3f vec = ma_sound_get_velocity(m_Audio);
    return {vec.x, vec.y, vec.z};
}

float Audio::GetVolume() const
{
    return ma_sound_get_volume(m_Audio);
}

void Audio::Seek(float seconds)
{
    ma_sound_seek_to_second(m_Audio, seconds);
}

void Audio::SetLooping(bool looping)
{
    ma_sound_set_looping(m_Audio, looping);
}

void Audio::SetMaxDistance(float distance)
{
    ma_sound_set_max_distance(m_Audio, distance);
}

void Audio::SetMinDistance(float distance)
{
    ma_sound_set_min_distance(m_Audio, distance);
}

void Audio::SetPan(float pan)
{
    ma_sound_set_pan(m_Audio, pan);
}

void Audio::SetPitch(float pitch)
{
    ma_sound_set_pitch(m_Audio, pitch);
}

void Audio::SetPosition(float x, float y, float z)
{
    ma_sound_set_position(m_Audio, x, y, z);
}

void Audio::SetPosition(const Vector3 &position)
{
    ma_sound_set_position(m_Audio, position.x, position.y, position.z);
}

void Audio::SetVelocity(float x, float y, float z)
{
    ma_sound_set_velocity(m_Audio, x, y, z);
}

void Audio::SetVelocity(const Vector3 &velocity)
{
    ma_sound_set_velocity(m_Audio, velocity.x, velocity.y, velocity.z);
}

void Audio::SetVolume(float volume)
{
    ma_sound_set_volume(m_Audio, volume);
}

void Audio::Pause()
{
    ma_sound_stop(m_Audio);
}

void Audio::Play()
{
    ma_sound_start(m_Audio);
}

void Audio::Restart()
{
    Stop();
    Play();
}

void Audio::Stop()
{
    ma_sound_stop(m_Audio);
    ma_sound_seek_to_pcm_frame(m_Audio, 0);
}

Audio::operator ma_sound() const
{
    return *m_Audio;
}

Audio::operator ma_sound *() const
{
    return m_Audio;
}

} // namespace Lumen