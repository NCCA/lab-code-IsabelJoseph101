#include <gtest/gtest.h>
#include "RGBA.h"

TEST(RGBA, construct)
{
    RGBA a;
    ASSERT_TRUE(a.r == 0);
    ASSERT_TRUE(a.g == 0);
    ASSERT_TRUE(a.b == 0);
    ASSERT_TRUE(a.a == 0);
}

TEST(RGBA,construct_from_values)
{
    auto a=RGBA(255,128,32,12);
    ASSERT_TRUE(a.r == 255);
    ASSERT_TRUE(a.g == 128);
    ASSERT_TRUE(a.b == 32);
    ASSERT_TRUE(a.a == 12);
}