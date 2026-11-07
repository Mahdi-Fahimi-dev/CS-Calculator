#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <stdexcept>
#include "NumberConverter.h"
#include "inputValidator.h"

void NumberConverter::run() {

    while(true) {

        std::cout << std::endl;
        std::cout << "Number System Converter\n";
        std::cout << "  1. Decimal to Binary\n";
        std::cout << "  2. Binary to Decimal\n";
        std::cout << "  3. Decimal to Hexadecimal\n";
        std::cout << "  4. Hexadecimal to Decimal\n";
        std::cout << "  5. Decimal to Octal\n";
        std::cout << "  6. Binary to Octal\n";
        std::cout << "  7. Octal to Binary\n";
        std::cout << "  8. Back\n";
        std::cout << std::endl;

        std::string option;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if (option.size() != 1 || option[0] < '1' || option[0] > '8') {
            std::cout << std::endl;
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int optionNumber = option[0] - '0';

        // Decimal to binary
        if (optionNumber == 1) {
            
            std::string decimalInput;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> decimalInput;

            std::string result = decimalToBinary(decimalInput);

            if (result == "Invalid input!" || result == "Number is too large!") {
                std::cout << std::endl;
                std::cout << result << std::endl;
                continue;
            }

            std::cout << "Decimal (" << decimalInput << ") to binary is: "
                << result << std::endl;
        
        // Binary to decimal
        } else if (optionNumber == 2) {
            std::cout << std::endl;
            std::cout << "Binary to Decimal Selected\n";
            std::string binary;
            std::cout << "Enter a binary number: ";
            std::cin >> binary;

            std::string result = binaryToDecimal(binary);

        if (result == "Invalid binary number!" || result == "Number is too large!") {
            std::cout << std::endl;
            std::cout << result << std::endl;
            continue;
        }

        std::cout << "Binary (" << binary << ") to decimal is: "
            << result << std::endl;

        // Decimal to hexadecimal
        } else if (optionNumber == 3) {
            std::cout << std::endl;
            std::cout << "Decimal to Hexadecimal Selected\n";

            std::string nonNegativeNum1;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> nonNegativeNum1;

            std::string result = decimalToHexadecimal(nonNegativeNum1);

            if (result == "Invalid input!" || result == "Number is too large!") {
                std::cout << std::endl;
                std::cout << result << std::endl;
                continue;
            }

            std::cout << "The decimal (" << nonNegativeNum1
                << ") to hexadecimal is: " << result << std::endl;

        // Hexadecimal to decimal
        } else if (optionNumber == 4) {
            std::cout << std::endl;
            std::cout << "Hexadecimal to Decimal Selected\n";
            std::cout << "Enter a hexadecimal number: ";
            std::string hexa;
            std::cin >> hexa;

            std::string result = hexadecimalToDecimal(hexa);

            if (result == "Invalid hexadecimal number!" || result == "Number is too large!") {
                std::cout << std::endl;
                std::cout << result << std::endl;
                continue;
            }

            std::cout << "Hexadecimal (" << hexa << ") to decimal is: "
                << result << std::endl;
        
        // Decimal to Octal
        } else if (optionNumber == 5) {
            std::cout << std::endl;
            std::cout << "Decimal to Octal Selected\n";
            std::string decNum;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> decNum;

            std::string result = decimalToOctal(decNum);

            if (result == "Invalid input!" || result == "Number is too large!") {
                std::cout << std::endl;
                std::cout << result << std::endl;
                continue;
            }

            std::cout << "Decimal (" << decNum << ") to octal is: "
                << result << std::endl;

        // Binary to Octal
        } else if (optionNumber == 6) {
            std::cout << std::endl;
            std::cout << "Binary to Octal Selected\n";
            std::cout << "Enter a binary number: ";

            std::string binaryNum;
            std::cin >> binaryNum;

            if (!isBinary(binaryNum)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            int extraBits = binaryNum.size() % 3;
            if (extraBits == 1) {
                binaryNum = "00" + binaryNum;
            } else if (extraBits == 2) {
                binaryNum = "0" + binaryNum;
            }

            std::string octalResult;
            for (int i = 0; i < binaryNum.size(); i+=3) {
                int octalDigit = 0;
                octalDigit += (binaryNum[i] - '0') * 4;
                octalDigit += (binaryNum[i + 1] - '0') * 2;
                octalDigit += (binaryNum[i + 2] - '0') * 1;
                octalResult += octalDigit + '0';
            }
            while (octalResult.size() > 1 && octalResult[0] == '0') {
                octalResult.erase(0, 1);
            }
            std::cout << "Binary (" << binaryNum << ") to octal is: ";
            std::cout << octalResult;
            std::cout << std::endl;

        // Octal to Binary
        } else if (optionNumber == 7) {
            std::cout << std::endl;
            std::cout << "Octal to Binary Selected\n";
            std::cout << "Enter an octal number: ";
            std::string octalNum;
            std::cin >> octalNum;

            bool validOctal = true;

            // check if the number is between 0 and 7
            for (int i = 0; i < octalNum.size(); i++) {
                if (octalNum[i] < '0' || octalNum[i] > '7') {
                    std::cout << std::endl;
                    std::cout << "Invalid octal number!\n";
                    validOctal = false;
                    break;
                }
            }

            if (validOctal == false) { 
                continue;
            }

            std::string binaryResult;

            // convert the octal number into its numeric value
            for (int i = 0; i < octalNum.size(); i++) {
                int intNumber;
                intNumber = octalNum[i] - '0';
                std::string octBinaryNum;

                if (intNumber >= 4) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 4;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }

                if (intNumber >= 2) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 2;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }

                if (intNumber >= 1) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 1;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }
                binaryResult = binaryResult + octBinaryNum;

            }
            while (binaryResult.size() > 1 && binaryResult[0] == '0') {
                binaryResult.erase(0, 1);
            }
            std::cout << "Octal (" << octalNum << ") to binary is: ";
            std::cout << binaryResult;
            std::cout << std::endl;
                
        } else if (optionNumber == 8) {
            return;
        } else {
            std::cout << "Invalid Choice!\n";
        }

    }

}

