#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>

class Employee {
    protected:
        std::string name;
        int id;
    public:
        Employee(std::string name, int id) : name(name), id(id) {}
        virtual ~Employee() {}
        virtual double calculateSalary() const = 0;
        virtual void displayInfo() const {
            std::cout << "ID: " << id << ", Name: " << name;
        }
    };

    class SalariedEmployee : public Employee {
        private:
            double monthlySalary;
        public:
            SalariedEmployee(std::string name, int id, double salary)
                : Employee(name, id), monthlySalary(salary) {}
            double calculateSalary() const override {
                return monthlySalary;
            }
            void displayInfo() const override {
                Employee::displayInfo();
                std::cout << ", Type: Salaried, Monthly Salary: $" << monthlySalary << std::endl;
            }
        };
class HourlyEmployee : public Employee {
            private:
                double hourlyRate;
                int hoursWorked;
            public:
                HourlyEmployee(std::string name, int id, double rate, int hours)
                    : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}
                double calculateSalary() const override {
                    return hourlyRate * hoursWorked;
                }
                void displayInfo() const override {
                    Employee::displayInfo();
                    std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
                              << ", Hourly Rate: $" << hourlyRate
                              << ", Salary: $" << calculateSalary() << std::endl;
                }
            };
class CommissionEmployee : public Employee {
                private:
                    double baseSalary;
                    double salesAmount;
                    double commissionRate;
                public:
                    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
                        : Employee(name, id), baseSalary(base), salesAmount(sales), commissionRate(rate) {}
                    double calculateSalary() const override {
                        return baseSalary + (salesAmount * commissionRate);
                    }
                    void displayInfo() const override {
                        Employee::displayInfo();
                        std::cout << ", Type: Commission, Base Salary: $" << baseSalary
                                  << ", Sales: $" << salesAmount
                                  << ", Commission Rate: " << (commissionRate * 100) << "%"
                                  << ", Salary: $" << calculateSalary() << std::endl;
                    }
                };
                void readEmployeesFromFile(const std::string& filename, std::vector<std::unique_ptr<Employee>>& employees) {
                    std::ifstream file(filename);
                    if (!file) {
                        std::cerr << "Error: Could not open file " << filename << std::endl;
                        return;
                    }
                    
                    std::string line;
                    while (std::getline(file, line)) {
                        std::istringstream iss(line);
                        std::string type, name;
                        int id;
                        if (!(iss >> type >> id >> name)) {
                            std::cerr << "Error: Invalid file format." << std::endl;
                            continue;
                        }
                        
                        if (type == "Salaried") {
                            double salary;
                            if (iss >> salary) {
                                employees.push_back(std::make_unique<SalariedEmployee>(name, id, salary));
                            }
                        } else if (type == "Hourly") {
                            double rate;
                            int hours;
                            if (iss >> rate >> hours) {
                                employees.push_back(std::make_unique<HourlyEmployee>(name, id, rate, hours));
                            }
                        } else if (type == "Commission") {
                            double base, sales, rate;
                            if (iss >> base >> sales >> rate) {
                                employees.push_back(std::make_unique<CommissionEmployee>(name, id, base, sales, rate));
                            }
                        } else {
                            std::cerr << "Error: Unknown employee type: " << type << std::endl;
                        }
                    }
                }
                
                int main() {
                    std::vector<std::unique_ptr<Employee>> employees;
                    readEmployeesFromFile("employees.txt", employees);
                
                    std::cout << "\nEmployee Details:\n";
                    for (const auto& emp : employees) {
                        emp->displayInfo();
                    }
                    
                    return 0;
                }