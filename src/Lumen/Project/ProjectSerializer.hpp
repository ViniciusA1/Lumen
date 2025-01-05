#pragma once

#include "Lumen/Project/Project.hpp"

namespace Lumen
{

class ProjectSerializer
{
public:
    ProjectSerializer() = default;

    bool Deserialize(Project &project, const Path &path);
    bool Serialize(const Project &project, const Path &path);
};

} // namespace Lumen