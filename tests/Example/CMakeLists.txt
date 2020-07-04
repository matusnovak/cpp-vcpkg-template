cmake_minimum_required(VERSION 3.10)
project(ExampleTests)

# Project source files
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add the project source files
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# Find dependencies
find_package(Catch2 REQUIRED)

# Add dependencies to target
target_link_libraries(${PROJECT_NAME} PRIVATE Example Catch2::Catch2)
