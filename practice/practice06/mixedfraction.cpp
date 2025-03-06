#include "mixedfraction.h"

// Constructor for mixed fraction
MixedFraction::MixedFraction(int whole, int n, int d) 
    : Fraction(whole * d + n, d) {}

// Convert improper fraction to mixed fraction
MixedFraction::MixedFraction(const Fraction& fraction)
    : Fraction(fraction) {}

// Overload << to print mixed fraction
std::ostream& operator<<(std::ostream& os, const MixedFraction& frac) {
    int whole = frac.getNumerator() / frac.getDenominator();
    int remainder = abs(frac.getNumerator()) % frac.getDenominator();

    if (whole != 0) os << whole;
    if (remainder != 0) os << " " << remainder << "/" << frac.getDenominator();
    return os;
}
