include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(collection_test collectionTests.cpp)

target_link_libraries(collection_test
 PRIVATE
  GTest::GTest)

enable_testing()
add_test(NAME test COMMAND collection_test ${PATCH_NUMBER_CONSTANT})