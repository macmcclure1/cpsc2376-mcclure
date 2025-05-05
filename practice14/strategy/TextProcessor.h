#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include "IFilterStrategy.h"
#include <memory>

class TextProcessor {
    std::unique_ptr<IFilterStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<IFilterStrategy> s) {
        strategy = std::move(s);
    }
    std::string process(const std::string& text) const {
        return strategy ? strategy->apply(text) : text;
    }
};

#endif