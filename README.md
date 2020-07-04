# C++ Vcpkg template with GitHub actions

[![build](https://github.com/matusnovak/cpp-vcpkg-template/workflows/build/badge.svg)](https://github.com/matusnovak/cpp-vcpkg-template/actions)

This is a minimum working template project for C++ with vcpkg and GitHub actions. This template uses the minimum amount of configuration to create a working C++ project out of the box. You don't need to configure anything (just rename `example` occurances to whatever you want), it just works.

**Features:**

* Uses CMake
* Each commit is automatically compiled on Windows (x86 + x64), Linux, and OSX via GitHub actions.
* Each new tag is automatically released into [GitHub Releases](https://github.com/matusnovak/cpp-vcpkg-template/releases) with the built binary, library, and header files.
* Uses vcpkg to handle dependencies and also uses cache on the GitHub actions to cache vcpkg install directory. This is done based on the vcpkg.txt file via hashing.
* Automatically creates a log on the release. This log is created from the last tag to the latest tag (latest tag = the tag currently being compiled). This ensures that the releases contain the all of commit logs between releases.
* The example project is structured as: library + cli + tests
* Everything is automatic, minimal configuration, works out of the box.
* Releases are packaged with `bin`, `include`, and `lib` folders that contain their respective files. The `bin` contains the binary created in the `src/ExampleCli` folder. The `include` folder contains the `include` directory. The `lib` folder contains the static library created in `src/Example`.
* Testing via Catch2

## F.A.Q

#### _How do I use this?_

Fork (prefer to use the template button) into your GitHub account. The only thing you will need to do is to rename all occuranced of `example` word to whatever you want to name your new awesome project (unless you want your project to be called "example"). Note that you have to rename both `example` and `Example` occurances. That's it. Your GitHub actions will enable automatically. No additional configuration needed for the GitHub actions workflow.

#### _Why another C++ template project?_

Find me a template project that does not have 10K lines of unnecessary configuration, that works out of the box, publishes the artifacts to GitHub releases with automatic changelog, uses no scripting language to do it, and is configured to automatically compiled to Windows (x64 + x86) + Linux + OSX.

#### _Why the static library and the CLI target?_

The `ExampleCli` is just an example to create a binary executable. I wanted to create a C++ example project where the output is a binary executable, but to have tests at the same time. You can compile the tests with the same source files as the output executable, but you would be compiling the source files twice -> for creating the executable and for creating the tests. Splitting it into a static library and an executable ensures that the core logic is in the library which you can link in your tests. Reduces the compile time in big projects a lot. The "CLI" here is just an example usage of that binary. It can be a GUI app, whatever.

#### _Why CMake?_

It's the best thing we have at the moment, plus it works with vcpkg, and works out of the box with Visual Studio, CLion, and many other editors.

#### _What is vcpkg?_

A C++ library manager made by Microsoft: [https://github.com/microsoft/vcpkg](https://github.com/microsoft/vcpkg)


## License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
