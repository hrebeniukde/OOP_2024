#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "jobposition.h"
#include "department.h"

class Employee
{
public:
    Employee();

    std::string getName();
    void setName(std::string newName);

    int getId();
    void setId(int newId);

    double getSalary();
    void setSalary(double newSalary);

    JobPosition getJobPosition();
    void setJobPosition(JobPosition newJobPosition);

    Department* getDepartment();
    void setDepartment(Department* newDepartment);

private:
    std::string name;
    int id;
    double salary;
    JobPosition jobPosition;
    Department* department;

};

#endif // EMPLOYEE_H
