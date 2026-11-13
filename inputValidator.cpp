#include "inputValidator.h"
#include <stdexcept>

// if the character is not '0' or '1' then it returns false.
// It returns true if the loop does not find any invalid character
bool isBinary(const std::string& input) {
    if (input.empty()) {
        return false;
    }

    for (int i = 0; i < input.size(); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}

bool isNonNegativeInteger(const std::string& input) {
    if (input.empty()) {
        return false;
    }

    for (int i = 0; i < input.size(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
    }
    return true;
}

bool parseUnsignedInteger(const std::string& input, unsigned long long& value) {
    if (!isNonNegativeInteger(input)) {
        return false;
    }

    try {
        value = std::stoull(input);
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
    catch (const std::out_of_range& e) {
        return false;
    }

    return true;
}