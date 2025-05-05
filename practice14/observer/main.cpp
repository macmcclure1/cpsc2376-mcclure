#include "GradeBook.h"
#include <iostream>

class Averager {
    int total = 0;
    int count = 0;
public:
    void update(int grade) {
        total += grade;
        ++count;
        std::cout << "Average: " << (total / count) << "\n";
    }
};

class Notifier {
public:
    void update(int grade) {
        if (grade < 60) {
            std::cout << "Email sent to student@example.com\n";
        }
    }
};

int main() {
    GradeBook gb;
    Averager avg;
    Notifier notif;

    gb.subscribe([&](int g) { avg.update(g); });
    gb.subscribe([&](int g) { notif.update(g); });

    int grade;
    while (true) {
        std::cout << "Enter grade (or -1 to quit): ";
        std::cin >> grade;
        if (grade == -1) break;
        gb.setGrade(grade);
    }
    return 0;
}
