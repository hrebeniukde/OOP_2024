#include "manager.h"

Manager::Manager(std::string name) {
    this->name = name;
}

std::string Manager::getName() const
{
    return name;
}

void Manager::setName(const std::string &newName)
{
    name = newName;
}
