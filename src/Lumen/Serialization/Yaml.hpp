#pragma once

#include "Lumen/File/Path.hpp"

#if WIN32
#define YAML_CPP_STATIC_DEFINE
#endif
#include "yaml-cpp/yaml.h"

namespace Lumen
{

class Yaml
{
public:
    enum class EmitterStyle
    {
        Default,
        Block,
        Flow
    };

public:
    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Yaml;
        using difference_type = std::ptrdiff_t;
        using pointer = Yaml *;
        using reference = Yaml &;

        explicit Iterator(YAML::iterator it);

        Yaml operator*() const;
        Iterator &operator++();

        bool operator!=(const Iterator &other) const;

    private:
        YAML::iterator m_Iterator;
    };

    class ConstIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Yaml;
        using difference_type = std::ptrdiff_t;
        using pointer = const Yaml *;
        using reference = const Yaml &;

        explicit ConstIterator(YAML::const_iterator it);

        Yaml operator*() const;
        ConstIterator &operator++();

        bool operator!=(const ConstIterator &other) const;

    private:
        YAML::const_iterator m_Iterator;
    };

public:
    Yaml() = default;
    Yaml(const YAML::Node &node);

    [[nodiscard]] bool Contains(const std::string &key) const;
    template <typename T> [[nodiscard]] bool Is() const;
    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsSequence() const;

    template <typename T> T GetOrDefault(const T &defaultValue) const;
    [[nodiscard]] std::size_t GetSize() const;

    void SetStyle(Yaml::EmitterStyle style);
    void PushBack(const Yaml &yaml);
    template <typename T> void PushBack(const T &value);

    template <typename T> T As() const;
    void Clear();

    static Yaml FromFile(const Path &path);
    bool ToFile(const Path &path);

    Iterator begin();
    Iterator end();
    [[nodiscard]] ConstIterator begin() const;
    [[nodiscard]] ConstIterator end() const;

    template <typename T> Yaml &operator<<(const T &obj);
    template <typename T> const Yaml &operator>>(T &obj) const;

    template <typename T> const Yaml operator[](const T &key) const;
    template <typename T> Yaml operator[](const T &key);

    operator YAML::Node() const;

private:
    YAML::Node m_Data;
};

} // namespace Lumen