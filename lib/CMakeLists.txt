configure_file(version.h.in, "${CMAKE_BINARY_DIR}/include/version.h")

add_library(helloWorldLib helloworld.cpp)

target_include_directories(helloWorldLib
    PRIVATE "${CMAKE_BINARY_DIR}/include/"
)

