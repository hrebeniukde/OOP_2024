#include <iostream>

#include "employee.h"

void printEmployeeData(Employee &employee)
{
    std::cout << "Id: " << employee.getId() << std::endl;
    std::cout << "Name: " << employee.getName() << std::endl;
    std::cout << "Salary: " << employee.getSalary() << std::endl;
}

int main()
{
    std::cout << "========== Default constructor ==========" << std::endl;
    Employee emptyEmployee;
    printEmployeeData(emptyEmployee);

    std::cout << "========== Constructor with parameters ==========" << std::endl;
    Employee bob("Bob", 1, 10000000);
    printEmployeeData(bob);

    std::cout << "========== Constructor with parameters ==========" << std::endl;
    Employee copiedEmployee(emptyEmployee);
    printEmployeeData(copiedEmployee);

    std::cout << std::endl;

    return 0;
}
