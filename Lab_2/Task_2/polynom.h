#ifndef POLYNOM_H
#define POLYNOM_H

#include <string>
#include <vector>

struct Uninom {
    int coefficient;
    int degree;
};

class Polynom
{
public:
    Polynom(int degree, const std::vector<Uninom> &members);

    void printPolynom();

    Polynom add(const Polynom &other);

    Polynom subtract(const Polynom &other);

    Polynom multiply(const Polynom &other);

private:
    int degree;

    std::vector<Uninom> members;

    Polynom calculate(const Polynom &other, std::string calcOperator);
};

#endif // POLYNOM_H
