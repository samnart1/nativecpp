#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include <string>

using namespace std;

enum class TemperatureUnit {
    CELSIUS,
    FAHRENHEIT
};

class TempConverter {
private:
    static const double FREEZING_CELSIUS;
    static const double BOILING_CELSIUS;
    static const double FREEZING_FAHRENHEIT;
    static const double BOILING_FAHRENHEIT;

    void displayWelcome();
    void displayMenu();
    int getMenuChoice();
    double getTemperatureInput(const string& unit);
    void displayResult(double inputTemp, double convertedTemp, TemperatureUnit fromUnit, TemperatureUnit toUnit);
    void displayTemperatureContext(double celsius);
    string getUnitSymbol(TemperatureUnit unit);
    string getUnitName(TemperatureUnit unit);
    bool isValidTemperature(double temp, TemperatureUnit unit);

public:
    TempConverter();

    double celsiusToFahrenheit(double celsius);
    double fahrenheitToCelsius(double fahrenheit);

    void runConverter();
    bool askToContinue();

    void displayConversionTable(double start, double end, double step, TemperatureUnit unit);

};

#endif