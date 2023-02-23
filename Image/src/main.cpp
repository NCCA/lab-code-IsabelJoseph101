#include <iostream>
#include <cstdlib>
#include <random>
#include "Image.h"

int main()
{
    auto img = Image(512, 512);

    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randWidth(0, img.width()-1);
    std::uniform_int_distribution<> randHeight(0, img.height()-1);
    std::uniform_int_distribution<> colour(0, 255);

    // prints image demo text
    std::cout<<"Image Demo\n";

    // create some art
    // from this random number generator select me a random number from 0 to 255
    for(int i = 0; i < 500000; i++)
    {
        // obtains random value for color from 0 to 255
        auto r = colour(gen);
        auto g = colour(gen);
        auto b = colour(gen);
        // obtains random value for height and width
        auto x = randWidth(gen);
        auto y = randHeight(gen);
        img.setPixel(x, y, r, g, b);
    }

    img.save("test.jpg");
    return EXIT_SUCCESS;
}