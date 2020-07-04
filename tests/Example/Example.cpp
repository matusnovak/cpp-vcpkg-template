#include <Example/Example.hpp>
#include <catch2/catch.hpp>

using namespace Example;

TEST_CASE("Foo") {
    Foo foo(".");
    const auto files = foo.get();
    REQUIRE(files.size() > 0);
}
