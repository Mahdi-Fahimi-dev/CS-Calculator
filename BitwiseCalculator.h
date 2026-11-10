#include <string>
#ifndef BITWISECALCULATOR_H
#define BITWISECALCULATOR_H

class BitwiseCalculator {
public:
    void run();
    std::string bitwiseAnd(const std::string& first, const std::string& second);
    std::string bitwiseOr(const std::string& first, const std::string& second);
};
#endif
