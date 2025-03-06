#include "fraction.h"
#include "mixedfraction.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nOptions:\n"
              << "1. Enter a fraction manually\n"
              << "2. Add a fraction\n"
              << "3. Subtract a fraction\n"
              << "4. Multiply by a fraction\n"
              << "5. Divide by a fraction\n"
              << "6. Display as Mixed Fraction\n"
              << "7. Clear Fraction\n"
              << "8. Exit\n";
}

Fraction getFractionFromUser() {
    int num, den;
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> den;
    return Fraction(num, den);
}

int main() {
    Fraction currentFraction; // Start with 0/1

    while (true) {
        std::cout << "\nCurrent Fraction: " << currentFraction << "\n";
        displayMenu();
        
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 8) break;

        try {
            switch (choice) {
                case 1:
                    currentFraction = getFractionFromUser();
                    break;
                case 2:
                    currentFraction = currentFraction + getFractionFromUser();
                    break;
                case 3:
                    currentFraction = currentFraction - getFractionFromUser();
                    break;
                case 4:
                    currentFraction = currentFraction * getFractionFromUser();
                    break;
                case 5:
                    currentFraction = currentFraction / getFractionFromUser();
                    break;
                case 6:
                    std::cout << "Mixed Fraction: " << MixedFraction(currentFraction) << "\n";
                    break;
                case 7:
                    currentFraction = Fraction();
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
