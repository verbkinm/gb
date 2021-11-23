#include "rgba.h"

RGBA::RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255)
{

}

RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
{

}

void RGBA::print() const
{
    //почему-то cout воспринимает uint8_t как char!!!
    std::cout << "RGBA: " << (int)m_red << ", " << (int)m_green << ", " << (int)m_blue << ", " << (int)m_alpha << std::endl;
}
