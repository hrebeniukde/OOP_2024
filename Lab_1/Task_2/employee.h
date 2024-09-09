#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

struct Employee {
    std::string name = "";
    int id = -1;
    int salary = -1;
};

void setName(Employee &object, std::string newName);
std::string getName(Employee &object);

void setId(Employee &object, int newId);
int getId(Employee &object);

void setSalary(Employee &object, int newSalary);
int getSalary(Employee &object);

#endif // EMPLOYEE_H
