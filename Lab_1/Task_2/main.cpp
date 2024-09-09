#include <iostream>

#include "employee.h"

int main()
{
    Employee bob;
    setId(bob, 2);
    setName(bob, "Bob");
    setSalary(bob, 99999);

    std::cout << "Id: " << getId(bob) << std::endl;
    std::cout << "Name: " << getName(bob) << std::endl;
    std::cout << "Salary: " << getSalary(bob) << std::endl;

    return 0;
}
