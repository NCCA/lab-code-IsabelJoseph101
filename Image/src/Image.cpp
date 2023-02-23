#include "Image.h"

// user defined constructors
// allocating width and height 
Image::Image(int _w, int _h): m_width{_w}, m_height{_h}
{
    m_pixels = std::make_unique<RGBA []>(_w*_h);
}

RGBA Image::getPixel(int _x, int _y) const
{
    return m_pixels[0];
}

// seting pixels
void Image::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    m_pixels[0].r = _r;
    m_pixels[0].g = _g;
    m_pixels[0].b = _b;
    m_pixels[0].a = _a;
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}