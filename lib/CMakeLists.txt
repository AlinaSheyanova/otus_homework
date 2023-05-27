configure_file(version.h.in, "${CMAKE_BINARY_DIR}/include/version.h")

add_library(ipFilterLib ipAddres.cpp)

target_include_directories(ipFilterLib
    PRIVATE "${CMAKE_BINARY_DIR}/include/"
)

