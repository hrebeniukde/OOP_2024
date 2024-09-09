#include "employee.h"

Employee::Employee() {
    name = "";
    id = -1;
    salary = -1;
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
