#ifndef JOBPOSITION_H
#define JOBPOSITION_H

#include <string>

class JobPosition
{
public:
    JobPosition();

    std::string getTitle();
    void setTitle(std::string newTitle);

    double getSalary();
    void setSalary(double newSalary);

private:
    std::string title;
    double salary;
};

#endif // JOBPOSITION_H
