#include <gtest/gtest.h>
#include <vector>

#include "custom_collection.h"

TEST(StdMap, StdAlloc)
{
    std::map<int, int> factorialMap;
    int f = 1;
    factorialMap[0] = f;
    for (int i = 1; i <= 10; i++)
    {
        f *= i;
        factorialMap[i]= f;
    }
    ASSERT_EQ(factorialMap[0], 1);
    ASSERT_EQ(factorialMap[1], 1);
    ASSERT_EQ(factorialMap[2], 2);
    ASSERT_EQ(factorialMap[3], 6);
    ASSERT_EQ(factorialMap[4], 24);
    ASSERT_EQ(factorialMap[8], 40320);
    ASSERT_EQ(factorialMap[9], 362880);
}

TEST(StdMap, CustomAlloc)
{
    std::map<int, int> factorialMap;
    int f = 1;
    factorialMap[0] = f;
    for (int i = 1; i <= 10; i++)
    {
        f *= i;
        factorialMap[i]= f;
    }
    ASSERT_EQ(factorialMap[0], 1);
    ASSERT_EQ(factorialMap[1], 1);
    ASSERT_EQ(factorialMap[2], 2);
    ASSERT_EQ(factorialMap[3], 6);
    ASSERT_EQ(factorialMap[4], 24);
    ASSERT_EQ(factorialMap[8], 40320);
    ASSERT_EQ(factorialMap[9], 362880);
}

TEST(CustomCollectiom, StdAlloc)
{
    CustomCollection<int> collection;
    for (int i = 0; i < 10; i++)
    {
        collection.push_back(i);
    }
    ASSERT_EQ(collection[0], 0);
    ASSERT_EQ(collection[1], 1);
    ASSERT_EQ(collection[5], 5);
    ASSERT_EQ(collection[9], 9);
}

TEST(CustomCollection, CustomAlloc)
{
    CustomCollection<int> collection;
    for (int i = 0; i < 10; i++)
    {
        collection.push_back(i);
    }
    ASSERT_EQ(collection[0], 0);
    ASSERT_EQ(collection[1], 1);
    ASSERT_EQ(collection[5], 5);
    ASSERT_EQ(collection[9], 9);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}