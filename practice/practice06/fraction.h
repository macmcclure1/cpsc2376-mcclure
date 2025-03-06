#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator

    void simplify(); // Simplifies the fraction using GCD

public:
    // Constructors
    Fraction();
    Fraction(int n, int d);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Setters
    void setNumerator(int n);
    void setDenominator(int d);

    // Friend functions for operator overloading
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Overload << for printing fractions
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif
