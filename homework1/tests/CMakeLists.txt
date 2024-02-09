include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(helloworld_test helloworld_test.cpp)

target_link_libraries(helloworld_test
 PRIVATE
  GTest::GTest
  helloWorldLib)

enable_testing()
add_test(NAME test COMMAND helloworld_test ${PATCH_NUMBER_CONSTANT})