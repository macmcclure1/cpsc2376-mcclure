#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "fraction.h"

class MixedFraction : public Fraction {
public:
    // Constructors
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction);

    // Overload << for printing mixed fractions
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& frac);
};

#endif
