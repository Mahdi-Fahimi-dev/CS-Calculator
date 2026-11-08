#include <string>
#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H

class NumberConverter {
public:
    void run();
    std::string decimalToBinary(const std::string& input);
    std::string binaryToDecimal(const std::string& input);
    std::string decimalToHexadecimal(const std::string& input);
    std::string hexadecimalToDecimal(const std::string& input);
    std::string decimalToOctal(const std::string& input);
    std::string binaryToOctal(const std::string& input);
    std::string octalToBinary(const std::string& input);

};

#endif