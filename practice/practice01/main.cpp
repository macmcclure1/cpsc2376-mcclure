#include <iostream>
#include <vector>
#include <numeric> 


void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main() {
    std::vector<int> numbers; 
    int choice = 0;

    do {
        
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of the vector\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter a number to add to the vector: ";
                std::cin >> value;
                numbers.push_back(value);
                break;
            }
            case 2:
                printVector(numbers);
                break;
            case 3:
                doubleVector(numbers);
                break;
            case 4: {
                int sum = calculateSum(numbers);
                std::cout << "Sum of the vector: " << sum << std::endl;
                break;
            }
            case 5: {
                int multiple;
                std::cout << "Enter a value to find multiples of: ";
                std::cin >> multiple;
                printMultiples(numbers, multiple);
                break;
            }
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}


void printVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
        return;
    }

    std::cout << "Vector elements: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


void doubleVector(std::vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
    std::cout << "The vector has been doubled.\n";
}


int calculateSum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

 
void printMultiples(const std::vector<int>& vec, int multiple) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
        return;
    }

    std::cout << "Multiples of " << multiple << ": ";
    bool found = false;
    for (int num : vec) {
        if (num % multiple == 0) {
            std::cout << num << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "None";
    }
    std::cout << std::endl;
}
