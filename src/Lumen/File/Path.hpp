#pragma once

#include <filesystem>

namespace Lumen
{

class Path
{
public:
    Path();
    Path(std::filesystem::path path);

    void Clear();
    void RemoveFilename();
    void ReplaceFilename(const Path &filename);
    void ReplaceExtension(const std::string &extension);
    void Swap(Path &other);

    [[nodiscard]] Path RootName() const;
    [[nodiscard]] Path RootDirectory() const;
    [[nodiscard]] Path RootPath() const;
    [[nodiscard]] Path RelativePath() const;
    [[nodiscard]] Path ParentPath() const;
    [[nodiscard]] Path Filename() const;
    [[nodiscard]] Path Stem() const;
    [[nodiscard]] Path Extension() const;
    [[nodiscard]] std::string String() const;

    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] bool HasRootPath() const;
    [[nodiscard]] bool HasRootName() const;
    [[nodiscard]] bool HasRootDirectory() const;
    [[nodiscard]] bool HasRelativePath() const;
    [[nodiscard]] bool HasParentPath() const;
    [[nodiscard]] bool HasFilename() const;
    [[nodiscard]] bool HasStem() const;
    [[nodiscard]] bool HasExtension() const;
    [[nodiscard]] bool IsAbsolute() const;
    [[nodiscard]] bool IsRelative() const;

    operator std::filesystem::path() const;
    Path &operator=(const std::string &path);
    Path &operator=(const std::filesystem::path &path);
    bool operator==(const Path &other) const;
    bool operator!=(const Path &other) const;
    Path operator/(const std::string &other) const;
    Path operator/(const Path &other) const;
    Path &operator/=(const std::string &other);
    Path &operator/=(const Path &other);
    Path &operator+=(const std::string &str);

private:
    std::filesystem::path m_Path;
};

} // namespace Lumen