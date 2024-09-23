#include <iostream>

#include "employee.h"

Employee::Employee() {
    name = "None";
    id = -1;
    salary = 0;
}

Employee::Employee(std::string name, int id, int salary)
{
    this->name = name;
    this->id = id;
    this->salary = salary;
}

Employee::Employee(const Employee &employee)
{
    this->name = employee.name;
    this->id = employee.id;
    this->salary = employee.salary;
}

Employee::~Employee()
{
    std::cout << "Employee object has been destroyed." << std::endl;
}

std::string Employee::getName()
{
    return name;
}

void Employee::setName(std::string newName)
{
    name = newName;
}

int Employee::getId()
{
    return id;
}

void Employee::setId(int newId)
{
    id = newId;
}

int Employee::getSalary()
{
    return salary;
}

void Employee::setSalary(int newSalary)
{
    salary = newSalary;
}
