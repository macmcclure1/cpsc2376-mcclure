#ifndef REVERSEFILTER_H
#define REVERSEFILTER_H

#include "IFilterStrategy.h"
#include <algorithm>

class ReverseFilter : public IFilterStrategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result = input;
        std::reverse(result.begin(), result.end());
        return result;
    }
};

#endif