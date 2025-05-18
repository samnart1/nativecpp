#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "Calculator.h"
#include <string>

class UserInterface {
private:
    Calculator* calculator;

    void displayMenu() const;
    void displayHelp() const;
    void displayCurrentValue() const;
    void processOperation(char operation);
    double getNumberInput() const;

    bool isValidNumber(const std::string& input) const;

public:
    UserInterface(Calculator* calc);

    void run();
};

#endif