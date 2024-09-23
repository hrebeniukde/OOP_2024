#include "polynom.h"

#include <iostream>

Polynom::Polynom(int degree, const std::vector<Uninom> &members) {
    this->degree = degree;
    this->members = members;
}

void Polynom::printPolynom()
{
    for (int index = 0; index < (int)this->members.size(); index++) {
        Uninom member = this->members.at(index);

        if (member.coefficient > 0 && index > 0)
            std::cout << "+";

        std::cout << member.coefficient;

        if (member.degree > 0)
            std::cout << "x^" << member.degree;
    }

    std::cout << std::endl;
}

Polynom Polynom::add(const Polynom &other) {
    return calculate(other, "+");
}

Polynom Polynom::subtract(const Polynom &other)
{
    return calculate(other, "-");
}

Polynom Polynom::multiply(const Polynom &other)
{
    std::vector<Uninom> newPolynomMembers;

    int firstPolynomSize = this->members.size();
    int secondPolynomSize = other.members.size();

    for (int firstIndex = 0; firstIndex < firstPolynomSize; firstIndex++) {
        Uninom firstMember = this->members.at(firstIndex);
        for (int secondIndex = 0; secondIndex < secondPolynomSize; secondIndex++) {
            Uninom secondMember = other.members.at(secondIndex);

            Uninom result = {firstMember.coefficient * secondMember.coefficient, firstMember.degree + secondMember.degree};
            newPolynomMembers.push_back(result);
        }
    }

    return Polynom(this->degree + other.degree, newPolynomMembers);
}

Polynom Polynom::calculate(const Polynom &other, std::string calcOperator)
{
    std::vector<Uninom> newPolynomMembers;

    int firstPolynomSize = this->members.size();
    int secondPolynomSize = other.members.size();

    int highestPolynomDegree = (other.degree > this->degree) ? other.degree : this->degree;
    for (int index = 0; index < highestPolynomDegree + 1; index++) {
        int firstMember = 0,
            secondMember = 0,
            result = 0;

        if (index < firstPolynomSize)
            firstMember = this->members.at(index).coefficient;

        if (index < secondPolynomSize)
            secondMember = other.members.at(index).coefficient;

        if (calcOperator == "+")
            result = firstMember + secondMember;
        else if (calcOperator == "-")
            result = firstMember - secondMember;

        newPolynomMembers.push_back({result, index});
    }

    return Polynom(highestPolynomDegree, newPolynomMembers);
}
