cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(homework)

if(NOT PATCH_NUMBER_CONSTANT)
    set(PATCH_NUMBER_CONSTANT 1)
endif()

include_directories(${CMAKE_BINARY_DIR}/include/)

configure_file(version.h.in, "include/version.h")

add_executable(launcher main.cpp)

