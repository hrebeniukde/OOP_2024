#include "employee.h"

void setName(Employee &object, std::string newName) {
    object.name = newName;
}

std::string getName(Employee &object) {
    return object.name;
}

void setId(Employee &object, int newId) {
    object.id = newId;
}

int getId(Employee &object) {
    return object.id;
}

void setSalary(Employee &object, int newSalary) {
    object.salary = newSalary;
}

int getSalary(Employee &object) {
    return object.salary;
}
