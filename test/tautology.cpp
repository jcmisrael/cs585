#include "gtest/gtest.h"

namespace {

TEST(TautologyTest, 1Equals1){
    ASSERT_EQ(1,1);
}

TEST(TautologyTest, stringEquals){
    ASSERT_STREQ("Testing string equals", "Testing string equals");
}

} // end of namespace
