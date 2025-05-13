#pragma once

#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Math/Vector3.hpp"

namespace Lumen
{

class MeshFactory
{
public:
    MeshFactory() = delete;

public:
    static Mesh CreateCone(float radius, float height, int slices);
    static Mesh CreateCube(float width, float height, float length);
    static Mesh CreateCubicmap(const Image &cubicmap, const Vector3 &cubeSize);
    static Mesh CreateCylinder(float radius, float height, int slices);
    static Mesh CreateHeightmap(const Image &heightmap, const Vector3 &size);
    static Mesh CreateHemiSphere(float radius, int rings, int slices);
    static Mesh CreateKnot(float radius, float size, int radSeg, int sides);
    static Mesh CreatePoly(int sides, float radius);
    static Mesh CreatePlane(float width, float length, int resX, int resZ);
    static Mesh CreateSphere(float radius, int rings, int slices);
    static Mesh CreateTorus(float radius, float size, int radSeg, int sides);
};

} // namespace Lumen