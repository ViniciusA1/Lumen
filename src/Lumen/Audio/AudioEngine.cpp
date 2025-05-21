#include "Lumen/Audio/AudioEngine.hpp"

#include "miniaudio.h"

namespace Lumen
{

static bool s_IsInitialized = false;
static ma_context s_Context;
static ma_device s_Device;
static ma_engine s_Engine;

bool AudioEngine::Init()
{
    if (s_IsInitialized)
        return s_IsInitialized;

    ma_result result;

    result = ma_context_init(nullptr, 0, nullptr, &s_Context);
    if (result != MA_SUCCESS)
        return s_IsInitialized;

    ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = ma_format_f32;
    deviceConfig.playback.channels = 2;
    deviceConfig.sampleRate = 0;
    deviceConfig.dataCallback = nullptr;
    deviceConfig.pUserData = &s_Engine;

    result = ma_device_init(&s_Context, &deviceConfig, &s_Device);
    if (result != MA_SUCCESS)
    {
        ma_context_uninit(&s_Context);
        return s_IsInitialized;
    }

    ma_engine_config engineConfig = ma_engine_config_init();
    result = ma_engine_init(&engineConfig, &s_Engine);
    if (result != MA_SUCCESS)
    {
        ma_device_uninit(&s_Device);
        ma_context_uninit(&s_Context);
        return s_IsInitialized;
    }

    result = ma_device_start(&s_Device);
    if (result != MA_SUCCESS)
    {
        ma_engine_uninit(&s_Engine);
        ma_device_uninit(&s_Device);
        ma_context_uninit(&s_Context);
        return s_IsInitialized;
    }

    s_IsInitialized = true;
    return s_IsInitialized;
}

void AudioEngine::Shutdown()
{
    ma_device_uninit(&s_Device);
    ma_engine_uninit(&s_Engine);
    ma_context_uninit(&s_Context);
}

ma_sound AudioEngine::LoadAudio(const Path &path)
{
    ma_sound sound;
    ma_result result = ma_sound_init_from_file(&s_Engine, path.String().c_str(), 0,
                                               nullptr, nullptr, &sound);

    if (result != MA_SUCCESS)
        return {};

    return sound;
}

void AudioEngine::UnloadAudio(ma_sound &audio)
{
    ma_sound_uninit(&audio);
}

} // namespace Lumen