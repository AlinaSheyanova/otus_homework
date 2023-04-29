cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(helloworld_cli)

if(NOT PATCH_NUMBER_CONSTANT)
    set(PATCH_NUMBER_CONSTANT "unknown")
endif()

add_subdirectory(lib)

include_directories(
    ${CMAKE_BINARY_DIR}/include/ 
    ${PROJECT_SOURCE_DIR}/lib/
)

add_subdirectory(tests)

add_executable(launcher src/main.cpp)

target_link_libraries(launcher
 PRIVATE
  helloWorldLib)


