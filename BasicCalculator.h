#include <string>
#ifndef BASICCALCULATOR_H
#define BASICCALCULATOR_H

class BasicCalculator {
public:
    void run();
    std::string calculate(double firstNumber, char operation, double secondNumber);

};

#endif