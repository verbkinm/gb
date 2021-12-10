#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    Figure() = default;

    virtual float area() const = 0;
};

#endif // FIGURE_H
