#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>

class Fraction
{
private:
    int _numerator, _denominator;

    void commonDenominator(Fraction &fr1, Fraction &fr2);
    inline Fraction revert() const;

public:
    Fraction(int n, int d);

    inline Fraction operator +(Fraction &fr);
    inline Fraction operator -(Fraction &fr);
    inline Fraction operator *(int value) const;
    inline Fraction operator *(const Fraction &fr) const;
    inline Fraction operator /(int value) const;
    inline Fraction operator /(const Fraction &fr) const;
    inline Fraction operator -() const;

    inline bool operator ==(const Fraction &fr) const;
    inline bool operator !=(const Fraction &fr) const;
    bool operator <(const Fraction &fr);
    bool operator <=(const Fraction &fr);
    inline bool operator >(const Fraction &fr);
    inline bool operator >=(const Fraction &fr);
};

#endif // FRACTION_H
