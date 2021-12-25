#ifndef EX_H
#define EX_H

#include <exception>

class Ex : public std::exception
{
public:
    Ex(float x);

    float x() const;

private:
    float _x;
};

#endif // EX_H
