static int sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) { // Bug: Off-by-one error
        sum += i;
    }
    return sum;
}
for (int i = start; i <= end; i++) { // Fixed: Include end value
static bool containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i <= numbers.size(); i++) { // Bug
        if (numbers[i] > 0) { // Bug
            return true;
        }
    }
    return false;
}
for (size_t i = 0; i < numbers.size(); i++) { // Fixed: Prevent out-of-bounds
    if (numbers[i] < 0) { // Fixed: Proper negative check
        return true;
    }
}
static int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return 0; // Bug
    int maxVal = numbers[0];
    for (size_t i = 1; i <= numbers.size(); i++) { // Bug
        if (numbers[i] >= maxVal) { // Bug
            maxVal = numbers[i];
        }
    }
    return maxVal;
}
if (numbers.empty()) throw std::invalid_argument("Empty vector"); // Fixed
for (size_t i = 1; i < numbers.size(); i++) { // Fixed: Prevent out-of-bounds
    if (numbers[i] > maxVal) { // Fixed: Proper comparison
        maxVal = numbers[i];
    }
}
