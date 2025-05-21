#pragma once

#include "Lumen/File/Path.hpp"

struct ma_sound;

namespace Lumen
{

class AudioEngine
{
public:
    AudioEngine() = delete;

public:
    static bool Init();
    static void Shutdown();

    static ma_sound LoadAudio(const Path &path);
    static void UnloadAudio(ma_sound &audio);
};

} // namespace Lumen