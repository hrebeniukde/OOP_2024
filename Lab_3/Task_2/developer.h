#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <string>

#include "employee.h"

class Developer : public Employee
{
public:
    Developer();

    std::string getProgrammingLanguage();
    void setProgrammingLanguage(std::string newLanguage);

private:
    std::string programmingLanguage;
};

#endif // DEVELOPER_H
