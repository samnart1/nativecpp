#include "UserInterface.h"
#include <iostream>
#include <limits>
#include <cctype>       // for isdigit
#include <string>
#include <sstream>      // for string to number conversion
#include <iomanip>      // for output formatting

UserInterface::UserInterface(Calculator* calc) : calculator(calc) {}

void UserInterface::run() {
    char choice = '\0';
    bool running = true;

    displayHelp();

    while (running) {
        displayCurrentValue();
        displayMenu();

        std::cout << "Select operation: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'q' || choice == 'Q') {
            std::cout << "Thank you for using the calculator. Goodbye!\n";
            running = false;
            continue;
        }

        try {
            processOperation(choice);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void UserInterface::displayMenu() const {
    std::cout << "\nOperations:\n";
    std::cout << " + : Add\n";
    std::cout << " - : Subtract\n";
    std::cout << " * : Multiply\n";
    std::cout << " / : Divide\n";
    std::cout << " ^ : Power\n";
    std::cout << " r : Square root\n";
    std::cout << " c : Clear calculator\n";
    std::cout << " m : Store in memory\n";
    std::cout << " R : Recall from memory\n";
    std::cout << " M : Add to memory\n";
    std::cout << " C : Clear memory\n";
    std::cout << " = : Set value\n";
    std::cout << " h : Hep\n";
    std::cout << " q : Quit\n";
}

void UserInterface::displayHelp() const {
    std::cout << "\n===== Calculator Help =====\n";
    std::cout << "This calculator performs basic arithmetic operations.\n";
    std::cout << "The current value is used as the first operand for operations.\n";
    std::cout << "Memory functions let you store and recall values.\n";
    std::cout << "\nTips:\n";
    std::cout << "- Use 'c' to clear the calculator's current value\n";
    std::cout << "- Use memory functions to store intermediate results\n";
    std::cout << "- The calculator handles floating-point numbers\n";
    std::cout << "=============================\n\n";
}

void UserInterface::displayCurrentValue() const {
    std::cout << "\nCurrent value: " << std::fixed << std::setprecision(4) << calculator->getCurrentValue() << std::endl;
}

double UserInterface::getNumberInput() const {
    std::string input;
    double number;
    bool valid = false;

    while(!valid) {
        std::cout << "Enter number: ";
        std::getline(std::cin, input);

        if (isValidNumber(input)) {
            std::stringstream(input) >> number;
            valid = true;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }

    return number;
}

bool UserInterface::isValidNumber(const std::string& input) const {
    bool hasDecimal = false;
    bool hasDigit = false;

    if (input.empty()) {
        return false;
    }

    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];

        if (i == 0 && (c == '+' || c == '-')) {
            continue;
        }

        if (c == '.') {
            if (hasDecimal) {
                return false;
            }
            hasDecimal = true;
            continue;
        }

        if (!std::isdigit(c)) {
            return false;
        }

        hasDigit = true;
    }

    return hasDigit;
}

void UserInterface::processOperation(char operation) {
    double inputNumber;

    switch (operation) {
        case '+':
            inputNumber = getNumberInput();
            calculator->add(inputNumber);
            break;

        case '-':
            inputNumber = getNumberInput();
            calculator->subtract(inputNumber);
            break;

        case '*':
            inputNumber = getNumberInput();
            calculator->multiply(inputNumber);
            break;

        case '/':
            inputNumber = getNumberInput();
            calculator->divide(inputNumber);
            break;

        case '^':
            inputNumber = getNumberInput();
            calculator->power(inputNumber);
            break;

        case 'r':
        case 'R':
            if (operation == 'r') {
                calculator->squareRoot();
            } else {
                calculator->memoryRecall();
                std::cout << "Value recalled from memory.\n";
            }
            break;

        case 'c':
            calculator->clear();
            std::cout << "Calculator cleared.\n";
            break;

        case 'm':
            calculator->memoryStore();
            std::cout << "Value stored in memory.\n";
            break;

        case 'M':
            inputNumber = getNumberInput();
            calculator->memoryAdd(inputNumber);
            std::cout << "Value added to memory.\n";
            break;

        case 'C':
            calculator->memoryClear();
            std::cout << "Memory cleared.\n";
            break;

        case '=':
            inputNumber = getNumberInput();
            calculator->setCurrentValue(inputNumber);
            break;

        case 'h':
        case 'H':
            displayHelp();
            break;

        default:
            std::cout << "Invalid operation. Press 'h' for help.\n";
    }
}