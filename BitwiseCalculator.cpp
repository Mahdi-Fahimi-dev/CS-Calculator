#include <iostream>
#include "BitwiseCalculator.h"
#include "inputValidator.h"
#include "binaryHelper.h"

void BitwiseCalculator::run() {
    while (true) {
        std::cout << std::endl;
        std::cout << "Bitwise Calculator\n";
        std::cout << "  1. AND\n";
        std::cout << "  2. OR\n";
        std::cout << "  3. XOR\n";
        std::cout << "  4. NOT\n";
        std::cout << "  5. Left Shift\n";
        std::cout << "  6. Logical Right Shift\n";
        std::cout << "  7. Arithmetic Right Shift\n";
        std::cout << "  8. Back\n";
        std::cout << std::endl;

        std::string menuOption;
        std::cout << "Enter your choice: ";
        std::cin >> menuOption;

        // Input Validation
        if (menuOption.size() != 1 || menuOption[0] < '1' || menuOption[0] > '8') {
            std::cout << std::endl;
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int selectOption = menuOption[0] - '0';
        
        // AND Operation
        if (selectOption == 1) {
            std::cout << std::endl;
            std::cout << "AND Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string firstBinary;
            std::cin >> firstBinary;

            // checks if the number is 0 or 1
            if (!isBinary(firstBinary)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }
            

            std::cout << "Enter second binary number: ";
            std::string secondBinary;
            std::cin >> secondBinary;

            // checks if the number is 0 or 1
            if (!isBinary(secondBinary)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string result = bitwiseAnd(firstBinary, secondBinary);

            if (result == "Invalid binary number!") {
                std::cout << result << std::endl;
                continue;
            }

            padBinaryStrings(firstBinary, secondBinary);

            std::cout << std::endl;
            std::cout << "      " << firstBinary << std::endl;
            std::cout << "AND" << std::endl;
            std::cout << "      " << secondBinary << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << result << std::endl;

        // OR Operation
        } else if (selectOption == 2) {
            std::cout << std::endl;
            std::cout << "OR Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string binaryNum1;
            std::cin >> binaryNum1;

            // checks if the number is 0 or 1
            if (!isBinary(binaryNum1)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::cout << "Enter second binary number: ";
            std::string binaryNum2;
            std::cin >> binaryNum2;

            // checks if the number is 0 or 1
            if (!isBinary(binaryNum2)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string result = bitwiseOr(binaryNum1, binaryNum2);

            padBinaryStrings(binaryNum1, binaryNum2);

            std::cout << std::endl;
            std::cout << "      " << binaryNum1 << std::endl;
            std::cout << "OR" << std::endl;
            std::cout << "      " << binaryNum2 << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << result << std::endl;
        
        // XOR Operation
        } else if (selectOption == 3) {
            std::cout << std::endl;
            std::cout << "XOR Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string binaryOne;      // first binary number for XOR operation
            std::cin >> binaryOne;

            // checks if the number is 0 or 1
            if (!isBinary(binaryOne)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::cout << "Enter second binary number: ";
            std::string binaryTwo;      // Second binary number for XOR operation
            std::cin >> binaryTwo;

            // checks if the number is 0 or 1
            if (!isBinary(binaryTwo)) {
                std::cout << std::endl;
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string result = bitwiseXor(binaryOne, binaryTwo);

            padBinaryStrings(binaryOne, binaryTwo);

            // Prints the result
            std::cout << std::endl;
            std::cout << "      " << binaryOne << std::endl;
            std::cout << "XOR" << std::endl;
            std::cout << "      " << binaryTwo << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << result << std::endl;

        // NOT Operation
        } else if (selectOption == 4) {
            std::cout << std::endl;
            std::cout << "NOT Operation Selected\n";
            std::cout << "Enter a binary number: ";
            
            std::string number;
            std::cin >> number;

            // checks if the number is 0 or 1
            if (!isBinary(number)) {
                std::cout << "Invalid binary number!\n";
                continue;
            }
            
            std::string notResult = invertBinary(number);

            // Prints the result
            std::cout << std::endl;
            std::cout << "NOT(" << number << ") -> " << notResult;
            std::cout << std::endl;

        // Shift Left Operation
        } else if (selectOption == 5) {
            std::cout << std::endl;
            std::cout << "Left Shift Selected\n";
            std::cout << "Enter a binary number: ";

            std::string binaryNumber;       // binary number to be shifted
            std::cin >> binaryNumber;

            // checks if the number is 0 or 1
            if (!isBinary(binaryNumber)) {
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string shiftInput;
            std::cout << "Enter shift amount: ";
            std::cin >> shiftInput;

            if (!isNonNegativeInteger(shiftInput)) {
                std::cout << "Invalid input!\n";
                continue;
            }

            unsigned long long shiftAmount;
            if (!parseShiftAmount(shiftInput, shiftAmount)) {
                std::cout << "Shift amount is too large! Maximum is 1024.\n";
                continue;
            }

            // prints the original input if the shift amount is 0
            if (shiftAmount == 0) {
                std::cout << std::endl;
                std::cout << binaryNumber << ", left shift (" << shiftAmount << ") -> " << binaryNumber << std::endl;
                continue;
            }

            // add zeros to the end of the shift result based on the shift amount
            std::string shiftResult = binaryNumber;
            for (unsigned long long i = 0; i < shiftAmount; i++) {
                shiftResult = shiftResult + '0';
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << binaryNumber << ", left shift (" << shiftAmount << ") -> " << shiftResult << std::endl;

        // Logical Right Shift 
        } else if (selectOption == 6) {
            std::cout << std::endl;
            std::cout << "Logical Right Shift Selected\n";
            std::cout << "Enter a binary number: ";

            std::string biNum;      // binary number to be shifted
            std::cin >> biNum;

            // checks if the number is 0 or 1
            if (!isBinary(biNum)) {
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string rightShiftInput;
            std::cout << "Enter shift amount: ";
            std::cin >> rightShiftInput;

            // validate if every character is between '0' and '9'
            if (!isNonNegativeInteger(rightShiftInput)) {
                std::cout << "Invalid input!\n";
                continue;
            }

            unsigned long long shiftAmount;
            if (!parseShiftAmount(rightShiftInput, shiftAmount)) {
                std::cout << "Shift amount is too large! Maximum is 1024.\n";
                continue;
            }

            // prints the original input if the shift amount is 0
            if (shiftAmount == 0) {
                std::cout << std::endl;
                std::cout << biNum << ", logical right shift (" << shiftAmount << ") -> " << biNum << std::endl;
                continue;
            }

            // Preserves the original bit width
            std::string resultOfShift = biNum;
            if (shiftAmount >= biNum.size()) {
                resultOfShift = std::string(biNum.size(), '0');
            } else {
                resultOfShift = std::string(biNum.size(), '0');
                for (unsigned long long i = shiftAmount; i < biNum.size(); i++) {
                    resultOfShift[i] = biNum[i - shiftAmount];
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << biNum << ", logical right shift (" << shiftAmount << ") -> " << resultOfShift << std::endl;

        // Arithmetic right shift operation
        } else if (selectOption == 7) {
            std::cout << std::endl;
            std::cout << "Arithmetic Right Shift Selected\n";
            std::cout << "Enter a binary number: ";

            std::string arithInput;         // binary number to be shifted
            std::cin >> arithInput;

            // checks if the number is 0 or 1
            if (!isBinary(arithInput)) {
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string rightArithShiftInput;
            std::cout << "Enter shift amount: ";
            std::cin >> rightArithShiftInput;

            // validate if every character is between '0' and '9'
            if (!isNonNegativeInteger(rightArithShiftInput)) {
                std::cout << "Invalid input!\n";
                continue;
            }

            unsigned long long shiftAmount;
            if (!parseShiftAmount(rightArithShiftInput, shiftAmount)) {
                std::cout << "Shift amount is too large! Maximum is 1024.\n";
                continue;
            }

            // prints the original input if the shift amount is 0
            if (shiftAmount == 0) {
                std::cout << std::endl;
                std::cout << arithInput << ", arithmetic right shift (" << shiftAmount << ") -> " << arithInput << std::endl;
                continue;
            }

            char signBit = arithInput[0];
            
            // Preserves the original bit width
            std::string arithResult;
            if (shiftAmount >= arithInput.size()) {
                arithResult = std::string(arithInput.size(), signBit);
            } else {
                arithResult = std::string(arithInput.size(), signBit);
                for (unsigned long long i = shiftAmount; i < arithInput.size(); i++) {
                    arithResult[i] = arithInput[i - shiftAmount];
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << arithInput << ", arithmetic right shift (" << shiftAmount << ") -> " << arithResult << std::endl;

        } else if (selectOption == 8) {
            return;
        } else {
            std::cout << "Invalid Choice!\n";
        }
    }
} 

// AND 
std::string BitwiseCalculator::bitwiseAnd(const std::string& first, const std::string& second) {

    if (!isBinary(first) || !isBinary(second)) {
        return "Invalid binary number!";
    }

    std::string firstBinary = first;
    std::string secondBinary = second;

    padBinaryStrings(firstBinary, secondBinary);

    std::string result;

    for (int i = 0; i < firstBinary.size(); i++) {
        if (firstBinary[i] == '1' && secondBinary[i] == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }

    return result;
}

// OR
std::string BitwiseCalculator::bitwiseOr(const std::string& first, const std::string& second) {

    if (!isBinary(first) || !isBinary(second)) {
        return "Invalid binary number!";
    }

    std::string firstBinary = first;
    std::string secondBinary = second;

    padBinaryStrings(firstBinary, secondBinary);

    std::string result;

    for (int i = 0; i < firstBinary.size(); i++) {
        if (firstBinary[i] == '1' || secondBinary[i] == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }

    return result;
}

// XOR
std::string BitwiseCalculator::bitwiseXor(const std::string& first, const std::string& second) {

    if (!isBinary(first) || !isBinary(second)) {
        return "Invalid binary number!";
    }

    std::string firstBinary = first;
    std::string secondBinary = second;

    padBinaryStrings(firstBinary, secondBinary);

    std::string result;

    for (int i = 0; i < firstBinary.size(); i++) {
        if (firstBinary[i] != secondBinary[i]) {
            result += '1';
        } else {
            result += '0';
        }
    }

    return result;
}