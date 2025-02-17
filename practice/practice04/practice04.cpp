#include <iostream>
#include <iomanip>
#include <list>
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
    
    // problem2a.cpp - Calculator
    template<typename T>
    T calculate(T a, T b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : throw invalid_argument("Division by zero");
            default: throw invalid_argument("Invalid operator");
        }
    }

    int main() {
        double num1, num2;
        char op;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter operation (+, -, *, /): ";
        cin >> op;

        try {
            cout << "Result: " << fixed << setprecision(2) << calculate(num1, num2, op) << "\n";
        } catch (const exception& e) {
            cout << e.what() << "\n";
        }
        return 0;
    }

    // problem3a.cpp - Task Manager
    void taskManager() {
        list<string> tasks;
        int choice;
        string task;
        
        do {
            cout << "1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Exit\nChoice: ";
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1:
                    cout << "Enter task: ";
                    getline(cin, task);
                    tasks.push_back(task);
                    cout << "Task added!\n";
                    break;
                case 2:
                    if (!tasks.empty()) {
                        cout << "Enter task number to remove: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= tasks.size()) {
                            auto it = tasks.begin();
                            advance(it, index - 1);
                            tasks.erase(it);
                            cout << "Task removed!\n";
                        } else {
                            cout << "Invalid task number!\n";
                        }
                    } else {
                        cout << "No tasks to remove!\n";
                    }
                    break;
                case 3:
                    cout << "Tasks:\n";
                    int i = 1;
                    for (const auto& t : tasks) {
                        cout << i++ << ". " << t << "\n";
                    }
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }
    
    taskManager();
    return 0;
}
