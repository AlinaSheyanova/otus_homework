include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(sparsematrix_test sparsematrix_test.cpp)

target_link_libraries(sparsematrix_test
 PRIVATE
  GTest::GTest
  SparseMatrixLib)

enable_testing()
add_test(NAME test COMMAND sparsematrix_test ${PATCH_NUMBER_CONSTANT})