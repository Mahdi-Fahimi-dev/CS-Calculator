#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <string>
#include "BasicCalculator.h"

void BasicCalculator::run() {
    double num1, num2;
    char operation;

    std::cout << "Enter the first number, the operation, and the second number: ";
    std::cin >> num1 >> operation >> num2;
    if (std::cin.fail()) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::string result = calculate(num1, operation, num2);

    if (result == "Undefined" || result == "Invalid Operation") {
        std::cout << result << std::endl;
    } else {
        std::cout << num1 << " " << operation << " " << num2
                << " = " << result << std::endl;
    }
}

std::string BasicCalculator::calculate(double firstNumber, char operation, double secondNumber) {
    double result;

    switch (operation) {
        case '+':
            result = firstNumber + secondNumber;
            break;

        case '-':
            result = firstNumber - secondNumber;
            break;

        case '*':
            result = firstNumber * secondNumber;
            break;

        case '/':
            if (secondNumber == 0) {
                return "Undefined";
            }
            result = firstNumber / secondNumber;
            break;

        case '%':
            if (secondNumber == 0) {
                return "Undefined";
            }
            result = std::fmod(firstNumber, secondNumber);
            break;

        default:
            return "Invalid Operation";
    }

    std::ostringstream output;
    output << result;
    return output.str();
}
