#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
private:
    double salary;

public:
    FullTimeEmployee(double s) {
        salary = s;
    }

    double calculateSalary() {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hours;
    double rate;

public:
    PartTimeEmployee(double h, double r) {
        hours = h;
        rate = r;
    }

    double calculateSalary() {
        return hours * rate;
    }
};

int main() {
    FullTimeEmployee employee1(50000);
    PartTimeEmployee employee2(20, 1000);

    cout << "Full Time Salary: " << employee1.calculateSalary() << endl;
    cout << "Part Time Salary: " << employee2.calculateSalary() << endl;

    return 0;
}
