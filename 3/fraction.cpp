#include "fraction.h"

Fraction::Fraction(int n, int d) : _numerator(n), _denominator(d)
{
    if (_denominator == 0)
      throw std::invalid_argument("_denominator == 0");

    if(d < 0)
    {
        _numerator = -_numerator;
        _denominator = abs(_denominator);
    }
    if(n < 0)
        _numerator = -_numerator;
}

void Fraction::commonDenominator(Fraction &fr1, Fraction &fr2)
{
    if(fr1._denominator == fr2._denominator)
        return;

    int tmpFr1D = fr1._denominator;

    fr1._numerator *= fr2._denominator;
    fr1._denominator *= fr2._denominator;

    fr2._numerator *= tmpFr1D;
    fr2._denominator *= tmpFr1D;
}

Fraction Fraction::revert() const
{
    return {this->_denominator, this->_numerator};
}

Fraction Fraction::operator+(Fraction &fr)
{
    commonDenominator(*this, fr);
    return {this->_numerator + fr._numerator, this->_denominator + fr._denominator};
}

Fraction Fraction::operator -(Fraction &fr)
{
    commonDenominator(*this, fr);
    return {this->_numerator - fr._numerator, this->_denominator - fr._denominator};
}

Fraction Fraction::operator *(int value) const
{
    return {this->_numerator * value, this->_denominator};
}

Fraction Fraction::operator *(const Fraction &fr) const
{
    return {this->_numerator * fr._numerator, this->_denominator * fr._denominator};
}

Fraction Fraction::operator /(int value) const
{
    return *this * value;
}

Fraction Fraction::operator /(const Fraction &fr) const
{
    return *this * fr.revert();
}

Fraction Fraction::operator -() const
{
    return {-this->_numerator, this->_denominator};
}

bool Fraction::operator ==(const Fraction &fr) const
{
    return (this->_numerator == fr._numerator) && (this->_denominator && fr._denominator);
}

bool Fraction::operator !=(const Fraction &fr) const
{
    return !(*this == fr);
}

bool Fraction::operator <(const Fraction &fr)
{
    Fraction f1 = *this;
    Fraction f2 = fr;

    commonDenominator(f1, f2);

    return f1._numerator < f2._numerator;
}

bool Fraction::operator <=(const Fraction &fr)
{
    Fraction f1 = *this;
    Fraction f2 = fr;

    commonDenominator(f1, f2);

    return f1._numerator <= f2._numerator;
}

bool Fraction::operator >(const Fraction &fr)
{
    return !(*this < fr);
}

bool Fraction::operator >=(const Fraction &fr)
{
    return !(*this <= fr);
}
