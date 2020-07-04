cmake_minimum_required(VERSION 3.10)
set(CMAKE_MODULE_PATH 
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_LIST_DIR}/modules"
)

project(Example)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

option(EXAMPLE_TESTS "Build ${PROJECT_NAME} tests" ON)

set(CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING "Select build type")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}Cli)
if(EXAMPLE_TESTS)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/${PROJECT_NAME})
endif()

