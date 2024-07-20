#include <iostream>

using namespace std;

// Function to convert and display temperatures
void convertAndDisplay(double temperature, char originalUnit) {
    double celsius, fahrenheit, kelvin;

    // Convert to Celsius for calculation
    switch (originalUnit) {
        case 'F':
            celsius = (temperature - 32) * 5 / 9;
            break;
        case 'K':
            celsius = temperature - 273.15;
            break;
        default:
            celsius = temperature;
    }

    // Convert to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    // Convert to Kelvin
    kelvin = celsius + 273.15;

    // Display results
    cout << "Converted Temperatures:" << endl;
    cout << "Celsius: " << celsius << endl;
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "Kelvin: " << kelvin << endl;
}

int main() {
    double temperature;
    char originalUnit;

    // Prompt user for input
    cout << "Enter temperature value: ";
    cin >> temperature;

    // Prompt user for the original unit of measurement
    cout << "Enter original unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> originalUnit;

    // Convert temperature and display results
    convertAndDisplay(temperature, originalUnit);

    return 0;
}
