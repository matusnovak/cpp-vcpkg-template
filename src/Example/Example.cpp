#include "../../include/Example/Example.hpp"
#include <fmt/format.h>

using namespace Example;
namespace fs = std::filesystem;

Foo::Foo(const fs::path& path) : path(path) {
}

Foo::~Foo() = default;

std::vector<fs::path> Foo::get() const {
    std::vector<fs::path> ret;
    for (const auto& p : fs::directory_iterator(path)) {
        ret.push_back(p);
    }
    return ret;
}
