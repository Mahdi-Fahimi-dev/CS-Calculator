#include <emscripten/bind.h>
#include "BasicCalculator.h"
#include "NumberConverter.h"
#include "BitwiseCalculator.h"
#include <string>

int testConnection() {
    return 42;
}

std::string calculateBasic(double firstNumber, std::string operation, double secondNumber) {
    BasicCalculator calculator;

    if (operation.empty()) {
        return "Invalid Operation";
    }

    return calculator.calculate(firstNumber, operation[0], secondNumber);
}

std::string convertDecimalToBinary(const std::string& input) {
    NumberConverter converter;
    return converter.decimalToBinary(input);
}

std::string convertBinaryToDecimal(const std::string& input) {
    NumberConverter converter;
    return converter.binaryToDecimal(input);
}

std::string convertDecimalToHexadecimal(const std::string& input) {
    NumberConverter converter;
    return converter.decimalToHexadecimal(input);
}

std::string convertHexadecimalToDecimal(const std::string& input) {
    NumberConverter converter;
    return converter.hexadecimalToDecimal(input);
}

std::string convertDecimalToOctal(const std::string& input) {
    NumberConverter converter;
    return converter.decimalToOctal(input);
}

std::string convertBinaryToOctal(const std::string& input) {
    NumberConverter converter;
    return converter.binaryToOctal(input);
}

std::string convertOctalToBinary(const std::string& input) {
    NumberConverter converter;
    return converter.octalToBinary(input);
}

std::string bitwiseAnd(const std::string& first, const std::string& second) {
    BitwiseCalculator calculator;
    return calculator.bitwiseAnd(first, second);
}

std::string bitwiseOr(const std::string& first, const std::string& second) {
    BitwiseCalculator calculator;
    return calculator.bitwiseOr(first, second);
}

std::string bitwiseXor(const std::string& first, const std::string& second) {
    BitwiseCalculator calculator;
    return calculator.bitwiseXor(first, second);
}

std::string bitwiseNot(const std::string& input) {
    BitwiseCalculator calculator;
    return calculator.bitwiseNot(input);
}

std::string bitwiseLeftShift(const std::string& input, const std::string& shiftInput) {
    BitwiseCalculator calculator;
    return calculator.bitwiseLeftShift(input, shiftInput);
}

std::string bitwiseLogicalRightShift(
    const std::string& input,
    const std::string& shiftInput) {

    BitwiseCalculator calculator;
    return calculator.bitwiseLogicalRightShift(input, shiftInput);
}

std::string bitwiseArithmeticRightShift(
    const std::string& input,
    const std::string& shiftInput) {

    BitwiseCalculator calculator;
    return calculator.bitwiseArithmeticRightShift(input, shiftInput);
}

EMSCRIPTEN_BINDINGS(cs_calculator) {
    emscripten::function("testConnection", &testConnection);
    emscripten::function("calculateBasic", &calculateBasic);
    emscripten::function("convertDecimalToBinary", &convertDecimalToBinary);
    emscripten::function("convertBinaryToDecimal", &convertBinaryToDecimal);
    emscripten::function("convertDecimalToHexadecimal", &convertDecimalToHexadecimal);
    emscripten::function("convertHexadecimalToDecimal", &convertHexadecimalToDecimal);
    emscripten::function("convertDecimalToOctal", &convertDecimalToOctal);
    emscripten::function("convertBinaryToOctal", &convertBinaryToOctal);
    emscripten::function("convertOctalToBinary", &convertOctalToBinary);
    emscripten::function("bitwiseAnd", &bitwiseAnd);
    emscripten::function("bitwiseOr", &bitwiseOr);
    emscripten::function("bitwiseXor", &bitwiseXor);
    emscripten::function("bitwiseNot", &bitwiseNot);
    emscripten::function("bitwiseLeftShift", &bitwiseLeftShift);
    emscripten::function("bitwiseLogicalRightShift", &bitwiseLogicalRightShift);
    emscripten::function("bitwiseArithmeticRightShift", &bitwiseArithmeticRightShift);
}