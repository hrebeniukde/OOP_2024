#include "warehouse.h"

#include <algorithm>
#include <iostream>

void Warehouse::addPart(const Part &part) {
    parts.push_back(part);
}

void Warehouse::removePartByName(const std::string &name) {
    parts.erase(std::remove_if(parts.begin(), parts.end(), [&name](const Part& p) {
        return p.getName() == name;
    }), parts.end());
}

void Warehouse::updatePart(const std::string &name, double newPrice, int newQuantity) {
    for (auto& part : parts) {
        if (part.getName() == name) {
            part.setPrice(newPrice);
            part.setQuantity(newQuantity);
            break;
        }
    }
}

void Warehouse::printParts() const {
    for (const auto& part : parts) {
        part.print();
    }
}

void Warehouse::findPartByName(const std::string &name) const {
    for (const auto& part : parts) {
        if (part.getName() == name) {
            part.print();
            return;
        }
    }
    std::cout << "Запчастину не знайдено." << std::endl;
}

void Warehouse::sortPartsByPrice() {
    std::sort(parts.begin(), parts.end(), [](const Part& a, const Part& b) {
        return a.getPrice() < b.getPrice();
    });
}
