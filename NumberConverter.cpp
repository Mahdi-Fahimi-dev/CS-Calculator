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

            if (!isBinary(binary)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            unsigned long long result = 0;
            unsigned long long maxValue = std::numeric_limits<unsigned long long>::max();

            bool binaryOverflow = false;
            for (int i = 0; i < binary.size(); i++) {
                int digitValue = binary[i] - '0';

                if (result > (maxValue - digitValue) / 2) {
                    std::cout << std::endl;
                    std::cout << "Number is too large!\n";
                    binaryOverflow = true;
                    break;
                }
                result = (result * 2) + digitValue;
            }
            if (binaryOverflow) {
                continue;
            }
            std::cout << "Binary (" << binary << ") to decimal is: ";
            std::cout << result << std::endl;

        // Decimal to hexadecimal
        } else if (optionNumber == 3) {
            std::cout << std::endl;
            std::cout << "Decimal to Hexadecimal Selected\n";

            std::string nonNegativeNum1;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> nonNegativeNum1;

            if (!isNonNegativeInteger(nonNegativeNum1)) {
                std::cout << std::endl;
                std::cout << "Invalid input!\n";
                continue;
            }

            unsigned long long convertedString;
            if (!parseUnsignedInteger(nonNegativeNum1, convertedString)) {
                std::cout << std::endl;
                std::cout << "Number is too large!\n";
                continue;
            }

            unsigned long long dec = convertedString;

            std::vector <char> hexDecimal;

            if (convertedString == 0) {
            std::cout << "0\n";
            continue;
            }
            while(convertedString > 0) {
                int remainder1;
                remainder1 = convertedString % 16;
                convertedString = convertedString / 16;

                char character;
                if (remainder1 < 10) {
                    character = '0' + remainder1;
                } else {
                    character = 'A' + (remainder1 - 10);
                }

                hexDecimal.push_back(character);
            }
            std::cout << "The decimal (" << dec << ") to hexadecimal is: 0x";
            for (int i = hexDecimal.size() - 1; i >= 0; i--) {
                std::cout << hexDecimal[i];
            }
            std::cout << std::endl; 

        // Hexadecimal to decimal
        } else if (optionNumber == 4) {
            std::cout << std::endl;
            std::cout << "Hexadecimal to Decimal Selected\n";
            std::cout << "Enter a hexadecimal number: ";
            std::string hexa;
            std::cin >> hexa;

            bool validHexaToDecimal = true;

            // validation for hexadecimal number
            for (int i = 0; i < hexa.size(); i++) {
                if (!((hexa[i] >= '0' && hexa[i] <= '9') || (hexa[i] >= 'A' && hexa[i] <= 'F') || (hexa[i] >= 'a' && hexa[i] <= 'f'))) {
                    std::cout << std::endl;
                    std::cout << "Invalid hexadecimal number!\n";
                    validHexaToDecimal = false;
                    break;
                }
            }
            if (!validHexaToDecimal) {
                continue;
            }

            unsigned long long hexToDecResult = 0;
            unsigned long long maxValue = std::numeric_limits<unsigned long long>::max();

            bool hexOverflow = false;

            for (int i = 0; i < hexa.size(); i++) {
                int digitValue;
                if (hexa[i] >= '0' && hexa[i] <= '9') {
                    digitValue = hexa[i] - '0';
                } else if (hexa[i] == 'A' || hexa[i] == 'a') {
                    digitValue = 10;
                } else if (hexa[i] == 'B' || hexa[i] == 'b') {
                    digitValue = 11;
                } else if (hexa[i] == 'C' || hexa[i] == 'c') {
                    digitValue = 12;
                } else if (hexa[i] == 'D' || hexa[i] == 'd') {
                    digitValue = 13;
                } else if (hexa[i] == 'E' || hexa[i] == 'e') {
                    digitValue = 14;
                } else {
                    digitValue = 15;
                }

                if (hexToDecResult > (maxValue - digitValue) / 16) {
                    std::cout << std::endl;
                    std::cout << "Number is too large!\n";
                    hexOverflow = true;
                    break;
                }
                hexToDecResult = (hexToDecResult * 16) + digitValue;
            }
            if (hexOverflow) {
                continue;
            }
            std::cout << "Hexadecimal (" << hexa << ") to decimal is: ";
            std::cout << hexToDecResult;
            std::cout << std::endl;
        
        // Decimal to Octal
        } else if (optionNumber == 5) {
            std::cout << std::endl;
            std::cout << "Decimal to Octal Selected\n";
            std::string decNum;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> decNum;

            if (!isNonNegativeInteger(decNum)) {
                std::cout << std::endl;
                std::cout << "Invalid input!\n";
                continue;
            }

            unsigned long long decToOc;
            if (!parseUnsignedInteger(decNum, decToOc)) {
                std::cout << std::endl;
                std::cout << "Number is too large!\n";
                continue;
            }

            if (decToOc == 0) {
                std::cout << "0\n";
                continue;
            }

            std::vector<int> octal;

            while (decToOc > 0) {
                int remainderResult;
                remainderResult = decToOc % 8;
                octal.push_back(remainderResult);
                decToOc = decToOc / 8;
            }

            for (int i = octal.size() -1 ; i >= 0; i--) {
                std::cout << octal[i];
            }
            std::cout << std::endl;

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