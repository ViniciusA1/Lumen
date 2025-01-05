#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Math/Vector3.hpp"

#include "yaml-cpp/yaml.h"

namespace YAML
{

template <> struct convert<Lumen::UUID>
{
    static Node encode(const Lumen::UUID &uuid)
    {
        Node node;
        node = (uint64_t)uuid;
        return node;
    }

    static bool decode(const Node &node, Lumen::UUID &uuid)
    {
        if (!node.IsScalar())
            return false;

        uuid = Lumen::UUID(node.as<uint64_t>());
        return true;
    }
};

template <> struct convert<Lumen::Vector3>
{
    static Node encode(const Lumen::Vector3 &vec)
    {
        Node node;
        node["x"] = vec.x;
        node["y"] = vec.y;
        node["z"] = vec.z;
        return node;
    }

    static bool decode(const Node &node, Lumen::Vector3 &vec)
    {
        if (!node.IsMap() || !node["x"] || !node["y"] || !node["z"])
            return false;

        vec.x = node["x"].as<float>();
        vec.y = node["y"].as<float>();
        vec.z = node["z"].as<float>();
        return true;
    }
};

} // namespace YAML