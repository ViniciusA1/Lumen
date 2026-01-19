#include "Lumen/Audio/AudioStream.hpp"

#include "raylib.h"

namespace Lumen
{

AudioStream::AudioStream(const ::AudioStream &AudioStream)
    : m_AudioStream(new ::AudioStream(AudioStream))
{
}

AudioStream::AudioStream(::AudioStream *AudioStream) : m_AudioStream(AudioStream)
{
}

bool AudioStream::IsPlaying() const
{
    return IsAudioStreamPlaying(*m_AudioStream);
}

bool AudioStream::IsProcessed() const
{
    return IsAudioStreamProcessed(*m_AudioStream);
}

bool AudioStream::IsValid() const
{
    return IsAudioStreamValid(*m_AudioStream);
}

int AudioStream::GetChannelCount() const
{
    return m_AudioStream->channels;
}

int AudioStream::GetSampleRate() const
{
    return m_AudioStream->sampleRate;
}

int AudioStream::GetSampleSize() const
{
    return m_AudioStream->sampleSize;
}

AssetType AudioStream::GetType() const
{
    return AssetType::Audio;
}

void AudioStream::Pause() const
{
    PauseAudioStream(*m_AudioStream);
}

void AudioStream::Play() const
{
    PlayAudioStream(*m_AudioStream);
}

void AudioStream::Resume() const
{
    ResumeAudioStream(*m_AudioStream);
}

void AudioStream::Stop() const
{
    StopAudioStream(*m_AudioStream);
}

void AudioStream::SetPan(float pan) const
{
    SetAudioStreamPan(*m_AudioStream, pan);
}

void AudioStream::SetPitch(float pitch) const
{
    SetAudioStreamPitch(*m_AudioStream, pitch);
}

void AudioStream::SetVolume(float volume) const
{
    SetAudioStreamVolume(*m_AudioStream, volume);
}

void AudioStream::Update(const void *data, int frameCount) const
{
    UpdateAudioStream(*m_AudioStream, data, frameCount);
}

AudioStream::operator ::AudioStream() const
{
    return *m_AudioStream;
}

AudioStream::operator ::AudioStream *() const
{
    return m_AudioStream;
}

} // namespace Lumen