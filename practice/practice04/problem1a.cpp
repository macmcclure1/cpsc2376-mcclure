#include <iostream>
#include <iomanip>
using namespace std;

double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {
        return (temp * 9.0 / 5.0) + 32.0;  // Celsius to Fahrenheit
    } else {
        return (temp - 32.0) * 5.0 / 9.0;  // Fahrenheit to Celsius
    }
}

int main() {
    int choice;
    double temp;
    cout << "1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\nChoose an option: ";
    cin >> choice;
    cout << "Enter temperature: ";
    cin >> temp;
    
    if (choice == 1)
        cout << "Converted: " << fixed << setprecision(2) << convertTemperature(temp, 'F') << "\u00B0F\n";
    else
        cout << "Converted: " << fixed << setprecision(2) << convertTemperature(temp, 'C') << "\u00B0C\n";
    
    return 0;
}
