#include "Lumen/Graphics/MeshFactory.hpp"

#include "raylib.h"

namespace Lumen
{

Mesh MeshFactory::CreateCone(float radius, float height, int slices)
{
    return GenMeshCone(radius, height, slices);
}

Mesh MeshFactory::CreateCube(float width, float height, float length)
{
    return GenMeshCube(width, height, length);
}

Mesh MeshFactory::CreateCubicmap(const Image &cubicmap, const Vector3 &cubeSize)
{
    return GenMeshCubicmap(cubicmap, cubeSize);
}

Mesh MeshFactory::CreateCylinder(float radius, float height, int slices)
{
    return GenMeshCylinder(radius, height, slices);
}

Mesh MeshFactory::CreateHeightmap(const Image &heightmap, const Vector3 &size)
{
    return GenMeshHeightmap(heightmap, size);
}

Mesh MeshFactory::CreateHemiSphere(float radius, int rings, int slices)
{
    return GenMeshHemiSphere(radius, rings, slices);
}

Mesh MeshFactory::CreateKnot(float radius, float size, int radSeg, int sides)
{
    return GenMeshKnot(radius, size, radSeg, sides);
}

Mesh MeshFactory::CreatePoly(int sides, float radius)
{
    return GenMeshPoly(sides, radius);
}

Mesh MeshFactory::CreatePlane(float width, float length, int resX, int resZ)
{
    return GenMeshPlane(width, length, resX, resZ);
}

Mesh MeshFactory::CreateSphere(float radius, int rings, int slices)
{
    return GenMeshSphere(radius, rings, slices);
}

Mesh MeshFactory::CreateTorus(float radius, float size, int radSeg, int sides)
{
    return GenMeshTorus(radius, size, radSeg, sides);
}

} // namespace Lumen
