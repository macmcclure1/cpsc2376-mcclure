#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    std::vector<int> numbers;
    int num, threshold;

    std::cout << "Enter integers (type -1 to stop): ";
    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
    }

    std::cout << "Enter threshold value: ";
    std::cin >> threshold;

    
    int count = std::count_if(numbers.begin(), numbers.end(), [threshold](int x) {
        return x > threshold;
    });
    std::cout << "Count of elements greater than " << threshold << ": " << count << std::endl;

    
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [threshold](int x) {
        return x < threshold;
    }), numbers.end());

    std::cout << "Filtered list (elements >= " << threshold << "): ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
