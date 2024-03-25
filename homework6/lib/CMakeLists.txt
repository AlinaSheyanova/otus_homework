add_library(SparseMatrixLib SparseMatrix.h)

target_include_directories(SparseMatrixLib
    PRIVATE "${CMAKE_BINARY_DIR}/include/"
)

set_target_properties(SparseMatrixLib PROPERTIES LINKER_LANGUAGE CXX)