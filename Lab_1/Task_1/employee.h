#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee();

    std::string getName();
    void setName(std::string newName);

    int getId();
    void setId(int newId);

    int getSalary();
    void setSalary(int newSalary);

private:
    std::string name;

    int id;

    int salary;
};

#endif // EMPLOYEE_H
