#include <gtest/gtest.h>
#include <vector>

#include "ip_to_string.h"

TEST(IP2String, uint8_t)
{
    std::string expected = "255";
    std::string actual = ip_to_string( int8_t{-1} );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, int16_t)
{
    std::string expected = "0.0";
    std::string actual = ip_to_string( int16_t{0} );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, int32_t)
{
    std::string expected = "127.0.0.1";
    std::string actual = ip_to_string( int32_t{2130706433} );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, int64_t)
{
    std::string expected = "123.45.67.89.101.112.131.41";
    std::string actual = ip_to_string( int64_t{8875824491850138409} );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, std_string)
{
    std::string expected = "Hello, World!";
    std::string actual = ip_to_string( std::string{"Hello, World!"});
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, std_vector_int)
{
    std::string expected = "100.200.300.400";
    std::string actual = ip_to_string( std::vector<int>{100, 200, 300, 400} );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, std_list_short)
{
    std::string expected = "400.300.200.100";
    std::string actual = ip_to_string( std::list<short>{400, 300, 200, 100}  );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, std_tuple)
{
    std::string expected = "123.456.789.0";
    std::string actual = ip_to_string(  std::make_tuple(123, 456, 789, 0) );
    ASSERT_EQ(actual, expected);
}

TEST(IP2String, std_pair)
{
    std::string expected = "123.FF";
    std::string actual = ip_to_string( std::make_pair(123, "FF")  );
    ASSERT_EQ(actual, expected);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}