include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(bulk_test bulk_test.cpp)

target_link_libraries(bulk_test
 PRIVATE
  GTest::GTest
  BulkLib)

enable_testing()
add_test(NAME test COMMAND bulk_test ${PATCH_NUMBER_CONSTANT})