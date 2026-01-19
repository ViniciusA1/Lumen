#include "Lumen/Asset/Importer/DefaultImporter.hpp"

#include "raylib.h"

namespace Lumen::DefaultAssetImporter
{

template <> Font Import()
{
    return ::GetFontDefault();
}

template <> Image Import()
{
    constexpr int width = 64;
    constexpr int height = 64;
    return ::GenImageColor(width, height, WHITE);
}

template <> Material Import()
{
    return LoadMaterialDefault();
}

template <> Mesh Import()
{
    return GenMeshCube(1.0f, 1.0f, 1.0f);
}

template <> Music Import()
{
    Wave wave = Import<Wave>();
    Music music = LoadMusicStreamFromMemory(".wav", wave.GetData().data(),
                                            wave.GetSampleCount() * sizeof(short));
    return music;
}

template <> Shader Import()
{
    return {};
}

template <> Sound Import()
{
    Wave wave = Import<Wave>();
    Sound sound = LoadSoundFromWave(wave);
    UnloadWave(wave);
    return sound;
}

template <> Texture2D Import()
{
    constexpr int width = 64;
    constexpr int height = 64;
    ::Image image = ::GenImageColor(width, height, WHITE);
    ::Texture2D texture = ::LoadTextureFromImage(image);
    ::UnloadImage(image);
    return texture;
}

template <> Wave Import()
{
    const int sampleRate = 44100;
    const int sampleCount = sampleRate;
    const int sampleSize = 16;
    const int channels = 1;

    auto *samples = (short *)MemAlloc(sampleCount * sizeof(short));
    for (int i = 0; i < sampleCount; i++)
        samples[i] = 0;

    ::Wave wave;
    wave.data = samples;
    wave.frameCount = sampleCount;
    wave.sampleRate = sampleRate;
    wave.sampleSize = sampleSize;
    wave.channels = channels;
    return wave;
}

} // namespace Lumen::DefaultAssetImporter