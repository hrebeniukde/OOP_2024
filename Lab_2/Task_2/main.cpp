#include <iostream>
#include <vector>

#include "polynom.h"

Polynom sumPolynoms(const std::vector<Polynom> &polynoms) {
    if (polynoms.empty()) {
        return Polynom(0, {});
    }

    Polynom sum = polynoms[0];
    for (int index = 1; index < (int)polynoms.size(); index++) {
        sum = sum.add(polynoms[index]);
    }

    return sum;
}

int main()
{
    std::cout << "========== Initialising polynomials ==========" << std::endl;
    std::vector<Uninom> members1 = { {2, 0}, {-3, 1}, {5, 2}, {4, 3} };
    Polynom polynom1(3, members1);
    std::cout << "Polynomial 1: ";
    polynom1.printPolynom();

    std::vector<Uninom> members2 = { {5, 0}, {7, 1}, {-6, 2} };
    Polynom polynom2(2, members2);
    std::cout << "Polynomial 2: ";
    polynom2.printPolynom();

    std::vector<Uninom> members3 = { {5, 0}, {2, 1} };
    Polynom polynom3(1, members3);
    std::cout << "Polynomial 3: ";
    polynom3.printPolynom();

    std::cout << "========== Result of adding polynomials ==========" << std::endl;
    Polynom newPolynom = polynom1.add(polynom2);
    newPolynom.printPolynom();

    std::cout << "========== Result of subtracting polynomials ==========" << std::endl;
    newPolynom = polynom1.subtract(polynom2);
    newPolynom.printPolynom();

    std::cout << "========== Result of multiplying polynomials ==========" << std::endl;
    newPolynom = polynom1.multiply(polynom2);
    newPolynom.printPolynom();

    std::cout << "========== Result of adding polynomials of an array ==========" << std::endl;
    std::vector<Polynom> polynoms = { polynom1, polynom2, polynom3 };
    Polynom result = sumPolynoms(polynoms);
    result.printPolynom();

    return 0;
}
