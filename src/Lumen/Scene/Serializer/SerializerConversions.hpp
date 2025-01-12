#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Graphics/Color.hpp"
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
        node.SetStyle(YAML::EmitterStyle::Flow);
        node.push_back(vec.x);
        node.push_back(vec.y);
        node.push_back(vec.z);
        return node;
    }

    static bool decode(const Node &node, Lumen::Vector3 &vec)
    {
        if (!node.IsSequence() || node.size() != 3)
            return false;

        vec.x = node[0].as<float>();
        vec.y = node[1].as<float>();
        vec.z = node[2].as<float>();
        return true;
    }
};

template <> struct convert<Lumen::Color>
{
    static Node encode(const Lumen::Color &color)
    {
        Node node;
        node.SetStyle(YAML::EmitterStyle::Flow);
        node.push_back(color.r);
        node.push_back(color.g);
        node.push_back(color.b);
        node.push_back(color.a);
        return node;
    }

    static bool decode(const Node &node, Lumen::Color &color)
    {
        if (!node.IsSequence() || node.size() != 4)
            return false;

        color.r = node[0].as<float>();
        color.g = node[1].as<float>();
        color.b = node[2].as<float>();
        color.a = node[3].as<float>();
        return true;
    }
};

} // namespace YAML