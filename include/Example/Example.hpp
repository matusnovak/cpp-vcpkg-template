#pragma once

#include <filesystem>
#include <vector>

namespace Example {
class Foo {
public:
    explicit Foo(const std::filesystem::path& path);
    virtual ~Foo();

    std::vector<std::filesystem::path> get() const;

private:
    std::filesystem::path path;
};
} // namespace Example
