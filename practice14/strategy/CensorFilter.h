#ifndef CENSORFILTER_H
#define CENSORFILTER_H

#include "IFilterStrategy.h"
#include <string>
#include <vector>
#include <sstream>

class CensorFilter : public IFilterStrategy {
    std::vector<std::string> badWords = {"bad", "ugly"};
public:
    std::string apply(const std::string& input) const override {
        std::istringstream iss(input);
        std::ostringstream oss;
        std::string word;
        while (iss >> word) {
            bool censored = false;
            for (const auto& bad : badWords) {
                if (word == bad) {
                    word = "***";
                    censored = true;
                    break;
                }
            }
            oss << word << ' ';
        }
        return oss.str();
    }
};

#endif
