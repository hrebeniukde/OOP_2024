#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>

#include "part.h"

class Warehouse {
private:
    std::vector<Part> parts;

public:
    void addPart(const Part& part);

    void removePartByName(const std::string& name);

    void updatePart(const std::string& name, double newPrice, int newQuantity);

    void printParts() const;

    void findPartByName(const std::string& name) const;

    void sortPartsByPrice();

};

#endif // WAREHOUSE_H
