#ifndef IMAGE_H_
#define IMAGE_H_
#include "RGBA.h"
#include <memory>

// classes are capitalized
class Image
{
    public:
    // default constructor
    // 0 and 0 values
    Image() = default;
    // user defined constructor
    Image(int _w, int _h);
    int width() const;
    int height() const;
    RGBA getPixel(int _x, int _y) const;
    void setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);

    private:
    // m_ means that anything that is a member of the class
    int m_width = 0;
    int m_height = 0;
    std::unique_ptr<RGBA []> m_pixels;
};

#endif