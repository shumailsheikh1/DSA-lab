#include <iostream>
using namespace std;

class Employee
{
public:
    virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
public:
    double salary;

    FullTimeEmployee(double s)
    {
        salary = s;
    }

    double calculateSalary()
    {
        return salary;
    }
};

class PartTimeEmployee : public Employee
{
public:
    int hours;
    double rate;

    PartTimeEmployee(int h, double r)
    {
        hours = h;
        rate = r;
    }

    double calculateSalary()
    {
        return hours * rate;
    }
};

int main()
{
    FullTimeEmployee e1(50000);
    PartTimeEmployee e2(40, 500);

    cout << "Full Time Salary: "
        << e1.calculateSalary() << endl;

    cout << "Part Time Salary: "
        << e2.calculateSalary() << endl;

    return 0;
}