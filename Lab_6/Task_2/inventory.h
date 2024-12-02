#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Inventory {
    std::vector<T> products;

public:
    void addProduct(const T& product) {
        products.push_back(product);
    }

    void removeProductByName(const std::string& name) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if ((*it)->getName() == name) {
                products.erase(it);
                std::cout << "Товар \"" << name << "\" було видалено з інвентаря.\n";
                return;
            }
        }
        std::cout << "Товар з назвою \"" << name << "\" не знайдено.\n";
    }

    void displayAllProducts() const {
        for (const auto& product : products) {
            product->display();
        }
    }

    void findProductsByPrice(double price) const {
        bool found = false;
        for (const auto& product : products) {
            if (product->getPrice() == price) {
                product->display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Товари з ціною " << price << " не знайдено.\n";
        }
    }
};

#endif // INVENTORY_H
