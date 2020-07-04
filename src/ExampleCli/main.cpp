#include <Example/Example.hpp>
#include <argagg/argagg.hpp>
#include <fmt/format.h>
#include <iostream>

#define xstr(a) str(a)
#define str(a) #a

#ifdef VERSION
static const std::string version = xstr(VERSION);
#else
static const std::string version = "unknown";
#endif

static argagg::parser argparser{{{"help", {"-h", "--help"}, "Shows this help message", 0},
                                 {"version", {"-v", "--version"}, "Get the build version", 0},
                                 {"foo", {"-f", "--foo"}, "Do the foo thing", 1}}};

using namespace Example;

int main(const int argc, char* argv[]) {
    try {
        const auto args = argparser.parse(argc, argv);
        if (args["help"]) {
            std::cerr << argparser;
        }

        else if (args["version"]) {
            std::cout << version << std::endl;
        }

        else if (args["foo"]) {
            Foo foo(args["version"].as<std::string>());
            for (const auto& p : foo.get()) {
                std::cout << fmt::format("Found: {}", p.string()) << std::endl;
            }
        }

        else {
            std::cerr << argparser;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
