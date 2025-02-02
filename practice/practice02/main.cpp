#include <iostream>
#include <fstream>
#include <iomanip>

const std::string FILE_NAME = "account_balance.txt";

// Function prototypes
double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);

int main() {
    std::cout << "Welcome to Your Bank Account!" << std::endl;
    
    double balance = readBalanceFromFile();
    
    int choice;
    do {
        std::cout << "\nMenu:\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: checkBalance(balance); break;
            case 2: deposit(balance); break;
            case 3: withdraw(balance); break;
            case 4: std::cout << "Exiting..." << std::endl; break;
            default: std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
    
    return 0;
}

// Reads the balance from file or initializes it if file is missing
double readBalanceFromFile() {
    std::ifstream inFile(FILE_NAME);
    double balance;
    
    if (!inFile) {
        std::cout << "Initializing account with $100.00..." << std::endl;
        balance = 100.00;
        writeBalanceToFile(balance);
    } else {
        inFile >> balance;
        if (inFile.fail()) {
            std::cerr << "Error reading balance. Resetting to $100.00..." << std::endl;
            balance = 100.00;
            writeBalanceToFile(balance);
        }
    }
    inFile.close();
    return balance;
}

// Writes the balance to file
void writeBalanceToFile(double balance) {
    std::ofstream outFile(FILE_NAME);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    outFile << std::fixed << std::setprecision(2) << balance;
    outFile.close();
}

// Displays the balance
void checkBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

// Handles deposit operation
void deposit(double &balance) {
    double amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;
    
    if (amount <= 0) {
        std::cerr << "Error: Deposit amount must be positive." << std::endl;
        return;
    }
    
    balance += amount;
    writeBalanceToFile(balance);
    std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

// Handles withdrawal operation
void withdraw(double &balance) {
    double amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;
    
    if (amount <= 0) {
        std::cerr << "Error: Withdrawal amount must be positive." << std::endl;
        return;
    }
    
    if (amount > balance) {
        std::cerr << "Error: Insufficient funds. Your balance is $" << std::fixed << std::setprecision(2) << balance << std::endl;
        return;
    }
    
    balance -= amount;
    writeBalanceToFile(balance);
    std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}
