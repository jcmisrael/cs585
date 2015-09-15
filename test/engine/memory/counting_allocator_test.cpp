// counting_allocator_test.cpp
// Test implementation for counting allocator

#include "counting_allocator.hpp"
#include "gtest/gtest.h"

namespace {

using StevensDev::sgdm::CountingAllocator;

TEST(CountingAllocatorTest, constructor){
    CountingAllocator<int> ca;
    const int numAllocations = ca.getAllocationCount();
    const int numReleases = ca.getReleaseCount();
    ASSERT_EQ(numAllocations, 0);
    ASSERT_EQ(numReleases, 0);
}

TEST(CountingAllocatorTest, get){
    CountingAllocator<int> ca;
    int* i = NULL;
    i = ca.get(1);
    ASSERT_TRUE(i != NULL);
    *i = 5;
    ASSERT_EQ(*i, 5);
    ca.release(i, 1);
    i = NULL;
}

TEST(CountingAllocatorTest, getAllocationCount){
    CountingAllocator<int> ca;
    int* i = NULL;
    EXPECT_EQ(ca.getAllocationCount(), 0);
    i = ca.get(2);
    EXPECT_EQ(ca.getAllocationCount(), 2);
    ca.release(i, 2);
    i = NULL;
}

TEST(CountingAllocatorTest, getReleaseCount){
    CountingAllocator<int> ca;
    int* i = NULL;
    EXPECT_EQ(ca.getReleaseCount(), 0);
    i = ca.get(2);
    ca.release(i, 2);
    i = NULL;
    EXPECT_EQ(ca.getReleaseCount(), 2);
}

TEST(CountingAllocatorTest, getOutstandingCount){
    CountingAllocator<int> ca;
    int* i = NULL;
    int* i2 = NULL;
    EXPECT_EQ(ca.getOutstandingCount(), 0);
    i = ca.get(2);
    EXPECT_EQ(ca.getOutstandingCount(), 2);
    i2 = ca.get(3);
    EXPECT_EQ(ca.getOutstandingCount(), 5);
    ca.release(i, 2);
    i = NULL;
    EXPECT_EQ(ca.getOutstandingCount(), 3);
    ca.release(i2, 3);
    i2 = NULL;
}

TEST(CountingAllocatorTest, getTotalAllocationCount){
    CountingAllocator<int> ca;
    CountingAllocator<int> ca2;
    int* i = NULL;
    int* i2 = NULL;
    const int base = CountingAllocator<int>::getTotalAllocationCount(); // Get base value due to previous allocs
    EXPECT_EQ(CountingAllocator<int>::getTotalAllocationCount(), base);
    i = ca.get(2);
    EXPECT_EQ(CountingAllocator<int>::getTotalAllocationCount(), base + 2);
    i2 = ca2.get(3);
    EXPECT_EQ(CountingAllocator<int>::getTotalAllocationCount(), base + 5);
    ca.release(i, 2);
    i = NULL;
    ca2.release(i2, 3);
    i2 = NULL;
}

TEST(CountingAllocatorTest, getTotalReleaseCount){
    CountingAllocator<int> ca;
    CountingAllocator<int> ca2;
    int* i = NULL;
    int* i2 = NULL;
    const int base = CountingAllocator<int>::getTotalReleaseCount(); // Get base value due to previous releases
    EXPECT_EQ(CountingAllocator<int>::getTotalReleaseCount(), base);
    i = ca.get(2);
    ca.release(i, 2);
    i = NULL;
    EXPECT_EQ(CountingAllocator<int>::getTotalReleaseCount(), base + 2);
    i2 = ca2.get(3);
    ca2.release(i2, 3);
    i2 = NULL;
    EXPECT_EQ(CountingAllocator<int>::getTotalReleaseCount(), base + 5);
}

TEST(CountingAllocatorTest, getTotalOutstandingCount){
    CountingAllocator<int> ca;
    CountingAllocator<int> ca2;
    int* i = NULL;
    int* i2 = NULL;
    EXPECT_EQ(CountingAllocator<int>::getTotalOutstandingCount(), 0);
    i = ca.get(2);
    EXPECT_EQ(CountingAllocator<int>::getTotalOutstandingCount(), 2);
    i2 = ca2.get(3);
    EXPECT_EQ(CountingAllocator<int>::getTotalOutstandingCount(), 5);
    ca.release(i, 2);
    i = NULL;
    EXPECT_EQ(CountingAllocator<int>::getTotalOutstandingCount(), 3);
    ca2.release(i2, 3);
    i2 = NULL;
    EXPECT_EQ(CountingAllocator<int>::getTotalOutstandingCount(), 0);
}

} // end of namespace
