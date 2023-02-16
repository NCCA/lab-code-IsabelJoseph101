#include <gtest/gtest.h>
#include "Image.h"

TEST(Image, ctor)
{
    auto img = Image();
    ASSERT_EQ(image.width(),0);
    ASSERT_EQ(image.height(),0);
}