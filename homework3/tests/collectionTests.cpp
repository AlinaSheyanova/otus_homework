#include <gtest/gtest.h>
#include <vector>

#include "custom_collection.h"

TEST(AddElement, OneElement)
{
    CustomRingBuffer<int> ringBuffer(5);
    int expected = 5;
    ringBuffer.add(expected);
    auto size = ringBuffer.count();
    ASSERT_EQ(size, 1);
    auto actual = ringBuffer.get();
    ASSERT_EQ(actual, expected);
}

TEST(AddElement, FiveElements)
{
    CustomRingBuffer<int> ringBuffer(10);
    std::vector<int> expected = {0, 1, 2, 3, 4};
    size_t expected_size = 0;
    for(auto value : expected)
    {
        ringBuffer.add(value);
        expected_size++;
        auto size = ringBuffer.count();
        ASSERT_EQ(size, expected_size);
    }
    for(auto expected_value : expected)
    {
        auto actual = ringBuffer.get();
        ASSERT_EQ(actual, expected_value);
    }
}

TEST(AddRange, FiveElements)
{
    CustomRingBuffer<int> ringBuffer(10);
    std::vector<int> expected = {0, 1, 2, 3, 4};
    auto expected_size = expected.size();
    ringBuffer.addRange(expected);
    auto size = ringBuffer.count();
    ASSERT_EQ(size, expected_size);
    for(auto expected_value : expected)
    {
        auto actual = ringBuffer.get();
        ASSERT_EQ(actual, expected_value);
    }
}

TEST(AddRange, Overflow)
{
    CustomRingBuffer<int> ringBuffer(4);
    std::vector<int> expected = {0, 1, 2, 3, 4};
    size_t expected_size = 0;
    for(auto value : expected)
    {
        ringBuffer.add(value);
        expected_size++;
        auto size = ringBuffer.count();
        ASSERT_EQ(size, expected_size);
    }
    for(auto expected_value : expected)
    {
        auto actual = ringBuffer.get();
        ASSERT_EQ(actual, expected_value);
    }
}

TEST(RengedBaseFor, Enumerate)
{
    CustomRingBuffer<int> ringBuffer(10);
    std::vector<int> source = {0, 1, 2, 3, 4};
    ringBuffer.addRange(source);
    auto expected_size = source.size();
    for(auto item : ringBuffer)
    {
        expected_size--;
        auto expected_value = source[expected_size];
        ASSERT_EQ(item, expected_value);
        auto actual_size = ringBuffer.count();
        ASSERT_EQ(actual_size, expected_size);
    }
    ASSERT_EQ(expected_size, 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}