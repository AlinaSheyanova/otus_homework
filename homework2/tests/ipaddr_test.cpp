#include <gtest/gtest.h>
#include <sstream>

#include "ipAddres.h"

TEST(IpFilter, ipAddr)
{
    const auto ip1 = "0.0.0.1";
    const auto ip1data = ipAddress(ip1);
    const auto ip2 = "0.0.1.1";
    const auto ip2data = ipAddress(ip2);
    ASSERT_EQ((ip1data < ip2data), true);
}

TEST(IpFilter, ipAddr2)
{
    const auto ip1 = "2.0.0.1";
    const auto ip1data = ipAddress(ip1);
    const auto ip2 = "2.0.0.2";
    const auto ip2data = ipAddress(ip2);
    ASSERT_EQ((ip1data < ip2data), true);
}

TEST(IpFilter, ipAdd3)
{
    const auto expected = "2.0.0.2";
    const auto actual = ipAddress(expected).toString();
    ASSERT_EQ(actual, expected);
    const auto expected2 = "10.10.0.10";
    const auto actual2 = ipAddress(expected2).toString();
    ASSERT_EQ(actual2, expected2);
    const auto expected3 = "255.255.255.255";
    const auto actual3 = ipAddress(expected3).toString();
    ASSERT_EQ(actual3, expected3);
    const auto expected4 = "127.0.0.1";
    const auto actual4 = ipAddress(expected4).toString();
    ASSERT_EQ(actual4, expected4);
    const auto expected5 = "127";
    const auto actual5 = ipAddress(expected5).toString();
    ASSERT_EQ(actual5, "");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}