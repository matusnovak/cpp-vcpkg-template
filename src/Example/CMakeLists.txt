cmake_minimum_required(VERSION 3.10)

# Project source files
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../include")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/../../include/${PROJECT_NAME}/*.hpp")

# Add the project source files
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME_LOWER})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

# Install target
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Install target
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../include/${PROJECT_NAME}"
  DESTINATION "include" FILES_MATCHING PATTERN "*.hpp"
)

# Find dependencies
find_package(fmt CONFIG REQUIRED)

# Add dependencies to target
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt fmt::fmt-header-only)

