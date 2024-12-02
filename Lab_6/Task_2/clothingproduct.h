#ifndef CLOTHINGPRODUCT_H
#define CLOTHINGPRODUCT_H

#include "product.h"

#include <iostream>

class ClothingProduct : public Product {
    std::string size;

public:
    ClothingProduct(const std::string& name_, double price_, int quantity_, const std::string& size_)
        : Product(name_, price_, quantity_), size(size_) {}

    void display() const override {
        std::cout << "Назва: " << name << " (Одяг)"
                  << ", Ціна: " << price << ", Кількість: " << quantity
                  << ", Розмір: " << size << std::endl;
    }
};

#endif // CLOTHINGPRODUCT_H
