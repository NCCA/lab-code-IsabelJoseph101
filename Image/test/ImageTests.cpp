#include <gtest/gtest.h>
#include "Image.h"

TEST(Image, ctor)
{
    auto img = Image();
    ASSERT_EQ(img.width(),0);
    ASSERT_EQ(img.height(),0);
}

TEST(Image, userCtor)
{
    auto img = Image(1024, 720);
    ASSERT_EQ(img.width(), 1024);
    ASSERT_EQ(img.height(), 720);
}

// top left hand corner is the origin (0, 0)
TEST(Image, defaultRGBA)
{
    auto img = Image(5, 5);
    for(int y = 0; y < 5; ++y)
    {
        for(int x = 0; x < 5; ++x)
        {
            auto pixel = img.getPixel(x, y);
            ASSERT_EQ(pixel.r,0);
            ASSERT_EQ(pixel.g,0);
            ASSERT_EQ(pixel.b,0);
            ASSERT_EQ(pixel.a,0);
        }
    }
}

