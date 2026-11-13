#include <iostream>
#include "TwosComplement.h"
#include "inputValidator.h"
#include "binaryHelper.h"

void TwosComplement::run() {
    while (true) {
        std::cout << std::endl;
        std::cout << "2's Complement\n";
        std::cout << "  1. Find 2's Complement of a Binary Number\n";
        std::cout << "  2. Back\n";

        std::string choiceInput;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choiceInput;

        // Input Validation
        if (choiceInput != "1" && choiceInput != "2") {
            std::cout << std::endl;
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int intChoiceInput = choiceInput[0] - '0';

        if (intChoiceInput == 1) {
            std::cout << std::endl;
            std::cout << "Finding 2's Complement Selected\n";
            std::cout << "Enter a binary number: ";
            std::string inputInBinary;
            std::cin >> inputInBinary;

            // checks if the number is 0 or 1
            if (!isBinary(inputInBinary)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string result = calculateTwosComplement(inputInBinary);

            std::cout << std::endl;
            std::cout << inputInBinary << ", 2's complement -> " << result << std::endl;

        } else {
            return;
        }
   }
}

std::string TwosComplement::calculateTwosComplement(const std::string& input) {

    if (!isBinary(input)) {
        return "Invalid binary number!";
    }

    std::string result = invertBinary(input);

    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] == '0') {
            result[i] = '1';
            break;
        } else {
            result[i] = '0';
        }
    }

    return result;
}
 