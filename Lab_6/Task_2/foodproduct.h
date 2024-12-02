#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "product.h"

#include <iostream>

class FoodProduct : public Product {
    std::string expirationDate;

public:
    FoodProduct(const std::string& name_, double price_, int quantity_, const std::string& expirationDate_)
        : Product(name_, price_, quantity_), expirationDate(expirationDate_) {}

    void display() const override {
        std::cout << "Назва: " << name << " (Продукти харчування)"
                  << ", Ціна: " << price << ", Кількість: " << quantity
                  << ", Термін придатності: " << expirationDate << std::endl;
    }
};

#endif // FOODPRODUCT_H
