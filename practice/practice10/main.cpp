// File: main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>



class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};


class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};


class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
                  << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            iss >> width >> height;
            auto rectangle = std::make_unique<Rectangle>(width, height);
            shapes.push_back(std::move(rectangle));
        } else if (shapeType == "circle") {
            double radius;
            iss >> radius;
            auto circle = std::make_unique<Circle>(radius);
            shapes.push_back(std::move(circle));
        } else {
            std::cerr << "Unknown shape type: " << shapeType << std::endl;
        }
    }

    printAllAreas(shapes);

    return 0;
}
