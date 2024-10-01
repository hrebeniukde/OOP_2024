#include "employee.h"

Employee::Employee() {
    name = "";
    id = -1;
    salary = 0.0;
    department = nullptr;
}

std::string Employee::getName() {
    return name;
}

void Employee::setName(std::string newName) {
    name = newName;
}

int Employee::getId() {
    return id;
}

void Employee::setId(int newId) {
    id = newId;
}

double Employee::getSalary() {
    return salary;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}

JobPosition Employee::getJobPosition() {
    return jobPosition;
}

void Employee::setJobPosition(JobPosition newJobPosition) {
    jobPosition = newJobPosition;
}

Department* Employee::getDepartment() {
    return department;
}

void Employee::setDepartment(Department* newDepartment) {
    department = newDepartment;
}
