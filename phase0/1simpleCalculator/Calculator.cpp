#include "Calculator.h"
#include <cmath>
#include <stdexcept>

Calculator::Calculator() : currentValue(0.0), memoryValue(0.0) {}

double Calculator::add(double num) {
    currentValue += num;
    return currentValue;
}

double Calculator::subtract(double num) {
    currentValue -= num;
    return currentValue;
}

double Calculator::multiply(double num) {
    currentValue *= num;
    return currentValue;
}

double Calculator::divide(double num) {
    if (num == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    currentValue /= num;
    return currentValue;
}

double Calculator::power(double exponent) {
    currentValue = std::pow(currentValue, exponent);
    return currentValue;
}