#include "Lumen/Graphics/Model.hpp"
#include "raylib.h"

namespace Lumen
{

Model::Model(const AssetMetadata &metadata, const ::Model &model)
    : Asset(metadata), m_Instance(CreateScope<::Model>(model))
{
}

Model::~Model()
{
    UnloadModel(*m_Instance);
}

bool Model::IsValid() const
{
    return IsModelReady(*m_Instance);
}

Model::operator ::Model() const
{
    return *m_Instance;
}
} // namespace Lumen