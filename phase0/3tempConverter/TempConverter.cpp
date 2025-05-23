#include "TempConverter.h"
#include <iomanip>
#include <limits>
#include <iostream>

using namespace std;

const double TempConverter::FREEZING_CELSIUS = 0.0;
const double TempConverter::BOILING_CELSIUS = 100.0;
const double TempConverter::FREEZING_FAHRENHEIT = 32.0;
const double TempConverter::BOILING_FAHRENHEIT = 212.0;

TempConverter::TempConverter() {}

double TempConverter::celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double TempConverter::fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void TempConverter::displayWelcome() {
    cout << "\n     === Temperature Converter === \n";
    cout << "Convert between celsius and fahrenheit with ease!" << '\n';
    cout << "=================================================";
}

void TempConverter::displayMenu() {
    cout << "\nChoose conversion type: " << '\n';
    cout << "1. Celsius -> Fahrenheit" << '\n';
    cout << "2. Fahrenheit -> Celsius" << '\n';
    cout << "3. Show conversion table" << '\n';
    cout << "4. Exit" << '\n';
    cout << "Enter your choice (1-4)" << '\n';
}

int TempConverter::getMenuChoice() {
    int choice;
    while (true) {
        if (cin >> choice && choice >= 1 && choice <= 4) {
            return choice;
        } else {
            cout << "Enter a valid choice from 1 to 4" << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double TempConverter::getTemperatureInput(const string& unit) {
    double temp;
    while (true) {
        cout << "Enter temperature in " << unit << ": ";
        if (cin >> temp) {
            return temp;
        } else {
            cout << "Invalid input! Please enter a numeric value: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool TempConverter::isValidTemperature(double temp, TemperatureUnit unit) {
    const double ABSOLUTE_ZERO_C = -273.15;
    const double ABSOLUTE_ZERO_F = -459.67;

    if (unit == TemperatureUnit::CELSIUS) {
        return temp >= ABSOLUTE_ZERO_C;
    } else {
        return temp >= ABSOLUTE_ZERO_F;
    }
}

string TempConverter::getUnitSymbol(TemperatureUnit unit) {
    return (unit == TemperatureUnit::CELSIUS) ? "°C" : "°F";
}

string TempConverter::getUnitName(TemperatureUnit unit) {
    return (unit == TemperatureUnit::CELSIUS) ? "Celsius" : "Fahrenheit";
}

void TempConverter::displayResult(double inputTemp, double convertedTemp, TemperatureUnit fromUnit, TemperatureUnit toUnit) {
    cout << fixed << setprecision(2);
    cout << "\n Conversion Result:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << inputTemp << getUnitSymbol(fromUnit) << " = " << convertedTemp << getUnitSymbol(toUnit);

    if (toUnit == TemperatureUnit::CELSIUS) {
        displayTemperatureContext(convertedTemp);
    } else {
        displayTemperatureContext(fahrenheitToCelsius(convertedTemp));
    }
}

