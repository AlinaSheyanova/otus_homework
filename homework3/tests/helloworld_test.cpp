#include <gtest/gtest.h>
#include <sstream>

#include "helloworld.h"

static ::std::string expected_version("unknown");

TEST(RunHelloWorld, Version)
{
    const auto actual = HelloWorld::getVersion();
    ASSERT_EQ(actual, expected_version);
}

TEST(RunHelloWorld, FullText)
{
    const auto expected = "build " + expected_version + "\nHello, World!\n";
    const auto actual = HelloWorld::getText();
    ASSERT_EQ(actual, expected);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    if (argc > 1)
        expected_version = argv[1];
    return RUN_ALL_TESTS();
}