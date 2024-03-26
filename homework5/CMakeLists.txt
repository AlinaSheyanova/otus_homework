cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(vector_editor)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)


include_directories(
    ${CMAKE_BINARY_DIR}/include/
)

add_subdirectory(src)
