#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    double currentValue;
    double memoryValue;

public:
    Calculator();

    double add(double num);
    double subtract(double num);
    double multiply(double num);
    double divide(double num);

    double power(double exponent);

    double squareRoot();

    void memoryClear();
    void memoryStore();
    void memoryRecall();
    void memoryAdd(double num);

    double getCurrentValue() const;
    void setCurrentValue(double value);

    void clear();
};

#endif