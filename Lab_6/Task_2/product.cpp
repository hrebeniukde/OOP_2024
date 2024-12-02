#include "product.h"

#include <iostream>

std::string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

int Product::getQuantity() const { return quantity; }

void Product::display() const {
    std::cout << "Назва: " << name << ", Ціна: " << price << ", Кількість: " << quantity << std::endl;
}
