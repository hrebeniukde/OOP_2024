#include "employee.h"

#include <iostream>

int main()
{
    Employee alex;
    alex.setId(1);
    alex.setName("Alex");
    alex.setSalary(10000000);

    std::cout << "Id: " << alex.getId() << std::endl;
    std::cout << "Name: " << alex.getName() << std::endl;
    std::cout << "Salary: " << alex.getSalary() << std::endl;

    return 0;
}
