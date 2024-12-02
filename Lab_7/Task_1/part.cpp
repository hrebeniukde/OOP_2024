#include "part.h"

#include <iostream>

std::string Part::getName() const {
    return name;
}

double Part::getPrice() const {
    return price;
}

void Part::setPrice(double newPrice) {
    price = newPrice;
}

void Part::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Part::print() const {
    std::cout << "Назва: " << name << ", Виробник: " << manufacturer
              << ", Ціна: " << price << ", Кількість: " << quantity << std::endl;
}
