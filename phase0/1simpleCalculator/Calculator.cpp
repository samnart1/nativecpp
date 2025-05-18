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

double Calculator::squareRoot() {
    if (currentValue < 0.0) {
        throw std::domain_error("Cannot calculate square root of a negative number");
    }
    currentValue = std::sqrt(currentValue);
    return currentValue;
}

void Calculator::memoryClear() {
    memoryValue == 0.0;
}

void Calculator::memoryStore() {
    memoryValue == currentValue;
}

void Calculator::memoryRecall() {
    currentValue = memoryValue;
}

void Calculator::memoryAdd(double num) {
    memoryValue += num;
}

double Calculator::getCurrentValue() const {
    return currentValue;
}

void Calculator::setCurrentValue(double value) {
    currentValue = value;
}

void Calculator::clear() {
    currentValue = 0.0;
}