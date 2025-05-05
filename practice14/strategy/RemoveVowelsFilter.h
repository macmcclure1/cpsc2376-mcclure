#ifndef REMOVEVOWELSFILTER_H
#define REMOVEVOWELSFILTER_H

#include "IFilterStrategy.h"

class RemoveVowelsFilter : public IFilterStrategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result;
        for (char c : input) {
            char lower = std::tolower(c);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
                result += c;
            }
        }
        return result;
    }
};

#endif