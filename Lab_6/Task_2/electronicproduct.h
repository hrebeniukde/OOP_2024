#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H

#include "product.h"

#include <iostream>

class ElectronicProduct : public Product {
    int warrantyPeriod;

public:
    ElectronicProduct(const std::string& name_, double price_, int quantity_, int warrantyPeriod_)
        : Product(name_, price_, quantity_), warrantyPeriod(warrantyPeriod_) {}

    void display() const override {
        std::cout << "Назва: " << name << " (Електроніка)"
                  << ", Ціна: " << price << ", Кількість: " << quantity
                  << ", Гарантійний період: " << warrantyPeriod << " місяців" << std::endl;
    }
};

#endif // ELECTRONICPRODUCT_H
