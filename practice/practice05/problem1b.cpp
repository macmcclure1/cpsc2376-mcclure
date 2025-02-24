#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type -1 to stop): ";
    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
    }

    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
