#include "department.h"

Department::Department() {
    name = "";
    manager = "";
}

std::string Department::getName() {
    return name;
}

void Department::setName(std::string newName) {
    name = newName;
}

std::string Department::getManager() {
    return manager;
}

void Department::setManager(std::string newManager) {
    manager = newManager;
}
