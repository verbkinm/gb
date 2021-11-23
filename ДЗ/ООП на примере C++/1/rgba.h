#ifndef RGBA_H
#define RGBA_H

#include <iostream>

class RGBA
{
private:
    uint8_t m_red, m_green, m_blue, m_alpha;
public:
    RGBA();
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

    void print() const;
};

#endif // RGBA_H
