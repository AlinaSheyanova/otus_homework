add_library(BulkLib processor.cpp reader.cpp writer.cpp)

target_include_directories(BulkLib
    PRIVATE "${CMAKE_BINARY_DIR}/include/"
)

