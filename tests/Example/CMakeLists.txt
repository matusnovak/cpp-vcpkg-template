cmake_minimum_required(VERSION 3.10)

# Project source files
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add the project source files
add_executable(${PROJECT_NAME}Tests ${SOURCES})
set_target_properties(${PROJECT_NAME}Tests PROPERTIES CXX_STANDARD 17)
add_test(NAME ${PROJECT_NAME}Tests COMMAND ${PROJECT_NAME}Tests)

# Find dependencies
find_package(Catch2 REQUIRED)

# Add dependencies to target
target_link_libraries(${PROJECT_NAME}Tests PRIVATE ${PROJECT_NAME} Catch2::Catch2)
