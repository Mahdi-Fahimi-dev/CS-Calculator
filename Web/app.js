/* Basic Calculator */
const basicButton = document.getElementById("basic-button");
const basicCalculator = document.getElementById("basic-calculator");
const backButton = document.getElementById("back-button");

const firstNumberInput = document.getElementById("first-number");
const operatorInput = document.getElementById("operator");
const secondNumberInput = document.getElementById("second-number");
const calculateButton = document.getElementById("calculate-button");
const basicResult = document.getElementById("result");

/* Number System Converter */
const converterButton = document.getElementById("converter-button");
const converter = document.getElementById("converter");
const converterBackButton = document.getElementById("converter-back-button");

const conversionType = document.getElementById("conversion-type");
const conversionInput = document.getElementById("conversion-input");

const convertButton = document.getElementById("convert-button");
const conversionResult = document.getElementById("conversion-result");

/* Bitwise Calculator */
const bitwiseButton = document.getElementById("bitwise-button");
const bitwiseCalculator = document.getElementById("bitwise-calculator");
const bitwiseBackButton = document.getElementById("bitwise-back-button");

const bitwiseOperation = document.getElementById("bitwise-operation");
const bitwiseSecondInput = document.getElementById("bitwise-second-input");

const bitwiseFirstInput = document.getElementById("bitwise-first-input");

const bitwiseCalculateButton = document.getElementById("bitwise-calculate-button");
const bitwiseResult = document.getElementById("bitwise-result");

/* Two's Complement */
const twosButton = document.getElementById("twos-button");
const twosComplement = document.getElementById("twos-complement");
const twosBackButton = document.getElementById("twos-back-button");

const twosInput = document.getElementById("twos-input");
const twosCalculateButton = document.getElementById("twos-calculate-button");
const twosResult = document.getElementById("twos-result");


/* Basic Calculator */
basicButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    basicCalculator.hidden = false;
});

backButton.addEventListener("click", function () {
    basicCalculator.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

/* Number System Converter */
converterButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    converter.hidden = false;
});

converterBackButton.addEventListener("click", function () {
    converter.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

conversionType.addEventListener("change", function () {
    if (
        conversionType.value === "decimal-binary" ||
        conversionType.value === "decimal-hex" ||
        conversionType.value === "decimal-octal"
    ) {
        conversionInput.placeholder = "Enter decimal number";

    } else if (
        conversionType.value === "binary-decimal" ||
        conversionType.value === "binary-octal"
    ) {
        conversionInput.placeholder = "Enter binary number";

    } else if (conversionType.value === "hex-decimal") {
        conversionInput.placeholder = "Enter hexadecimal number";

    } else if (conversionType.value === "octal-binary") {
        conversionInput.placeholder = "Enter octal number";
    }
});

convertButton.addEventListener("click", function () {
    if (conversionType.value === "decimal-binary") {
        conversionResult.value =
            Module.convertDecimalToBinary(conversionInput.value.trim());
    } else if (conversionType.value === "binary-decimal") {
        conversionResult.value =
            Module.convertBinaryToDecimal(conversionInput.value.trim());
    } else if (conversionType.value === "decimal-hex") {
        conversionResult.value =
            Module.convertDecimalToHexadecimal(conversionInput.value.trim());
    } else if (conversionType.value === "hex-decimal") {
        conversionResult.value =
            Module.convertHexadecimalToDecimal(conversionInput.value.trim());
    } else if (conversionType.value === "decimal-octal") {
        conversionResult.value =
            Module.convertDecimalToOctal(conversionInput.value.trim());
    }  else if (conversionType.value === "binary-octal") {
        conversionResult.value =
            Module.convertBinaryToOctal(conversionInput.value.trim());
    } else if (conversionType.value === "octal-binary") {
        conversionResult.value =
            Module.convertOctalToBinary(conversionInput.value.trim());
    }
});

/* Bitwise Calculator */
bitwiseButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    bitwiseCalculator.hidden = false;
});

bitwiseBackButton.addEventListener("click", function () {
    bitwiseCalculator.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

bitwiseOperation.addEventListener("change", function () {
    if (bitwiseOperation.value === "not") {
        bitwiseFirstInput.placeholder = "Enter binary number";
        bitwiseSecondInput.hidden = true;

    } else if (
        bitwiseOperation.value === "left-shift" ||
        bitwiseOperation.value === "logical-right-shift" ||
        bitwiseOperation.value === "arithmetic-right-shift"
    ) {
        bitwiseFirstInput.placeholder = "Enter binary number";
        bitwiseSecondInput.hidden = false;
        bitwiseSecondInput.placeholder = "Enter shift amount";

    } else {
        bitwiseFirstInput.placeholder = "Enter first binary number";
        bitwiseSecondInput.hidden = false;
        bitwiseSecondInput.placeholder = "Enter second binary number";
    }
});

bitwiseCalculateButton.addEventListener("click", function () {
    const operation = bitwiseOperation.value;
    const firstInput = bitwiseFirstInput.value.trim();
    const secondInput = bitwiseSecondInput.value.trim();

    /* AND Operation */
    if (operation === "and") {
        bitwiseResult.value = Module.bitwiseAnd(firstInput, secondInput);
    }

    /* OR Operation */
    else if (operation === "or") {
        bitwiseResult.value = Module.bitwiseOr(firstInput, secondInput);
    }

    /* XOR Operation */
    else if (operation === "xor") {
        bitwiseResult.value = Module.bitwiseXor(firstInput, secondInput);
    } 
    
    /* NOT Operation */
    else if (operation === "not") {
        bitwiseResult.value = Module.bitwiseNot(firstInput);
    }

    /* Left Shift Operation */
    else if (operation === "left-shift") {
        bitwiseResult.value = Module.bitwiseLeftShift(firstInput, secondInput);
    }

    /* Logical Right Shift Operation */
    else if (operation === "logical-right-shift") {
        bitwiseResult.value = Module.bitwiseLogicalRightShift(firstInput, secondInput);
    }

    /* Arithmetic Right Shift Operation */
    else if (operation === "arithmetic-right-shift") {
        bitwiseResult.value = Module.bitwiseArithmeticRightShift(firstInput, secondInput);}
});

/* Two's Complement */
twosButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    twosComplement.hidden = false;
});

twosBackButton.addEventListener("click", function () {
    twosComplement.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

calculateButton.addEventListener("click", function () {
    const firstNumber = firstNumberInput.value.trim();
    const secondNumber = secondNumberInput.value.trim();

    if (firstNumber === "" || secondNumber === "") {
        basicResult.value = "Please enter both numbers.";
        return;
    }

    const first = Number(firstNumber);
    const second = Number(secondNumber);

    if (Number.isNaN(first) || Number.isNaN(second)) {
        basicResult.value = "Invalid input!";
        return;
    }

    basicResult.value =
        Module.calculateBasic(first, operatorInput.value, second);
});

twosCalculateButton.addEventListener("click", function () {
    const input = twosInput.value.trim();

    twosResult.value = Module.calculateTwosComplement(input);
});