#ifndef UPPERCASEFILTER_H
#define UPPERCASEFILTER_H

#include "IFilterStrategy.h"
#include <cctype>

class UppercaseFilter : public IFilterStrategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result;
        for (char c : input) result += std::toupper(c);
        return result;
    }
};

#endif
