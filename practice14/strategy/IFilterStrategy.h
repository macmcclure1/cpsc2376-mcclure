#ifndef IFILTERSTRATEGY_H
#define IFILTERSTRATEGY_H

#include <string>

class IFilterStrategy {
public:
    virtual std::string apply(const std::string& input) const = 0;
    virtual ~IFilterStrategy() = default;
};

#endif