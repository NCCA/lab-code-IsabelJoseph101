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
            ASSERT_EQ(pixel.r, 0);
            ASSERT_EQ(pixel.g, 0);
            ASSERT_EQ(pixel.b, 0);
            ASSERT_EQ(pixel.a, 0);
        }
    }
}


TEST(Image, set_get)
{
    auto img = Image(100, 30);
    ASSERT_EQ(img.width(),100);
    ASSERT_EQ(img.height(),30);

    // setting pixels
    // red
    for(int y = 0; y < 10; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            img.setPixel(x , y, 255, 0, 0);
        }
    }

    // green
        for(int y = 10; y < 20; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            img.setPixel(x , y, 0, 255, 0);
        }
    }

    // blue
        for(int y = 20; y < 30; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            img.setPixel(x , y, 0, 0, 255);
        }
    }

    // getting pixels
    // red
        for(int y = 0; y < 10; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            auto pixel = img.getPixel(x, y);
            ASSERT_EQ(pixel.r, 255);
            ASSERT_EQ(pixel.g, 0);
            ASSERT_EQ(pixel.b, 0);
            ASSERT_EQ(pixel.a, 255);
        }
    }

    // blue
        for(int y = 10; y < 20; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            auto pixel = img.getPixel(x, y);
            ASSERT_EQ(pixel.r, 0);
            ASSERT_EQ(pixel.g, 255);
            ASSERT_EQ(pixel.b, 0);
            ASSERT_EQ(pixel.a, 255);
        }
    }

    // green
        for(int y = 20; y < 30; ++y)
    {
        for(int x = 0; x < img.width(); ++x)
        {
            auto pixel = img.getPixel(x, y);
            ASSERT_EQ(pixel.r, 0);
            ASSERT_EQ(pixel.g, 0);
            ASSERT_EQ(pixel.b, 255);
            ASSERT_EQ(pixel.a, 255);
        }
    }
    // img.setPixel(0, 0, 255, 128, 12, 0);
    // auto pixel = img.getPixel(0, 0);
    // ASSERT_EQ(pixel.r, 255);
    // ASSERT_EQ(pixel.g, 128);
    // ASSERT_EQ(pixel.b, 12);
    // ASSERT_EQ(pixel.a, 0);

    // saving to file
    ASSERT_TRUE(img.save("test.tiff"));
    ASSERT_TRUE(img.save("test.jpg"));
    ASSERT_TRUE(img.save("test.bmp"));
    ASSERT_TRUE(img.save("test.exr"));
}
