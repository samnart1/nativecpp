#include <iostream>
#include "Calculator.h"
#include "UserInterface.h"

int main() {

    std::cout << "===== C++ Calculator =====\n";

    Calculator calc;
    UserInterface ui(&calc);

    ui.run();

    return 0;
}