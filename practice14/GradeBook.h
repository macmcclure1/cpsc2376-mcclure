#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include <functional>

class GradeBook {
    int grade;
    std::vector<std::function<void(int)>> observers;
public:
    void setGrade(int g) {
        grade = g;
        for (auto& obs : observers) {
            obs(grade);
        }
    }
    void subscribe(std::function<void(int)> observer) {
        observers.push_back(observer);
    }
};

#endif
