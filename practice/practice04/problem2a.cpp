#include <iostream>
#include <iomanip>
using namespace std;

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