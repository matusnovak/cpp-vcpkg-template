cmake_minimum_required(VERSION 3.10)
set(CMAKE_MODULE_PATH 
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_LIST_DIR}/modules"
)

project(Example)

option(EXAMPLE_TESTS "Build Example project tests" OFF)

set(CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING "Select build type")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Example)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/ExampleCli)
if(EXAMPLE_TESTS)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/Example)
endif()

