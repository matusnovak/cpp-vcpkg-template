cmake_minimum_required(VERSION 3.10)
project(ExampleCli)

# Project source files
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add the project source files
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Get the version string based on the git tags
# and add it as macro definition
execute_process(
  COMMAND git describe --always 
  OUTPUT_VARIABLE VERSION
  ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(NOT VERSION)
  set(VERSION "1.0.0")
endif()
message("-- Setting Doxybook version to: ${VERSION}")
target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION=${VERSION})

# Install target
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Find dependencies
find_package(ArgAgg REQUIRED)

# Add dependencies to target
target_link_libraries(${PROJECT_NAME} PRIVATE Example ArgAgg)

