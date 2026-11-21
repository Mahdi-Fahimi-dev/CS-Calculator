# CS-Calculator
A C++ calculator designed for computer science students, with both a terminal version and a browser-based web version.

## Live Demo

**Try the web version here:**
https://mahdi-fahimi-dev.github.io/CS-Calculator/

## Features

### Basic Calculator

**Supports:**
    - Addition
    - Subtraction
    - Multiplication
    - Division
    - Modulo

Includes input validation and division/modulo-by-zero handling.

### Number System Converter

**Supports:**
    - Decimal to Binary
    - Binary to Decimal
    - Decimal to Hexadecimal
    - Hexadecimal to Decimal
    - Decimal to Octal
    - Binary to Octal
    - Octal to Binary

The converter includes validation for invalid numbers and values that exceed the supported range.

### Bitwise Calculator

**Supports:**
    - AND
    - OR
    - XOR
    - NOT
    - Left Shift
    - Logical Right Shift
    - Arithmetic Right Shift

**NOTE:** Left shift uses unbounded-width binary values. Bits are not discarded when they move beyond a fixed width such as 8-bit or 32-bit. The result grows as needed.

### 2's Complement

Finds the 2's complement of a binary number.

**NOTE:** The bit width entered by the user is preserved. For example, '0001' is treated as a 4-bit value and becomes '1111', while '00000001' is treated as an 8-bit value and becomes '11111111'.

## Web Version

CS Calculator is also available as a browser-based application.
The calculator's core functionality is written in C++ and compiled to WebAssembly using Emscripten. The web interface uses HTML, CSS, and JavaScript to interact with the C++ calculator logic.
The web interface was developed with assistance from AI for guidance while learning HTML, CSS, JavaScript, WebAssembly, and web development concepts. The calculator's core functionality and original implementation were developed in C++.

## Technologies Used

    - C++
    - HTML
    - CSS
    - JavaScript
    - WebAssembly
    - Emscripten
    - Git and GitHub
    - GitHub Pages

## Running the Terminal Version

**Clone the repository:**

    git clone https://github.com/Mahdi-Fahimi-dev/CS-Calculator.git

**Go into the project folder:**

    cd CS-Calculator

**Compile:**

    g++ main.cpp BasicCalculator.cpp NumberConverter.cpp BitwiseCalculator.cpp TwosComplement.cpp InputValidator.cpp BinaryHelper.cpp -o calculator

**Run on Windows:**

    .\calculator.exe

## Project Purpose

I created this project to help computer science students with number system conversions and bitwise operations, while also practicing C++ programming and object-oriented programming.
The project was later expanded into a web application to make it easily accessible to everyone while learning how C++ code can be reused in a browser through WebAssembly.