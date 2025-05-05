#include "TextProcessor.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"
#include "CensorFilter.h"
#include <iostream>

int main() {
    TextProcessor processor;
    std::string input;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    while (true) {
        std::cout << "\nChoose a filter:\n";
        std::cout << "1. Reverse\n2. Uppercase\n3. Remove vowels\n4. Censor bad words\n5. Exit\n> ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) processor.setStrategy(std::make_unique<ReverseFilter>());
        else if (choice == 2) processor.setStrategy(std::make_unique<UppercaseFilter>());
        else if (choice == 3) processor.setStrategy(std::make_unique<RemoveVowelsFilter>());
        else if (choice == 4) processor.setStrategy(std::make_unique<CensorFilter>());
        else break;

        std::cout << "\nProcessed: " << processor.process(input) << "\n";
    }
    return 0;
}