#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

class Department
{
public:
    Department();

    std::string getName();
    void setName(std::string newName);

    std::string getManager();
    void setManager(std::string newManager);

private:
    std::string name;
    std::string manager;

};

#endif // DEPARTMENT_H