std::string NumberConverter::decimalToBinary(const std::string& input) {

    if (!isNonNegativeInteger(input)) {
        return "Invalid input!";
    }

    unsigned long long decimal;

    if (!parseUnsignedInteger(input, decimal)) {
        return "Number is too large!";
    }

    if (decimal == 0) {
        return "0";
    }

    std::vector<int> binary;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary.push_back(remainder);
        decimal = decimal / 2;
    }

    std::string result;

    for (int i = binary.size() - 1; i >= 0; i--) {
        result += '0' + binary[i];
    }

    return result;
}

std::string NumberConverter::binaryToDecimal(const std::string& input) {

    if (!isBinary(input)) {
        return "Invalid binary number!";
    }

    unsigned long long result = 0;
    unsigned long long maxValue =
        std::numeric_limits<unsigned long long>::max();

    for (int i = 0; i < input.size(); i++) {
        int digitValue = input[i] - '0';

        if (result > (maxValue - digitValue) / 2) {
            return "Number is too large!";
        }

        result = (result * 2) + digitValue;
    }

    return std::to_string(result);
}

std::string NumberConverter::decimalToHexadecimal(const std::string& input) {

    if (!isNonNegativeInteger(input)) {
        return "Invalid input!";
    }

    unsigned long long decimal;

    if (!parseUnsignedInteger(input, decimal)) {
        return "Number is too large!";
    }

    if (decimal == 0) {
        return "0";
    }

    std::vector<char> hexadecimal;

    while (decimal > 0) {
        int remainder = decimal % 16;
        decimal = decimal / 16;

        char character;

        if (remainder < 10) {
            character = '0' + remainder;
        } else {
            character = 'A' + (remainder - 10);
        }

        hexadecimal.push_back(character);
    }

    std::string result = "0x";

    for (int i = hexadecimal.size() - 1; i >= 0; i--) {
        result += hexadecimal[i];
    }

    return result;
}

std::string NumberConverter::hexadecimalToDecimal(const std::string& input) {

    // Validate hexadecimal number
    for (int i = 0; i < input.size(); i++) {
        if (!((input[i] >= '0' && input[i] <= '9') ||
              (input[i] >= 'A' && input[i] <= 'F') ||
              (input[i] >= 'a' && input[i] <= 'f'))) {
            return "Invalid hexadecimal number!";
        }
    }

    unsigned long long result = 0;
    unsigned long long maxValue =
        std::numeric_limits<unsigned long long>::max();

    for (int i = 0; i < input.size(); i++) {
        int digitValue;

        if (input[i] >= '0' && input[i] <= '9') {
            digitValue = input[i] - '0';
        } else if (input[i] == 'A' || input[i] == 'a') {
            digitValue = 10;
        } else if (input[i] == 'B' || input[i] == 'b') {
            digitValue = 11;
        } else if (input[i] == 'C' || input[i] == 'c') {
            digitValue = 12;
        } else if (input[i] == 'D' || input[i] == 'd') {
            digitValue = 13;
        } else if (input[i] == 'E' || input[i] == 'e') {
            digitValue = 14;
        } else {
            digitValue = 15;
        }

        if (result > (maxValue - digitValue) / 16) {
            return "Number is too large!";
        }

        result = (result * 16) + digitValue;
    }

    return std::to_string(result);
}

std::string NumberConverter::decimalToOctal(const std::string& input) {

    if (!isNonNegativeInteger(input)) {
        return "Invalid input!";
    }

    unsigned long long decimal;

    if (!parseUnsignedInteger(input, decimal)) {
        return "Number is too large!";
    }

    if (decimal == 0) {
        return "0";
    }

    std::vector<int> octal;

    while (decimal > 0) {
        int remainder = decimal % 8;
        octal.push_back(remainder);
        decimal = decimal / 8;
    }

    std::string result;

    for (int i = octal.size() - 1; i >= 0; i--) {
        result += '0' + octal[i];
    }

    return result;
}