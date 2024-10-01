#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager
{
public:
    Manager(std::string name);

    std::string getName() const;
    void setName(const std::string &newName);

private:
    std::string name;
};

#endif // MANAGER_H
