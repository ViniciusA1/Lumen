#include "Lumen/Audio/Audio.hpp"

#include "raylib.h"

namespace Lumen
{

void Audio::Init()
{
    InitAudioDevice();
}

void Audio::Shutdown()
{
    CloseAudioDevice();
}

} // namespace Lumen