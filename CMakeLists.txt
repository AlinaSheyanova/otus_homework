cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(helloworld)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

if(NOT PATCH_NUMBER_CONSTANT)
    set(PATCH_NUMBER_CONSTANT "unknown")
endif()

add_subdirectory(lib)

include_directories(
    ${CMAKE_BINARY_DIR}/include/ 
    ${PROJECT_SOURCE_DIR}/lib/
)

add_subdirectory(tests)

add_subdirectory(src)
