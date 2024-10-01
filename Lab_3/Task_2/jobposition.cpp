#include "jobposition.h"

JobPosition::JobPosition() {
    title = "";
    salary = 0.0;
}

std::string JobPosition::getTitle() {
    return title;
}

void JobPosition::setTitle(std::string newTitle) {
    title = newTitle;
}

double JobPosition::getSalary() {
    return salary;
}

void JobPosition::setSalary(double newSalary) {
    salary = newSalary;
}
