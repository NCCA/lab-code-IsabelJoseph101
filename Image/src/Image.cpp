#include "Image.h"
#include <OpenImageIO/imageio.h>

// user defined constructors
// allocating width and height 
Image::Image(int _w, int _h): m_width{_w}, m_height{_h}
{
    m_pixels = std::make_unique<RGBA []>(_w*_h);
}

RGBA Image::getPixel(int _x, int _y) const
{
    int index = (m_width * _y) + _x;    
    return m_pixels[index];
}

// seting pixels
void Image::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    int index = (m_width * _y) + _x;
    m_pixels[index].r = _r;
    m_pixels[index].g = _g;
    m_pixels[index].b = _b;
    m_pixels[index].a = _a;
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}


bool Image::save(std::string_view _fname) const
{
    bool success = false;
    using namespace OIIO;
    auto out = ImageOutput::create(_fname.data());
    if(!out)
    {
        return false;
    }
    ImageSpec spec(m_width, m_height, 4, TypeDesc::UINT8);
    success = out->open(_fname.data(),spec);
    success = out->write_image(TypeDesc::UINT8, m_pixels.get());
    success = out->close();
    return success;
}